//progma once prevent us from including
//multiple times:
#pragma once
// --- includes --- 
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Button.h"
#include "Controller.h"
#include "HelpWindow.h"
#include <fstream>
#include <iostream>

class StartMenu
{
public:
	//constructor:
	StartMenu();


private:
	//our menu's window:
	sf::RenderWindow* m_window;

	//menu items:
	sf::Texture wallPaper;
	//menu spirits
	sf::Sprite wallPaperSprite;

	//buttons:
	Button m_start_button;
	Button m_help_button;
	Button m_exit_button;

	
	//font:
	sf::Font m_font;


	//Help Functions:
	// ====================================
	//function to handle mouse clicks:
	void handleClick(const sf::Event::MouseButtonEvent& event);
	/*void handleMouseOver(Button which_button);*/
};