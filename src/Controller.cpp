#include "Controller.h"


//emptry default constructor:
Controller::Controller() 
{
    m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");

    //For the Diffuclty selection:
    // ===========================
    //setting the start button:
    m_easyBotton.setButtonInfo("Easy Mode", { 0.2 * BOARD_WIDTH , 0.12 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT,
        sf::Color::Transparent, sf::Color::Yellow, { 0.4 * BOARD_WIDTH , 0.2 * BOARD_HEIGHT }, m_font);
    //setting the help button:
    m_midumButton.setButtonInfo("Medium Mode", { 0.2 * BOARD_WIDTH , 0.12 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT,
        sf::Color::Transparent, sf::Color::Yellow, { 0.4 * BOARD_WIDTH , 0.37 * BOARD_HEIGHT }, m_font);
    //setting the exit button:
    m_hardButton.setButtonInfo("Hard Mode", { 0.2 * BOARD_WIDTH, 0.12 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT,
        sf::Color::Transparent, sf::Color::Yellow, { 0.4 * BOARD_WIDTH , 0.54 * BOARD_HEIGHT }, m_font);

    //setting the exit button:
    m_exitButton.setButtonInfo("Exit Mode", { 0.2 * BOARD_WIDTH, 0.12 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT,
        sf::Color::Transparent, sf::Color::Yellow, { 0.4 * BOARD_WIDTH , 0.8 * BOARD_HEIGHT }, m_font);
}


void Controller::run(sf::RenderWindow* window)
{
    bool diffcultySelected = false;
    //presenting the diffuclty screen:
    while (window->isOpen() && !diffcultySelected)
    {
        window->clear();

        // Draw level buttons
        m_easyBotton.drawTo(*window);
        m_midumButton.drawTo(*window);
        m_hardButton.drawTo(*window);
        m_exitButton.drawTo(*window);

        //Display:
        window->display();

        
        if (auto event = sf::Event{}; window->pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;

            case sf::Event::MouseButtonReleased:
                diffcultySelected = handleClick(event.mouseButton, window);
                break;
                //mouse houvering over buttons:
            case sf::Event::MouseMoved:
                handleHoverOver(window);
                break;
            }
        }
    }

    //We took the diffculty now we build the board:
    auto board = Board();
    auto toolframe = ToolFrame();

    while (window->isOpen())
    {
        window->clear();
        board.drawBoard(window);
        toolframe.drawFrame(window);
        window->display();



        if (auto event = sf::Event{}; window->waitEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window->close();
                break;
            case sf::Event::MouseButtonReleased: // check which color the player clicked:
                auto pressedColor = toolframe.checkIfColorClicked(event.mouseButton, window);
                board.movePlayer(pressedColor);
                //board.handleComputer(m_diffculty);
                break;
            }
        }
    }
}
//-------------------------------------------------------------------
//This function takes event as input and handle it accordingly:
bool Controller::handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow* window)
{

	//if the user pressed the easy button:
	if (m_easyBotton.getbutton().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
        m_diffculty = Difficulty::Easy;
        return true;

	}
	//if the user pressed the  mid button:
	if (m_midumButton.getbutton().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
        m_diffculty = Difficulty::Medium;
        return true;
	}
	//if the user pressed the hard button:
	if (m_hardButton.getbutton().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
        m_diffculty = Difficulty::Hard;
        return true;
	}
    //if the user pressed the exit button:
    if (m_exitButton.getbutton().getGlobalBounds().contains(
        window->mapPixelToCoords({ event.x, event.y })))
    {
        window->close();
        return false;
    }

}

void Controller::handleHoverOver(sf::RenderWindow* window)
{
    // ======== hovering over easy button: =========
    if (m_easyBotton.isMouseOver(*window))
    {
        m_easyBotton.setTextColor(sf::Color::Blue);
    }
    else
        m_easyBotton.setTextColor(sf::Color::Yellow);
    // ==============================================
    // ======== hovering over medium button: =========
    if (m_midumButton.isMouseOver(*window))
    {
        m_midumButton.setTextColor(sf::Color::Blue);
    }
    else
        m_midumButton.setTextColor(sf::Color::Yellow);
    // ==============================================
    // ======== hovering over hard button: =========
    if (m_hardButton.isMouseOver(*window))
    {
        m_hardButton.setTextColor(sf::Color::Red);
    }
    else
        m_hardButton.setTextColor(sf::Color::Yellow);
    // ==============================================
    // ======== hovering over Exit button: =========
    if (m_exitButton.isMouseOver(*window))
    {
        m_exitButton.setTextColor(sf::Color::Red);
    }
    else
        m_exitButton.setTextColor(sf::Color::Yellow);
    // ==============================================
}