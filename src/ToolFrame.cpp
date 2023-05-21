#include "ToolFrame.h"


ToolFrame::ToolFrame()
{
	//set the position of the hexagons:
	m_redHex.setPosition({ 0.2 * BOARD_WIDTH,0.9 * BOARD_HEIGHT }),
		m_redHex.setColor(HexColor::Red),
		m_redHex.setRadius(2 * RADIUS);

	m_blueHex.setPosition({ 0.3 * BOARD_WIDTH, 0.9 * BOARD_HEIGHT }),
		m_blueHex.setColor(HexColor::Blue),
		m_blueHex.setRadius(2 * RADIUS);

	m_grayHex.setPosition({ 0.4 * BOARD_WIDTH, 0.9 * BOARD_HEIGHT }),
		m_grayHex.setColor(HexColor::Gray),
		m_grayHex.setRadius(2 * RADIUS);

	m_greenHex.setPosition({ 0.5 * BOARD_WIDTH, 0.9 * BOARD_HEIGHT }),
		m_greenHex.setColor(HexColor::Green),
		m_greenHex.setRadius(2 * RADIUS);

	m_yellowHex.setPosition({ 0.6 * BOARD_WIDTH, 0.9 * BOARD_HEIGHT }),
		m_yellowHex.setColor(HexColor::Yellow),
		m_yellowHex.setRadius(2 * RADIUS);

	m_magnetaHex.setPosition({ 0.7 * BOARD_WIDTH, 0.9 * BOARD_HEIGHT }),
		m_magnetaHex.setColor(HexColor::Magneta),
		m_magnetaHex.setRadius(2 * RADIUS);

	//Percentages of user:
	font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
	m_playerPercentage.setString(std::to_string(0));
	m_playerPercentage.setFont(font);
	m_playerPercentage.setCharacterSize(16);
	m_playerPercentage.setPosition({ 0.05 * BOARD_WIDTH, 0.92 * BOARD_HEIGHT });

	//Percentages of computer
	m_computerPercentage.setString(std::to_string(0));
	m_computerPercentage.setFont(font);
	m_computerPercentage.setCharacterSize(16);
	m_computerPercentage.setPosition({ 0.85 * BOARD_WIDTH, 0.92 * BOARD_HEIGHT });
	//Turn:

	m_newButtom.setButtonInfo("New Game", { 0.15 * BOARD_WIDTH , 0.1 * BOARD_HEIGHT }, 0.05 * BOARD_HEIGHT,
		sf::Color::Transparent, sf::Color::Red, { 0.8 * BOARD_WIDTH , 0 * BOARD_HEIGHT }, font);
}



void ToolFrame::drawFrame(sf::RenderWindow* window)
{
	window->draw(m_redHex.getShape());
	window->draw(m_blueHex.getShape());
	window->draw(m_grayHex.getShape());
	window->draw(m_greenHex.getShape());
	window->draw(m_yellowHex.getShape());
	window->draw(m_magnetaHex.getShape());
	window->draw(m_computerPercentage);
	window->draw(m_playerPercentage);
	m_newButtom.drawTo(*window);

}


//Function that gets the mouse clicking location,
//and returns which colors was picked, if none returns Invalid:
HexColor ToolFrame::checkIfColorClicked(const sf::Event::MouseButtonEvent& event, sf::RenderWindow* window)
{
	if (m_redHex.getShape().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
		return HexColor::Red;

	}
	if (m_blueHex.getShape().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
		return HexColor::Blue;
	}
	if (m_grayHex.getShape().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
		return HexColor::Gray;
	}
	if (m_greenHex.getShape().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
		return HexColor::Green;
	}

	if (m_yellowHex.getShape().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
		return HexColor::Yellow;
	}
	if (m_magnetaHex.getShape().getGlobalBounds().contains(
		window->mapPixelToCoords({ event.x, event.y })))
	{
		return HexColor::Magneta;
	}
	else
	    return HexColor::Invalid;
}


void ToolFrame::setPlayerPercentage(float new_percentage)
{
	m_playerPercentage.setString(std::to_string(new_percentage));
}
void ToolFrame::setComputerPercentage(float new_percentage)
{
	m_computerPercentage.setString(std::to_string(new_percentage));
}
const Button& ToolFrame::getNewButton() const 
{
	return m_newButtom;
}