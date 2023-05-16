#include "ToolBar.h"

ToolBar::ToolBar()
{

    m_blue.setButtonInfo( { 25 },sf::Color::Blue, { 200,520 });
    m_brown.setButtonInfo({ 25}, sf::Color::White, { 275,520 });
    m_green.setButtonInfo( { 25 }, sf::Color::Green, { 350,520 });
    m_pink.setButtonInfo( { 25 },sf::Color::Magenta, { 425,520 });
    m_red.setButtonInfo( { 25 },sf::Color::Red, { 500,520 });
    m_yellow.setButtonInfo({ 25 }, sf::Color::Yellow, { 575,520 });
}

void ToolBar::draw(sf::RenderWindow& window)
{
    //window.draw(yourPer);
    m_blue.drawTo(window);
    m_brown.drawTo(window);
    m_green.drawTo(window);
    m_pink.drawTo(window);
    m_red.drawTo(window);
    m_yellow.drawTo(window);
}

ToolBar::~ToolBar()
{
}
