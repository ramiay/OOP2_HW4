#include "Board.h"

Board::Board() : m_playerPercentage(0), m_computerPercentage(0)
{
    // We want to know the number of Hexa in the rows and the cols:
    m_rowsNum = m_drawingHeight / (RADIUS * 2);
    m_colsNum = m_drawingWidth / (RADIUS * 2);

    float colPosition = m_startWidth;
    float rowPosition = m_startHeight;

    // Initialize and position the hexagons
    for (int row = 0; row < m_rowsNum; row++)
    {
        std::vector<Hexagon> hexagonRow;
        for (int col = 0; col < m_colsNum; col++)
        {
            Hexagon hexagon;
            hexagon.setPosition({ colPosition, rowPosition });

            // Set the color randomly:
            HexColor randomColor = static_cast<HexColor>(std::rand() % static_cast<int>(HexColor::Invalid));
            hexagon.setColor(randomColor);
            hexagonRow.push_back(hexagon);
            colPosition += std::sqrt(3) * (RADIUS + 1);
        }
        m_board.push_back(hexagonRow);

        // Calculate the deviation for odd rows
        float rowDeviation = (row % 2 == 0) ? (std::sqrt(3) / 2 * (RADIUS + 1)) : 0.0f;

        // Update the positions for the next row
        colPosition = m_startWidth + rowDeviation;
        rowPosition += (3.0f / 4.0f) * ((RADIUS + 1) * 2);
    }
    createAdjacentLists();

}

void Board::drawBoard(sf::RenderWindow* window)
{
    for (int row = 0; row < m_rowsNum; row++) 
    {
        for (int col = 0; col < m_colsNum; col++)
        {
            // Draw the hexagons from m_board vector
            window->draw(m_board[row][col].getShape());
        }
    }

}

void Board::createAdjacentLists(){
    
    for (int row = 0; row < m_board.size(); row++)
    {
        for (int col = 0; col < m_board[0].size(); col++)
        {
            int offset = row % 2 == 0 ? -1 : 0;
            //so we can travel on the neighbors on modular way:
            int dx[] = { -1, 1,  0,  1, 0, 1 };
            int dy[] = { 0, 0, -1, -1, 1, 1 };

            for (int i = 0; i < 6; i++)
            {
                int newRow = row + dx[i];
                if (dy[i] != 0)
                    newRow += offset;
                int newCol = col + dy[i];

                // Check if the neighboring hexagon is within bounds
                if (newRow >= 0 && newRow < m_board.size() && newCol >= 0 && newCol < m_board[0].size())
                {
                    auto newHex = std::make_shared<Hexagon>(m_board[newRow][newRow]);
                    m_board[row][col].addAdjacent(newHex);

                }
            }
        }
    }
}

void Board::movePlayer(HexColor desiredColor)
{

    if (desiredColor == HexColor::Invalid)
        return;

    if (desiredColor == m_LastComColor || desiredColor == m_LastUserColor)
        return;

    m_LastUserColor = desiredColor;

    std::queue<std::pair<int, int>> queue;

    // Start from the bottom-left hexagon
    int startRow = m_rowsNum - 1;
    int startCol = 0;
    //so we can travel on the neighbors on modular way:
    int dx[] = { -1, -1, 0, 0, 1, 1 };
    int dy[] = { 0, 1, -1, 1, -1, 0 };


    // Update the starting hexagon and enqueue it for BFS
    m_board[startRow][startCol].setColor(desiredColor);
    m_board[startRow][startCol].setOccupiedByPlayerStatus(true);
    queue.push({ startRow, startCol });

    // Perform BFS to update the connected hexagons with the desired color
    while (!queue.empty())
    {
        int row = queue.front().first;
        int col = queue.front().second;
        queue.pop();

        // Check and update the neighboring hexagons with a different color
        for (int i = 0; i < 6; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            // Check if the neighboring hexagon is within bounds
            if (newRow >= 0 && newRow < m_rowsNum && newCol >= 0 && newCol < m_colsNum)
            {
                if (m_board[newRow][newCol].getColor() == desiredColor)
                {
                    if (!m_board[newRow][newCol].isOccupiedByPlayer() && !m_board[newRow][newCol].isOccupiedByComputer())
                    {
                        m_board[newRow][newCol].setOccupiedByPlayerStatus(true);
                        queue.push({ newRow, newCol });
                    }
                }
                else if (m_board[newRow][newCol].isOccupiedByPlayer()) {
                    m_board[newRow][newCol].setColor(desiredColor);
                    queue.push({ newRow, newCol });
                }
            }
        }
    }
    //calculate the player percentage:
    int totalHexagons = m_rowsNum * m_colsNum;
    int occupiedHexagons = 0;

    for (int row = 0; row < m_rowsNum; row++)
    {
        for (int col = 0; col < m_colsNum; col++)
        {
            if (m_board[row][col].isOccupiedByPlayer())
            {
                occupiedHexagons++;
            }
        }
    }

    float percentage = static_cast<float>(occupiedHexagons) / totalHexagons * 100.0f;
    m_playerPercentage = percentage;
}

