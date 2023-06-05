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


	const int m_drawingHeight = 0.9 * BOARD_HEIGHT;
	const int m_drawingWidth = BOARD_WIDTH;

	const int m_startHeight = 0.1 * BOARD_HEIGHT;
	const int m_startWidth = 0;


	int m_rowsNum;
	int m_colsNum;



	//player percentage:
	double m_playerPercentage;
	double m_computerPercentage;

	//Last colors used by computer and player:
	HexColor m_LastUserColor;
	HexColor m_LastComColor;

public:

	Board();
	~Board() {};
	void drawBoard(sf::RenderWindow* window);
	void movePlayer(HexColor desiredColor);
	void moveComputer(Difficulty desired_diffuclty);
	float getPlayerPercentage() const;
	float getComputerPercentage() const;
	HexColor maxNeighborColor(int in_col, int in_row, Difficulty level);
	void travelOnBoard(HexColor desiredColor, int startCol, int startRow);
	//int moveComputer(Difficulty diffculty);
	void createAdjacentLists();



};