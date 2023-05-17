#pragma once

// --- includes --- 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"
#include "Macros.h"

class HelpWindow
{
public:
	HelpWindow(sf::Font& font);
	void help_run(sf::RenderWindow* window);
	bool back_click(sf::RenderWindow* window, const sf::Event::MouseButtonEvent& event);

private:

	sf::Text m_text;
	//back button:
	Button m_back_button;
};

