#include "Button.h"



//constructors:
Button::Button() {}
Button::Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textColor)
{
    text.setString(t);
    text.setFillColor(textColor);
    text.setCharacterSize(charSize);

    button.setSize(size);
    button.setFillColor(bgcolor);
}

//function that sets the font:
void Button::setFont(sf::Font& font)
{
    text.setFont(font);
}
//function that sets the text to bold:
void Button::setBold()
{
    text.setStyle(sf::Text::Bold);
}
//function that sets the rectangle color:
void Button::setBackColor(sf::Color color)
{
    button.setFillColor(color);
}
//function that sets the text color:
void Button::setTextColor(sf::Color color)
{
    text.setFillColor(color);
}
//function that sets the rectangle and the text positions:
void Button::setPosition(sf::Vector2f pos)
{
    //set the button position:
    button.setPosition(pos);
    //set the text position to be in the center of the button:
    text.setPosition(pos.x + (button.getGlobalBounds().width - text.getGlobalBounds().width) / 2,
        pos.y + (button.getGlobalBounds().height / 2 - text.getGlobalBounds().height / 2));
}
//get function that returs the rect button:
sf::RectangleShape Button::getbutton() const
{
    return button;
}
//get function that returns the text:
sf::Text Button::getext() const
{
    return text;
}
//set function that sets all the button details and text:
void Button::setButtonInfo(std::string t, sf::Vector2f size, int charSize, sf::Color bgcolor, sf::Color textColor, sf::Vector2f pos
    , sf::Font& font)
{
    text.setString(t);
    text.setFillColor(textColor);
    text.setCharacterSize(charSize);
    text.setFont(font);
    button.setSize(size);
    button.setFillColor(bgcolor);
    setPosition(pos);
}
//function that draws the rectangle and the text to the window:
void Button::drawTo(sf::RenderWindow& m_window)
{
    m_window.draw(button);
    m_window.draw(text);
}
//this function if the mouse is over the button(rect and text):
bool Button::isMouseOver(sf::RenderWindow& m_window) {

    sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
    // Check if the mouse is over the image
    if (button.getGlobalBounds().contains(mousePos.x, mousePos.y))
        return true;
    else
        return false;
}