#include "Board.h"

Board::Board()
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

            // SHOULD ADD A CONDITION TO KNOW IF THE HEX IS ON EDGE:


            // Set the color randomly:
            HexColor randomColor = static_cast<HexColor>(std::rand() % static_cast<int>(HexColor::Magneta) + 1);
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
    ////initiate the players occupied hexagons:
    //m_playerOccupiedHexagons.resize(m_rowsNum, std::vector<Hexagon>(m_colsNum));

    ////make sure to set them as Invalid Color:
    //for (int row = 0; row < m_rowsNum; row++)
    //{
    //    for (int col = 0; col < m_colsNum; col++)
    //    {
    //        m_playerOccupiedHexagons[row][col] = m_board[row][col];
    //        m_playerOccupiedHexagons[row][col].setColor(HexColor::Invalid);
    //    }
    //}
}

void Board::drawBoard(sf::RenderWindow* window)
{
    for (int row = 0; row < m_rowsNum; row++) 
    {
        for (int col = 0; col < m_colsNum; col++)
        {
            // Draw the hexagons from m_board vector
            window->draw(m_board[row][col].getShape());

            //    // Draw the hexagons from m_playerOccupiedHexagons vector
            //    if (m_board[row][col].occupiedStatus()) 
            //        window->draw(m_[row][col].getShape());
            //
        }
    }
}

int Board::movePlayer(HexColor desiredColor)
{
    if (desiredColor == HexColor::Invalid)
        return -1;

    std::queue<std::pair<int, int>> queue;

    // Start from the bottom-left hexagon
    int startRow = m_rowsNum - 1;
    int startCol = 0;
    //so we can travel on the neighbors on modular way:
    int dx[] = { -1, -1, 0, 0, 1, 1 };
    int dy[] = { 0, 1, -1, 1, -1, 0 };

    
    // Update the starting hexagon and enqueue it for BFS
    m_board[startRow][startCol].setColor(desiredColor);
    m_board[startRow][startCol].setOccupiedStatus(true);
    queue.push({ startRow, startCol });

    // Perform BFS to update the connected hexagons with the desired color
    while (!queue.empty())
    {
        int row = queue.front().first;
        int col = queue.front().second;
        queue.pop();

        // Check and update the neighboring hexagons with the desired color
        for (int i = 0; i < 6; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];

            // Check if the neighboring hexagon is within bounds
            if (newRow >= 0 && newRow < m_rowsNum && newCol >= 0 && newCol < m_colsNum)
            {
                //if the neigbor is already occupied then color 
                if (m_board[newRow][newCol].occupiedStatus() == true)
                {
                    m_board[newRow][newCol].setColor(desiredColor);
                    queue.push({ newRow, newCol });
                }


                if (m_board[newRow][newCol].getColor() == desiredColor)
                {
                    m_board[newRow][newCol].setOccupiedStatus(true);
                    queue.push({ newRow, newCol });
                }

            }
        }
    }

    // Calculate the percentage of player-occupied hexagons
    /*int occupiedHexagons = 0;
    for (int row = 0; row < m_rowsNum; row++)
    {
        for (int col = 0; col < m_colsNum; col++)
        {
            if (m_board[row][col].occupiedStatus())
            {
                occupiedHexagons++;
            }
        }
    }

    int totalHexagons = m_rowsNum * m_colsNum;
    m_playerPercentage = (static_cast<double>(occupiedHexagons) / totalHexagons) * 100;*/

    return 0;
}
