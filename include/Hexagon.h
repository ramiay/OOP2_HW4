#pragma once

#include "Macros.h"
#include <SFML/Graphics.hpp>

class Hexagon
{
private:
	sf::CircleShape m_shape;
	bool m_isOccupiedByPlayer = false;
	bool m_isOcuupiedByComputer = false;
	std::vector<std::shared_ptr<Hexagon>> m_adjacentsList;



public:
	Hexagon();
	HexColor getColor() const;
	void setColor(HexColor Color);
	void setPosition(sf::Vector2f vector);
	sf::Vector2f getPosition() const;
	sf::CircleShape getShape() const;
	void setRadius(float radius);

	bool isOccupiedByPlayer() const;
	void setOccupiedByPlayerStatus(bool status);
	
	bool isOccupiedByComputer() const;
	void setOccupiedByComputerStatus(bool status);

	void addAdjacent(const std::shared_ptr<Hexagon>& hex);
	std::vector<std::shared_ptr<Hexagon>>& getAdjacents();

};