#include "ColorBot.h"

ColorBot::ColorBot() {}

ColorBot::ColorBot(float radius, sf::Color color)
{
    m_shape.setRadius(radius);
    m_shape.setFillColor(color);
}

ColorBot::ColorBot(std::string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textColor)
{
    text.setString(t);
    text.setFillColor(textColor);
    text.setCharacterSize(charSize);

    button.setSize(size);
    button.setFillColor(bgcolor);
}

void ColorBot::setColor(sf::Color color)
{
    m_shape.setFillColor(color);
}

void ColorBot::setPosition(sf::Vector2f pos)
{
    m_shape.setPosition(pos);
}


void ColorBot::setButtonInfo(float radius, sf::Color color, sf::Vector2f pos)
{
    m_shape.setRadius(radius);
    m_shape.setFillColor(color);
    m_shape.setPosition(pos);
}

void ColorBot::drawTo(sf::RenderWindow& window)
{
    window.draw(m_shape);
}

//function that sets the font:
void ColorBot::setFont(sf::Font& font)
{
    text.setFont(font);
}
//function that sets the text to bold:
void ColorBot::setBold()
{
    text.setStyle(sf::Text::Bold);
}
//function that sets the rectangle color:
void ColorBot::setBackColor(sf::Color color)
{
    button.setFillColor(color);
}
//function that sets the text color:
void ColorBot::setTextColor(sf::Color color)
{
    text.setFillColor(color);
}
//function that sets the rectangle and the text positions:
void ColorBot::setPosition_for_bot(sf::Vector2f pos)
{
    //set the button position:
    button.setPosition(pos);
    //set the text position to be in the center of the button:
    text.setPosition(pos.x + (button.getGlobalBounds().width - text.getGlobalBounds().width) / 2,
        pos.y + (button.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 2));
}
//get function that returs the rect button:
sf::RectangleShape ColorBot::getbutton() const
{
    return button;
}
//get function that returns the text:
sf::Text ColorBot::getext() const
{
    return text;
}
//set function that sets all the button details and text:
void ColorBot::setButtonInfo_2(string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textColor, sf::Vector2f pos
    , sf::Font& font)
{
    text.setString(t);
    text.setFillColor(textColor);
    text.setCharacterSize(charSize);
    text.setFont(font);
    button.setSize(size);
    button.setFillColor(bgcolor);
    setPosition_for_bot(pos);
}

//this function if the mouse is over the button(rect and text):
bool ColorBot::isMouseOver(sf::RenderWindow& m_window) {

    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    // Check if the mouse is over the image
    if (button.getGlobalBounds().contains(mousePos.x, mousePos.y))
        return true;
    else
        return false;
}