void Board::moveComputer(Difficulty desired_diffuclty)
{
    HexColor desiredColor;
    std::queue<std::pair<int, int>> queue;

    // Start from the bottom-left hexagon
    int startRow = 0;
    int startCol = m_colsNum -1 ;

   
    //choose the desired color randomly: 
    if (desired_diffuclty == Difficulty::Easy)
    {
        do
        {
            desiredColor = static_cast<HexColor>(std::rand() % static_cast<int>(HexColor::Invalid));
        } while (desiredColor == m_LastUserColor || desiredColor == m_LastComColor);

        m_LastComColor = desiredColor;
    }

    //the desired color is the the color with maximum apperance in the neighbors:
    else if (desired_diffuclty == Difficulty::Medium || desired_diffuclty == Difficulty::Hard)
        desiredColor = maxNeighborColor(startCol,startRow,desired_diffuclty);

    travelOnBoard(desiredColor,startCol,startRow);



    //calculate the Computer percentage:
    int totalHexagons = m_rowsNum * m_colsNum;
    int occupiedHexagons = 0;

    for (int row = 0; row < m_rowsNum; row++)
    {
        for (int col = 0; col < m_colsNum; col++)
        {
            if (m_board[row][col].isOccupiedByComputer())
            {
                occupiedHexagons++;
            }
        }
    }

    float percentage = static_cast<float>(occupiedHexagons) / totalHexagons * 100.0f;
    m_computerPercentage = percentage;
}



float Board::getPlayerPercentage() const
{
    return m_playerPercentage;
}
float Board::getComputerPercentage() const
{
    return m_computerPercentage;
}
// WE HAVE A PROBLEM HERE.
//AFTER THE FIRST MOVE , THE COLOR WILL REMAIN THE SAME:
HexColor Board::maxNeighborColor(int in_col, int in_row, Difficulty level)
{
    int redCounter = 0;
    int blueCounter = 0;
    int grayCounter = 0;
    int greenCounter = 0;
    int yellowCounter = 0;
    int magnetaCounter = 0;

    std::queue<std::pair<int, int>> queue;
    std::vector<std::vector<bool>> visited(m_rowsNum, std::vector<bool>(m_colsNum, false));

    // Define the offsets to travel on the neighbors in a modular way
    int dx[] = { -1, -1, 0, 0, 1, 1 };
    int dy[] = { 0, 1, -1, 1, -1, 0 };

    queue.push({ in_col, in_row });
    visited[in_row][in_col] = true;

    while (!queue.empty())
    {
        int col = queue.front().first;
        int row = queue.front().second;
        queue.pop();

        // Check and update the neighboring hexagons with a different color
        for (int i = 0; i < 6; i++)
        {
            int newCol = col + dx[i];
            int newRow = row + dy[i];

            // Check if the neighboring hexagon is within bounds
            if (newRow >= 0 && newRow < m_rowsNum && newCol >= 0 && newCol < m_colsNum)
            {
                if (!visited[newRow][newCol] && !m_board[newRow][newCol].isOccupiedByComputer() && !m_board[newRow][newCol].isOccupiedByPlayer())
                {
                    switch (m_board[newRow][newCol].getColor())
                    {
                    case HexColor::Red:
                        redCounter++;
                        break;
                    case HexColor::Blue:
                        blueCounter++;
                        break;
                    case HexColor::Gray:
                        grayCounter++;
                        break;
                    case HexColor::Green:
                        greenCounter++;
                        break;
                    case HexColor::Yellow:
                        yellowCounter++;
                        break;
                    case HexColor::Magneta:
                        magnetaCounter++;
                        break;
                    }

                    if (level == Difficulty::Medium)
                    {
                        // Stop BFS when an unoccupied hexagon is encountered
                        break;
                    }
                }
            }
        }
    }

    // Store the counters in a vector of pairs
    std::vector<std::pair<int, HexColor>> counters = {
        { redCounter, HexColor::Red },
        { blueCounter, HexColor::Blue },
        { grayCounter, HexColor::Gray },
        { greenCounter, HexColor::Green },
        { yellowCounter, HexColor::Yellow },
        { magnetaCounter, HexColor::Magneta }
    };

    // Sort the counters in descending order based on the counter value
    std::sort(counters.rbegin(), counters.rend());

    // Check if there is a tie between the highest counters
    if (counters[0].first == counters[1].first)
    {
        // There is a tie, return random color
        HexColor randomColor = static_cast<HexColor>(std::rand() % static_cast<int>(HexColor::Invalid));
        return randomColor;
    }


    if (counters[0].second == m_LastComColor || counters[0].second == m_LastUserColor)
    {
        // Find a random color that is not equal to counters[0].second
        HexColor desiredColor;
        do {
            desiredColor = static_cast<HexColor>(std::rand() % static_cast<int>(HexColor::Invalid));
        } while (desiredColor == counters[0].second);

        m_LastComColor = desiredColor;
        return desiredColor;
    }
    else
    {
        m_LastComColor = counters[0].second;
        // Return the color with the highest counter
        return counters[0].second;
    }
}

