
#include "StartMenu.h"

StartMenu::StartMenu()
{
	m_window = new sf::RenderWindow(sf::VideoMode(BOARD_WIDTH, BOARD_HEIGHT), "6Colors");
	m_window->setFramerateLimit(120);
	m_font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	//setting the start button:
	m_start_button.setButtonInfo("Start Game", { 0.2 * BOARD_WIDTH , 0.12 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT,
		sf::Color::Transparent, sf::Color::Yellow, { 0.4 * BOARD_WIDTH , 0.2 * BOARD_HEIGHT }, m_font);
	//setting the help button:
	m_help_button.setButtonInfo("Help", { 0.2 * BOARD_WIDTH , 0.12 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT,
		sf::Color::Transparent, sf::Color::Yellow, { 0.4 * BOARD_WIDTH , 0.44 * BOARD_HEIGHT }, m_font);
	//setting the exit button:
	m_exit_button.setButtonInfo("Exit Game", { 0.2 * BOARD_WIDTH, 0.12 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT, 
		sf::Color::Transparent, sf::Color::Yellow, { 0.4 * BOARD_WIDTH , 0.68 * BOARD_HEIGHT }, m_font);





	//-----------------------------------------------------

	while (m_window->isOpen())
	{
		//clear window
		m_window->clear();

		//drwaings:
		//====================================
		//draw wallpaper:

		//draw buttons:
		m_window->draw(m_start_button.getbutton());
		m_window->draw(m_start_button.getext());

		m_window->draw(m_help_button.getbutton());
		m_window->draw(m_help_button.getext());

		m_window->draw(m_exit_button.getbutton());
		m_window->draw(m_exit_button.getext());



		//Display on the window:
		m_window->display();

		//catching events:
		if (auto event = sf::Event{}; m_window->waitEvent(event))
		{
			switch (event.type)
			{
				//closing window:
			case sf::Event::Closed:
				m_window->close();
				exit(EXIT_SUCCESS);
				break;
				//mouse clicked:
			case sf::Event::MouseButtonReleased:
				handleClick(event.mouseButton);
				break;
				//mouse houvering over buttons:
			case sf::Event::MouseMoved:
				handleHoverOver(m_window);
				break;
			default:
				break;
			}
		}
	}
	exit(EXIT_SUCCESS);
}
//-------------------------------------------------------------------
//This function takes event as input and handle it accordingly:
void StartMenu::handleClick(const sf::Event::MouseButtonEvent& event)
{

	//if the user pressed the start game button:
	if (m_start_button.getbutton().getGlobalBounds().contains(
		m_window->mapPixelToCoords({ event.x, event.y })))
	{
		auto controller = Controller();
		controller.run(m_window);

	}
	//if the user pressed the Help  button:
	if (m_help_button.getbutton().getGlobalBounds().contains(
		m_window->mapPixelToCoords({ event.x, event.y })))
	{
		// Create the Help window:
		HelpWindow helpWindow(m_font);
		//run the help window:
		helpWindow.help_run(m_window);
	}
	if (m_exit_button.getbutton().getGlobalBounds().contains(
		m_window->mapPixelToCoords({ event.x, event.y })))
	{
		m_window->close();
 	}

	
}
//-------------------------------------------------------------------

void StartMenu::handleHoverOver(sf::RenderWindow* window)
{
	// ======== hovering over start button: =========
	if (m_start_button.isMouseOver(*m_window))
	{
		m_start_button.setTextColor(sf::Color::Blue);
	}
	else
		m_start_button.setTextColor(sf::Color::Yellow);
	// ==============================================
	// ======== hovering over Help button: =========
	if (m_help_button.isMouseOver(*m_window))
	{
		m_help_button.setTextColor(sf::Color::Blue);
	}
	else
		m_help_button.setTextColor(sf::Color::Yellow);
	// ==============================================
	// ======== hovering over Exit button: =========
	if (m_exit_button.isMouseOver(*m_window))
	{
		m_exit_button.setTextColor(sf::Color::Red);
	}
	else
		m_exit_button.setTextColor(sf::Color::Yellow);
	// ==============================================
}