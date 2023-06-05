#pragma once

// --- includes --- 
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Button.h"
#include "Board.h"
#include "ToolFrame.h"

class Controller
{
private:
    

    Button m_easyBotton;
    Button m_midumButton;
    Button m_hardButton;
    Button m_exitButton;

    Difficulty m_diffculty;

    sf::Font m_font;

    bool m_computerWon;
    bool m_playerWon;

    sf::Texture GameOverTexture;
    sf::Texture You_winTexture;
    //sprite
    sf::Sprite GameOverSprite;
    sf::Sprite You_winSprite;

public:
    Controller();
    void run(sf::RenderWindow* window);
    bool handleClick(const sf::Event::MouseButtonEvent& event, sf::RenderWindow* window);
    void handleHoverOver(sf::RenderWindow* window);
    ~Controller() {};

};