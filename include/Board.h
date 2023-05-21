#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Controller.h"
#include "Hexagon.h"
#include <fstream>
#include <iostream>
#include <cstdlib>  
#include <queue>
#include "ToolFrame.h"


class Board{

private:
	std::vector<std::vector<Hexagon>> m_board;
	void createAdjacentLists();


	const int m_drawingHeight = 0.9 * BOARD_HEIGHT;
	const int m_drawingWidth = BOARD_WIDTH;

	const int m_startHeight = 0.1 * BOARD_HEIGHT;
	const int m_startWidth = 0;


	int m_rowsNum;
	int m_colsNum;



	//player percentage:
	double m_playerPercentage;
	double m_computerPercentage;

public:

	Board();
	~Board() {};
	void drawBoard(sf::RenderWindow* window);
	void movePlayer(HexColor desiredColor);
	void moveComputer(Difficulty desired_diffuclty);
	float getPlayerPercentage() const;
	float getComputerPercentage() const;
	HexColor maxNeighborColor(int col, int row);
	//int moveComputer(Difficulty diffculty);
};