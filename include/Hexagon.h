#pragma once

#include "Macros.h"
#include <SFML/Graphics.hpp>

class Hexagon
{
private:
	sf::CircleShape m_shape;

public:
	Hexagon();
	void setColor(sf::Color color);
	sf::Color getColor() const;
	sf::Vector2f getPosition() const;
};