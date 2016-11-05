#pragma once
#include "Consts.h"

//using namespace sf;

enum CheckerColor
{
	none = 0,
	white = 1,
	black = 2
};

enum ChckerMovement
{
	no = 0,
	setUp = 1,
	kill = 2
};

struct CheckerWay
{
	int CheckerNum = NULL; 
	bool isKiller = false;
};

struct MoveWay
{
	std::vector <int> topLeft;
	std::vector <int> topRight;
	std::vector <int> downLeft;
	std::vector <int> downRight;
};

struct WhichCanMove
{
	int number;
	int color;
};

struct Checker
{
	sf::CircleShape shape;
	CheckerColor color;
	int row;
	int col;
	bool isQueen = false;
	bool isChoosed = false;
};

struct MySquare
{
	sf::RectangleShape square;
	Checker checker;
	bool isEmpty = true;
	bool isEnableToPlay = false;
	int row;
	int col;
};

struct BoardStruct
{
	MySquare cells[TOTAL_AMOUNT_OF_CELLS];
	int amountOfWhiteCheckers = 0;
	int amountOfBlackCheckers = 0;
};

struct AI_MoveWays
{
	int num;
	std::vector <CheckerWay> possibleWays;
};
