#pragma once
#include "Hexagon.h"
#include "Macros.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include "Controller.h"
#include "Controller.h"


class ToolFrame
{
private:
	Hexagon m_redHex;
	Hexagon m_blueHex;
	Hexagon m_grayHex;
	Hexagon m_greenHex;
	Hexagon m_yellowHex;
	Hexagon m_magnetaHex;


	sf::Text m_playerPercentage;
	sf::Text m_computerPercentage;

	sf::Font font;

	Button m_newButtom;

public:
	ToolFrame();
	~ToolFrame() {};
	void drawFrame(sf::RenderWindow* window);
	HexColor checkIfColorClicked(const sf::Event::MouseButtonEvent& event, sf::RenderWindow* window);
	void setPlayerPercentage(float new_percentage);
	void setComputerPercentage(float new_percentage);
	const Button& getNewButton() const;
};