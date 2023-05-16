#include "StartGame.h"

StartGame::StartGame()
{
	window.create(sf::VideoMode(800, 600), "6Color");
    window.setFramerateLimit(60);

    font.loadFromFile("C:/Windows/Fonts/Arial.ttf");
    random.setButtonInfo_2("Random", { 200,50 }, 30, sf::Color::Transparent, sf::Color::Cyan, { 300,300 }, font);
    Medium.setButtonInfo_2("Medium", { 200,50 }, 30, sf::Color::Transparent, sf::Color::Magenta, { 300,400 }, font);
    Hard.setButtonInfo_2("Hard", { 200,50 }, 30, sf::Color::Transparent, sf::Color::Red, { 300,500 }, font);
}

void StartGame::run()
{
    while (window.isOpen()) {
       // sf::Event event;


        window.clear(sf::Color::Black);
          
         window.draw(random.getbutton());
         window.draw(random.getext());

         window.draw(Medium.getbutton());
         window.draw(Medium.getext());

         window.draw(Hard.getbutton());
         window.draw(Hard.getext());

         window.display();

         if (auto event = sf::Event{}; window.waitEvent(event))
         {
             switch (event.type)
             {
                 //closing window:
             case sf::Event::Closed:
                 window.close();
                 break;
                 //mouse clicked:
             case sf::Event::MouseButtonReleased:
                 handleClick(event.mouseButton);
                 break;
             }
         }
    }
}

void StartGame::handleClick(const sf::Event::MouseButtonEvent& event)
{
    Controller c;
    
    if (random.getbutton().getGlobalBounds().contains(
         window.mapPixelToCoords({ event.x, event.y })))
    {
        c.run(window, "random");
    }
    if (Medium.getbutton().getGlobalBounds().contains(
         window.mapPixelToCoords({ event.x, event.y })))
    {
        c.run(window, "Medium");

    }
    if (Hard.getbutton().getGlobalBounds().contains(
        window.mapPixelToCoords({ event.x, event.y })))
    {
        c.run(window, "Hard");
    }
}


StartGame::~StartGame()
{
}
