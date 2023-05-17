#include "HelpWindow.h"



//constructor:
HelpWindow::HelpWindow(sf::Font& font)
{
	m_text.setString("Your Oponent is the Computer,\neach one of you start from opposite corners\nof the gameboard, which is covered by randomly\ncolored tiles. The aim is to expand across the\nboard tiles to your domain. The one who gets\nmore than 50% of the gameboard area wins.");
	m_text.setFillColor(sf::Color::Blue);

	// Calculate the center position of the board

    // Set the position of the background and text
	m_text.setPosition({ 0.05 * BOARD_WIDTH , 0.05 * BOARD_HEIGHT });
	//m_text.setPosition({ 0.4 * BOARD_WIDTH +0, 0.2 * BOARD_HEIGHT });

	//set the font:
	m_text.setFont(font);

	//set back button:
	m_back_button.setButtonInfo("Back", { 0.2 * BOARD_WIDTH, 0.12 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT, sf::Color::Transparent, sf::Color::Red, { 0.4 * BOARD_WIDTH,0.68 * BOARD_HEIGHT }, font);
	m_back_button.setBold();
	
}


void HelpWindow::help_run(sf::RenderWindow* window)
{
	bool condition = false;
	while (window->isOpen() && condition == false)
	{
		//clear window
		window->clear();

		//drwaings:
		//====================================
		window->draw(m_text);


		//draw button:
		window->draw(m_back_button.getbutton());
		window->draw(m_back_button.getext());

		//Display on the window:
		window->display();


		//catching events:
		if (auto event = sf::Event{}; window->waitEvent(event))
		{
			switch (event.type)
			{
				//closing window:
			case sf::Event::Closed:
				window->close();
				break;
				//mouse clicked:
			case sf::Event::MouseButtonReleased:
				condition = back_click(window, event.mouseButton);
				break;
				//mouse houvering over buttons:
			case sf::Event::MouseMoved:
				// ======== hovering over start button: =========
				if (m_back_button.isMouseOver(*window))
				{
					m_back_button.setTextColor(sf::Color::Blue);
				}
				else
					m_back_button.setTextColor(sf::Color::Red);

			}
		}
	}
}



//-------------------------------------------------------------------
//this function handles the back button click:
bool HelpWindow::back_click(sf::RenderWindow* window, const sf::Event::MouseButtonEvent& event)
{
	if (m_back_button.getbutton().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
		return true;
	}
	else
		return false;
}
//-------------------------------------------------------------------