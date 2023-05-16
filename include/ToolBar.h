#pragma once 

//includes:
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "ColorBot.h"

class ToolBar {

private:
	ColorBot m_green;
	ColorBot m_yellow;
	ColorBot m_pink;
	ColorBot m_red;
	ColorBot m_brown;
	ColorBot m_blue;


	sf::Text yourPer ;
	sf::Text computerPer ;

public:

	ToolBar();
	void draw(sf::RenderWindow& window);
	
	~ToolBar();
};