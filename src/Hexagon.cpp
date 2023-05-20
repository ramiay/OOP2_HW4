#include "Hexagon.h"


Hexagon::Hexagon() : m_isOcuupied(false)
{
	m_shape.setRadius(RADIUS),m_shape.setPointCount(6);
	m_shape.setOutlineThickness(1);
	m_shape.setOutlineColor(sf::Color::Black);
}

HexColor Hexagon::getColor() const
{
	if (m_shape.getFillColor() == sf::Color(237, 8, 0))
		return HexColor::Red;

	if (m_shape.getFillColor() == sf::Color())

		if (m_shape.getFillColor() == sf::Color(0, 150, 255))
			return HexColor::Blue;

	if (m_shape.getFillColor() == sf::Color(255, 234, 0))
		return HexColor::Yellow;

	if (m_shape.getFillColor() == sf::Color(178, 190, 181))
		return HexColor::Gray;

	if (m_shape.getFillColor() == sf::Color(80, 200, 120))
		return HexColor::Green;

	if (m_shape.getFillColor() == sf::Color(255, 0, 255))
		return HexColor::Magneta;
	else
		return HexColor::Invalid;
}
void Hexagon::setColor(HexColor Color)
{
	if (Color == HexColor::Red)
		m_shape.setFillColor(sf::Color(237, 8, 0));

	if (Color == HexColor::Blue)
		m_shape.setFillColor(sf::Color(0, 150, 255));

	if (Color == HexColor::Yellow)
		m_shape.setFillColor(sf::Color(255, 234, 0));

	if (Color == HexColor::Gray)
		m_shape.setFillColor(sf::Color(178, 190, 181));

	if (Color == HexColor::Green)
		m_shape.setFillColor(sf::Color(80, 200, 120));

	if (Color == HexColor::Magneta)
		m_shape.setFillColor(sf::Color(255, 0, 255));
}
sf::Vector2f Hexagon::getPosition() const
{
	return m_shape.getPosition();

}

void Hexagon::setPosition(sf::Vector2f vector)
{
	m_shape.setPosition(vector);
}



sf::CircleShape Hexagon::getShape() const
{
	return m_shape;
}

void Hexagon::setRadius(float radius)
{
	m_shape.setRadius(radius);
}

bool Hexagon::occupiedStatus() const
{
	return m_isOcuupied;
}
void Hexagon::setOccupiedStatus(bool status)
{
	m_isOcuupied = status;
}
