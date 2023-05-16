#pragma once 

//includes:
#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

#include"ToolBar.h"


class Controller {

private:



public:
	Controller();
	void run(sf::RenderWindow& window , std::string level);
	~Controller();
};