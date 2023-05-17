#pragma once

// --- includes --- 
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Button.h"
class Controller
{
private:
    enum class Difficulty
    {
        Easy,
        Medium,
        Hard
    };

    Button m_easyBotton;
    Button m_midumButton;
    Button m_hardButton;
    Button m_exitButton;

    Difficulty m_diffculty;

    sf::Font m_font;

public:
    Controller();
    void run(sf::RenderWindow* window);
    bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow* window);
};