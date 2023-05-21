#include "Hexagon.h"


Hexagon::Hexagon() : m_isOccupiedByPlayer(false) , m_isOcuupiedByComputer(false)
{
	m_shape.setRadius(RADIUS),m_shape.setPointCount(6);
	m_shape.setOutlineThickness(1);
	m_shape.setOutlineColor(sf::Color::Black);
}

HexColor Hexagon::getColor() const
{
	if (m_shape.getFillColor() == sf::Color::Red)
		return HexColor::Red;

	if (m_shape.getFillColor() == sf::Color::Blue)
		return HexColor::Blue;

	if (m_shape.getFillColor() == sf::Color::Yellow)
		return HexColor::Yellow;

	if (m_shape.getFillColor() == sf::Color(178, 190, 181))
		return HexColor::Gray;

	if (m_shape.getFillColor() == sf::Color::Green)
		return HexColor::Green;

	if (m_shape.getFillColor() == sf::Color::Magenta)
		return HexColor::Magneta;
	else
		return HexColor::Invalid;
}


void Hexagon::setColor(HexColor Color)
{
	if (Color == HexColor::Red)
		m_shape.setFillColor(sf::Color::Red);

	if (Color == HexColor::Blue)
		m_shape.setFillColor(sf::Color::Blue);

	if (Color == HexColor::Yellow)
		m_shape.setFillColor(sf::Color::Yellow);

	if (Color == HexColor::Gray)
		m_shape.setFillColor(sf::Color(178, 190, 181));

	if (Color == HexColor::Green)
		m_shape.setFillColor(sf::Color::Green);

	if (Color == HexColor::Magneta)
		m_shape.setFillColor(sf::Color::Magenta);
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

bool Hexagon::isOccupiedByPlayer() const
{
	return m_isOccupiedByPlayer;
}
void Hexagon::setOccupiedByPlayerStatus(bool status)
{
	m_isOccupiedByPlayer = status;
}

void Hexagon::addAdjacent(const std::shared_ptr<Hexagon>& hex)
{
	this->m_adjacentsList.push_back(hex);
}


bool Hexagon::isOccupiedByComputer() const
{
	return m_isOcuupiedByComputer;
}

void Hexagon::setOccupiedByComputerStatus(bool status)
{
	m_isOcuupiedByComputer = status;
}
std::vector<std::shared_ptr<Hexagon>>& Hexagon::getAdjacents()
{
	return this->m_adjacentsList;
}
