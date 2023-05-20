#pragma once
#include <string>

constexpr int BOARD_WIDTH = 800;
constexpr int BOARD_HEIGHT = 600;
constexpr int TOOLBAR_HEIGHT = 0.1 * BOARD_HEIGHT;
constexpr int RADIUS = 10;

enum class HexColor
{
    Red,
    Blue,
    Gray,
    Green,
    Yellow,
    Magneta,
    Invalid
};

enum class Difficulty
{
    Easy,
    Medium,
    Hard
};