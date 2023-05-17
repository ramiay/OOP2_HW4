#include "Hexagon.h"


Hexagon::Hexagon()
{
	//make it one line!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	m_shape.setRadius(RADIUS);
   	m_shape.setPointCount(6);

}
void Hexagon::setColor(sf::Color color)
{
	m_shape.setFillColor(color);
}
sf::Color Hexagon::getColor() const
{
	return m_shape.getFillColor();
}

sf::Vector2f Hexagon::getPosition() const
{
	return m_shape.getPosition();

	
}



