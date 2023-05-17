#pragma once
#include <SFML/Graphics.hpp>
#include "Macros.h"
#include "Controller.h"
#include "Hexagon.h"
#include <fstream>
#include <iostream>

// In the board class:
const int m_drawingHeight = 0.85 * BOARD_HEIGHT;
const int m_drawingWidth = BOARD_WIDTH;
const int m_startHeight = 0.15 * BOARD_HEIGHT;


class Board{

private:
	Hexagon m_hex;


public:

	Board();
	void CreatBoard();
	void FillRandomColor();
	~Board() {};



};