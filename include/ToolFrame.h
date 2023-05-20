#pragma once
#include "Hexagon.h"
#include "Macros.h"
#include "Button.h"
#include <SFML/Graphics.hpp>


class ToolFrame
{
private:
	Hexagon m_redHex;
	Hexagon m_blueHex;
	Hexagon m_grayHex;
	Hexagon m_greenHex;
	Hexagon m_yellowHex;
	Hexagon m_magnetaHex;


	float m_playerPercentage;
	float m_computerPercentage;


	Button m_newButtom;

public:
	ToolFrame();
	~ToolFrame() {};
	void drawFrame(sf::RenderWindow* window);
	HexColor checkIfColorClicked(const sf::Event::MouseButtonEvent& event, sf::RenderWindow* window);

};