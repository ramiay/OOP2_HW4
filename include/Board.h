#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Controller.h"
#include "Hexagon.h"
#include <fstream>
#include <iostream>
#include <cstdlib>  
#include <queue>


class Board{

private:
	std::vector<std::vector<Hexagon>> m_board;

	const int m_drawingHeight = 0.9 * BOARD_HEIGHT;
	const int m_drawingWidth = BOARD_WIDTH;

	const int m_startHeight = 0.1 * BOARD_HEIGHT;
	const int m_startWidth = 0;


	int m_rowsNum;
	int m_colsNum;

	//player percentage:
	double m_playerPercentage;
	double m_computerPercentage;
	//player's occupied hexagons:
	std::vector<std::vector<Hexagon>> m_playerOccupiedHexagons;
	std::vector<std::vector<Hexagon>> m_computerOccupiedHexagons;
public:

	Board();
	~Board() {};
	void drawBoard(sf::RenderWindow* window);
	int movePlayer(HexColor desiredColor);
	//int moveComputer(Difficulty diffculty);
};