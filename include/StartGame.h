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
#include "Controller.h"


class StartGame {

private:
	sf::RenderWindow window;

	ColorBot random;
	ColorBot Medium;
	ColorBot Hard;


	//font:
	sf::Font font;

public:

	StartGame();
	void run();
	void handleClick(const sf::Event::MouseButtonEvent& event);
	~StartGame();

};