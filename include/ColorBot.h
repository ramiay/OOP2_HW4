//progma once prevent us from including
//multiple times:
#pragma once
// --- includes --- 
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
// ---- namspaces ---
using namespace std;
// ------------------

class ColorBot
{
public:
    ColorBot();
    ColorBot(float radius, sf::Color color);
    ColorBot(std::string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textColor);

    void setColor(sf::Color color);
    void setPosition(sf::Vector2f pos);
    void setButtonInfo(float radius, sf::Color color, sf::Vector2f pos);
    void drawTo(sf::RenderWindow& window);

    void setFont(sf::Font& font);
    void setBold();
    void setBackColor(sf::Color color);
    void setTextColor(sf::Color color);
    void setPosition_for_bot(sf::Vector2f pos);
    sf::RectangleShape getbutton() const;
    sf::Text getext() const;
    void setButtonInfo_2(string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textColor, sf::Vector2f pos
        , sf::Font& font);

    bool isMouseOver(sf::RenderWindow& m_window);


private:
    sf::CircleShape m_shape;
    sf::RectangleShape button;
    sf::Text text;
};
