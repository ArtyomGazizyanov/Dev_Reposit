#pragma once   

#include <vector>
  
static float const SCREEN_WIDTH = 800;
static float const SCREEN_HEIGHT = 600;
static int const BOARD_SIZE = 8;

static const sf::Color GREY(128, 128, 128);
static const sf::Color BLUE(0, 190, 212);
static const sf::Color EMPTY_COLOR(0, 0, 0, 0);
static const sf::Color RED(255, 0, 0);
static const sf::Color BODY_COLOR(255, 239, 176);
static const sf::Color WHITE_QUEEN_COLOR(161, 247, 217);
static const sf::Color BLACK_QUEEN_COLOR(69, 38, 28);
static const sf::Color CONGRATULATIONS_BACKGROUND_COLOR(212, 212, 212, 150);

static int const TOTAL_AMOUNT_OF_CELLS = BOARD_SIZE * BOARD_SIZE;
static float const SQUARE_SIZE = 64;
static float const OUTBOARD_WIDTH = 3;
static float const OUTBOARD_CHOOSED_CHECKER = 3;
static int const AMOUNT_OF_CHECKERS = 12;
static float const CHECKERS_SIZE = 20; 

static int const DIAGONAL_RIGHT_CELL_NUM = BOARD_SIZE + 1;
static int const DIAGONAL_LEFT_CELL_NUM = BOARD_SIZE -1;