void Board::travelOnBoard(HexColor desiredColor, int startCol, int startRow)
{
    //so we can travel on the neighbors on modular way:
    int dx[] = { -1, -1, 0, 0, 1, 1 };
    int dy[] = { 0, 1, -1, 1, -1, 0 };

    std::queue<std::pair<int, int>> queue;
    // Update the starting hexagon and enqueue it for BFS
    m_board[startRow][startCol].setColor(desiredColor);
    m_board[startRow][startCol].setOccupiedByComputerStatus(true);
    queue.push({ startRow, startCol });

    // Perform BFS to update the connected hexagons with the desired color
    while (!queue.empty())
    {
        int row = queue.front().first;
        int col = queue.front().second;
        queue.pop();

        // Check and update the neighboring hexagons with a different color
        for (int i = 0; i < 6; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            // Check if the neighboring hexagon is within bounds
            if (newRow >= 0 && newRow < m_rowsNum && newCol >= 0 && newCol < m_colsNum)
            {
                if (m_board[newRow][newCol].getColor() == desiredColor)
                {
                    if (!m_board[newRow][newCol].isOccupiedByComputer() && !m_board[newRow][newCol].isOccupiedByPlayer())
                    {
                        m_board[newRow][newCol].setOccupiedByComputerStatus(true);
                        queue.push({ newRow, newCol });
                    }
                }
                else if (m_board[newRow][newCol].isOccupiedByComputer())
                {
                    m_board[newRow][newCol].setColor(desiredColor);
                    queue.push({ newRow, newCol });
                }
            }
        }
    }
}




//THIS WAS IN MOVE COMPUTER EASY MODE:




//
//        // Update the starting hexagon and enqueue it for BFS
//m_board[startRow][startCol].setColor(desiredColor);
//m_board[startRow][startCol].setOccupiedByComputerStatus(true);
//queue.push({ startRow, startCol });
//
//// Perform BFS to update the connected hexagons with the desired color
//while (!queue.empty())
//{
//    int row = queue.front().first;
//    int col = queue.front().second;
//    queue.pop();
//
//    // Check and update the neighboring hexagons with a different color
//    for (int i = 0; i < 6; i++)
//    {
//        int newRow = row + dx[i];
//        int newCol = col + dy[i];
//
//        // Check if the neighboring hexagon is within bounds
//        if (newRow >= 0 && newRow < m_rowsNum && newCol >= 0 && newCol < m_colsNum)
//        {
//            if (m_board[newRow][newCol].getColor() == desiredColor)
//            {
//                if (!m_board[newRow][newCol].isOccupiedByComputer() && !m_board[newRow][newCol].isOccupiedByPlayer())
//                {
//                    m_board[newRow][newCol].setOccupiedByComputerStatus(true);
//                    queue.push({ newRow, newCol });
//                }
//            }
//            else if (m_board[newRow][newCol].isOccupiedByComputer())
//            {
//                m_board[newRow][newCol].setColor(desiredColor);
//                queue.push({ newRow, newCol });
//            }
//        }
//    }
//}

//
//void Board::createAdjacentLists() 
//{
//
//    for (int row = 0; row < m_board.size(); row++)
//    {
//        for (int col = 0; col < m_board[0].size(); col++)
//        {
//            int offset = row % 2 == 0 ? -1 : 0;
//            //so we can travel on the neighbors on modular way:
//            int dx[] = { -1, 1,  0,  1, 0, 1 };
//            int dy[] = { 0, 0, -1, -1, 1, 1 };
//
//            for (int i = 0; i < 6; i++)
//            {
//                int newRow = row + dx[i];
//                if (dy[i] != 0)
//                    newRow += offset;
//                int newCol = col + dy[i];
//
//                // Check if the neighboring hexagon is within bounds
//                if (newRow >= 0 && newRow < m_board.size() && newCol >= 0 && newCol < m_board[0].size())
//                {
//                    auto newHex = std::make_shared<Hexagon>(m_board[newRow][newRow]);
//                    m_board[row][col].addAdjacent(newHex);
//
//                }
//            }
//        }
//    }
//}
