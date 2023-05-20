#pragma once

#include "Macros.h"
#include <SFML/Graphics.hpp>

class Hexagon
{
private:
	sf::CircleShape m_shape;
	bool m_isOcuupied = false;
public:
	Hexagon();
	HexColor getColor() const;
	void setColor(HexColor Color);
	void setPosition(sf::Vector2f vector);
	sf::Vector2f getPosition() const;
	sf::CircleShape getShape() const;
	void setRadius(float radius);

	bool occupiedStatus() const;
	void setOccupiedStatus(bool status);
};