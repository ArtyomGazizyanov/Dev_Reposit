#include "Header.h"

void DrawBackground(sf::RenderWindow &window)
{
	sf::RectangleShape background ((sf::Vector2f(SCREEN_HEIGHT, SCREEN_WIDTH)));
	background.setFillColor(BODY_COLOR);
	window.draw(background);
}

void SetOriginOutlineColorSquare(MySquare &thisSquare)
{
	thisSquare.square.setOutlineColor(sf::Color::Black);
	thisSquare.square.setOutlineThickness(OUTBOARD_WIDTH);
}

void ColorChoosenChecker(BoardStruct &board, int whichChecker)
{
	for (int i = 0; i < TOTAL_AMOUNT_OF_CELLS; ++i)
	{
		if (board.cells[i].checker.isChoosed == true)
		{
			board.cells[i].checker.isChoosed = false;
			SetOriginSettingsOfChecker(board.cells[i].checker);
		}
		if (i == whichChecker)
		{
			board.cells[i].checker.isChoosed = true;
			board.cells[i].checker.shape.setOutlineColor(BLUE);
			board.cells[i].checker.shape.setOutlineThickness(OUTBOARD_CHOOSED_CHECKER);
		}
	}
}

void CleanSquaresOutline(BoardStruct &board)
{
	for (int i = 0; i < TOTAL_AMOUNT_OF_CELLS; ++i)
	{
		SetOriginOutlineColorSquare(board.cells[i]);
	}
}

void ColorSqures(BoardStruct &board, std::vector <CheckerWay> &possibleWay)
{
	CleanSquaresOutline(board);
	int currentSquare;
	bool isAnyKillerWays = false;
	for (int i = 0; i < possibleWay.size(); ++i)
	{
		if (possibleWay[i].isKiller)
		{
			isAnyKillerWays = true;
		}
	}
	if (isAnyKillerWays)
	{
		for (int i = 0; i < possibleWay.size(); ++i)
		{
			if (possibleWay[i].isKiller)
			{
				currentSquare = possibleWay[i].CheckerNum;
				board.cells[currentSquare].square.setOutlineColor(RED);
				board.cells[currentSquare].square.setOutlineThickness(3);
			}
		}
	}
	else
	{
		for (int i = 0; i < possibleWay.size(); ++i)
		{
			if (!possibleWay[i].isKiller)
			{
				currentSquare = possibleWay[i].CheckerNum;
				board.cells[currentSquare].square.setOutlineColor(BLUE);
				board.cells[currentSquare].square.setOutlineThickness(3);
			}
		}
	}
	
}

void DrawDeck(BoardStruct &board, sf::RenderWindow& window)
{
	// Clear the window
	window.clear(BODY_COLOR);
	for (int i = 0; i < TOTAL_AMOUNT_OF_CELLS; ++i)
	{
		window.draw(board.cells[i].square);
	}

	for (int i = 0; i < TOTAL_AMOUNT_OF_CELLS; ++i)
	{
		if (board.cells[i].checker.color != none)
			window.draw(board.cells[i].checker.shape);
	}
}