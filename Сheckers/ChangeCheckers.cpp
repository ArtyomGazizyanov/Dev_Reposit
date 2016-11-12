#include "Header.h"
  
std::vector <int> QUEEN_LINE_FOR_WHITE; 
std::vector <int> QUEEN_LINE_FOR_BLACK;

void FindQueenLines(BoardStruct &board)//, std::vector <int> &QUEEN_LINE_FOR_WHITE, std::vector <int> &QUEEN_LINE_FOR_BLACK)
{
	for (int i = 0; i < BOARD_SIZE; ++i)
	{
		if (board.cells[i].isEnableToPlay)
		{
			QUEEN_LINE_FOR_WHITE.push_back(i);
		}
	}

	for (int i = TOTAL_AMOUNT_OF_CELLS - BOARD_SIZE; i < TOTAL_AMOUNT_OF_CELLS; ++i)
	{
		if (board.cells[i].isEnableToPlay)
		{
			QUEEN_LINE_FOR_BLACK.push_back(i);
		}
	}
}

sf::Vector2f GrabTheChecker(BoardStruct &board, int currChecker, int &whichCheckerCanMove, sf::Vector2f positionOfCursor,
					std::vector <CheckerWay> &possibleWays)
{
	sf::Vector2f deltaPosition;
	possibleWays = GetPossibleWays(board, currChecker);
	whichCheckerCanMove = currChecker;
	deltaPosition.x = positionOfCursor.x - board.cells[currChecker].checker.shape.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
	deltaPosition.y = positionOfCursor.y - board.cells[currChecker].checker.shape.getPosition().y;//тоже самое по игреку
	return deltaPosition;
}

void SetOriginCheckers(BoardStruct &board)
{
	for (int i = 0; i < 24; i++)
	{
		if (board.cells[i].isEnableToPlay)
		{
			board.cells[i].checker.color = black;
			board.cells[i].isEmpty = false;
			board.amountOfBlackCheckers++;
		}
	}

	for (int i = TOTAL_AMOUNT_OF_CELLS - 24; i < TOTAL_AMOUNT_OF_CELLS && board.amountOfWhiteCheckers < 12; i++)
	{
		if (board.cells[i].isEnableToPlay)
		{
			board.cells[i].checker.color = white;
			board.cells[i].isEmpty = false;
			board.amountOfWhiteCheckers++;
		}
	}

	Checker *CurChecker;
	int currentCheckerIndex = 0;
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		for (int col = 0; col < BOARD_SIZE; col++)
		{
			currentCheckerIndex = BOARD_SIZE * row + col;
			CurChecker = &board.cells[currentCheckerIndex].checker;
			if (CurChecker->color == white)
			{ 
				CurChecker->col = col;
				CurChecker->row = row;
				CurChecker->shape = sf::CircleShape(CHECKERS_SIZE);
				CurChecker->shape.setOutlineThickness(1);
				CurChecker->shape.setOutlineColor(sf::Color::Black);
				CurChecker->shape.setFillColor(sf::Color::White);
				CurChecker->shape.setPosition((col + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2, (row + 1)* SQUARE_SIZE + CHECKERS_SIZE / 2);
			}
			else if (CurChecker->color == black)
			{ 
				CurChecker->col = col;
				CurChecker->row = row;
				CurChecker->shape = sf::CircleShape(CHECKERS_SIZE);
				CurChecker->shape.setOutlineThickness(1);
				CurChecker->shape.setOutlineColor(sf::Color::White);
				CurChecker->shape.setFillColor(sf::Color::Black);
				CurChecker->shape.setPosition((col + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2, (row + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2);
			}
			
		}
	}
}

void SetOriginSettingsOfChecker(Checker &checker)
{
	if (checker.color == white)
	{
		checker.shape.setOutlineThickness(1);
		checker.shape.setOutlineColor(sf::Color::Black);
	}
	else
		if (checker.color == black)
		{
			checker.shape.setOutlineThickness(1);
			checker.shape.setOutlineColor(sf::Color::White);
		}
}

void BuildBackground(BoardStruct &board)
{
	MySquare *currCells;
	for (int row = 1; row <= BOARD_SIZE; row++)
	{
		for (int col = 1; col <= BOARD_SIZE; col++)
		{
			const int i = (row - 1) * BOARD_SIZE + (col - 1);
			currCells = &board.cells[i];
			currCells->col = col-1;
			currCells->row = row-1;
			currCells->square.setSize(sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE));
			currCells->square.setPosition(col * SQUARE_SIZE, row * SQUARE_SIZE);
			currCells->square.setOutlineColor(sf::Color::Black);
			currCells->square.setOutlineThickness(OUTBOARD_WIDTH);
			if ((col + row + 1) % 2 == 0)
			{
				currCells->square.setFillColor(GREY);
				currCells->isEnableToPlay = true;
			}
		}
	}
	FindQueenLines(board);
}
 

void DeleteChecker(Checker &checker)
{ 
	checker.shape.setRadius(0);
	checker.color = none;
	checker.isChoosed = false;
	checker.isQueen = false;
}

Checker CopyChecker(Checker &checker)
{
	Checker copiedChecker;
	copiedChecker.col = checker.col;
	copiedChecker.row = checker.row;
	copiedChecker.color = checker.color;
	copiedChecker.isChoosed = checker.isChoosed;
	copiedChecker.isQueen = checker.isQueen;
	copiedChecker.shape = checker.shape;

	return copiedChecker;
}


void ReplaceChecker(MySquare &destinationSquare, MySquare &donorSquare)
{
	destinationSquare.checker = donorSquare.checker;
	destinationSquare.checker.col = destinationSquare.col ;
	destinationSquare.checker.row = destinationSquare.row ;
	destinationSquare.isEmpty = false; 
}

void MakeEmptySquare(MySquare &cell)
{
	DeleteChecker(cell.checker);
	cell.isEmpty = true; 
}

int FindKilledCheckerNumber(int const &newCheckerNum, int const &whichChecker)
{
	int deletedCheckerNum = 0; 
	if ((newCheckerNum - whichChecker) == DIAGONAL_RIGHT_CELL_NUM * 2)
	{
		deletedCheckerNum = whichChecker + DIAGONAL_RIGHT_CELL_NUM;
	}
	else if ((newCheckerNum - whichChecker) == -DIAGONAL_RIGHT_CELL_NUM * 2)
	{
		deletedCheckerNum = whichChecker - DIAGONAL_RIGHT_CELL_NUM;
	}
	else if ((newCheckerNum - whichChecker) == DIAGONAL_LEFT_CELL_NUM * 2)
	{
		deletedCheckerNum = whichChecker + DIAGONAL_LEFT_CELL_NUM;
	}
	else if ((newCheckerNum - whichChecker) == -DIAGONAL_LEFT_CELL_NUM * 2)
	{
		deletedCheckerNum = whichChecker - DIAGONAL_LEFT_CELL_NUM;
	}
	return deletedCheckerNum;
}

std::vector <int> FintFindKilledCheckerNumber_Queen(BoardStruct board, int newCheckerNum, int whichChecker)
{ 
	std::vector <int> checkersToDie;
	int deltaCheckerNum = 0; 
	if ((newCheckerNum - whichChecker) % DIAGONAL_RIGHT_CELL_NUM == 0)
	{
		if (newCheckerNum < whichChecker)
		{
				deltaCheckerNum = -DIAGONAL_RIGHT_CELL_NUM;
		}
		else
		{
			deltaCheckerNum = DIAGONAL_RIGHT_CELL_NUM;
		}
		 
	}
	else
			if ((newCheckerNum - whichChecker) % DIAGONAL_LEFT_CELL_NUM == 0)
			{
				if (newCheckerNum < whichChecker)
				{
					deltaCheckerNum = -DIAGONAL_LEFT_CELL_NUM;
				}
				else
				{
					deltaCheckerNum = DIAGONAL_LEFT_CELL_NUM;
				} 
			}
	int currChecker = whichChecker + deltaCheckerNum; 
	while (currChecker != newCheckerNum)
	{ 
		if (!board.cells[currChecker].isEmpty)
		{
			checkersToDie.push_back(currChecker);
		}
		currChecker += deltaCheckerNum; 
	} 

	return	checkersToDie;
}

void DeleteKilledChecker(BoardStruct &board, int const &newCheckerNum, int const &whichChecker)
{
	std::vector <int> numCheckerToDelete = FintFindKilledCheckerNumber_Queen(board, newCheckerNum, whichChecker);
	for (int i = 0; i < numCheckerToDelete.size(); ++i)
	{
		if (board.cells[numCheckerToDelete[i]].checker.color == black)
		{
			board.amountOfBlackCheckers--;
		}
		else
			if (board.cells[numCheckerToDelete[i]].checker.color == white)
			{
				board.amountOfWhiteCheckers--;
			}
		DeleteChecker(board.cells[numCheckerToDelete[i]].checker);
		MakeEmptySquare(board.cells[numCheckerToDelete[i]]);
	}
}
 
void changeCheckertoQueen(Checker &checker, CheckerColor const &checkerColor)
{
	if (checkerColor == white)
	{ 
		checker.shape.setFillColor(WHITE_QUEEN_COLOR);
	}
	else
	{
		if (checkerColor == black)
		{
			checker.shape.setFillColor(BLACK_QUEEN_COLOR); 
		}
	}
	checker.isQueen = true;
}

void CheckIsCheckerQueen(BoardStruct &board, int newCheckerNum, int whichChecker)
{
	if (board.cells[whichChecker].checker.color == white)
	{
		for (int i = 0; i < QUEEN_LINE_FOR_WHITE.size(); ++i)
		{
			if (QUEEN_LINE_FOR_WHITE[i] == newCheckerNum)
			{
				changeCheckertoQueen(board.cells[whichChecker].checker, white);
				break;
			}
		}
	}

	if (board.cells[whichChecker].checker.color == black)
	{
		for (int i = 0; i < QUEEN_LINE_FOR_BLACK.size(); ++i)
		{
			if (QUEEN_LINE_FOR_BLACK[i] == newCheckerNum)
			{
				changeCheckertoQueen(board.cells[whichChecker].checker, black);
				break;
			}
		}
	}
}

bool CanCheckerKillSomeoneElse(BoardStruct &board, int whichChecker)
{
	bool isAnyKillerWays = false;
	int choosenDiagonal = 0;
	std::vector <CheckerWay> possibleWays;
	if (board.cells[whichChecker].checker.isQueen)
	{
		FindPossibleWaysForQueen(board, whichChecker, possibleWays, choosenDiagonal);
	}
	else
	{
		FindPossibleWays(board, whichChecker, possibleWays, choosenDiagonal);
	}


	for (int i = 0; i < possibleWays.size(); i++)
	{
		if (possibleWays[i].isKiller == true)
		{
			isAnyKillerWays = true;
		}
	}

	return isAnyKillerWays;
}

bool isCheckerMoving(BoardStruct &board, int &whichCheckerCanMove, CheckerColor checkerColor,int killingChecker, sf::Vector2f positionOfCursor,
	std::vector <CheckerWay> &possibleWays, sf::Vector2f &deltaPosition)
{
	bool isMove = false;
	Checker  checkerToKill = board.cells[killingChecker].checker;
	if (killingChecker != 0)
	{
		if (checkerToKill.color == checkerColor
			&& checkerToKill.shape.getGlobalBounds().contains(positionOfCursor.x, positionOfCursor.y)
			&& (board.cells[killingChecker].isEnableToPlay))//и при этом координата курсора попадает в спрайт
		{
			deltaPosition = GrabTheChecker(board, killingChecker, whichCheckerCanMove, positionOfCursor, possibleWays);
			isMove = true;
		}
	}
	else
		for (int i = 0; i < TOTAL_AMOUNT_OF_CELLS; i++)
		{
			if (board.cells[i].checker.color == checkerColor && board.cells[i].checker.shape.getGlobalBounds().contains(positionOfCursor.x, positionOfCursor.y) && (board.cells[i].isEnableToPlay))//и при этом координата курсора попадает в спрайт
			{
				deltaPosition = GrabTheChecker(board, i, whichCheckerCanMove, positionOfCursor, possibleWays);
				isMove = true;
			}
		}

	return isMove;
}
 
void IfWrongWayCheckerGoBackToStartPostion(BoardStruct &board, int whichChecker, int newCheckerNum, std::vector <CheckerWay> possibleWay)
{ 
	Checker *сhoosenChecker = &board.cells[whichChecker].checker;
	if (whichChecker == newCheckerNum || board.cells[newCheckerNum].checker.color != none)
	{
		сhoosenChecker->shape.setPosition((сhoosenChecker->col + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2,
			(сhoosenChecker->row + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2);
	}
	for (int i = 0; i < possibleWay.size(); i++)
	{
		if (newCheckerNum != possibleWay[i].CheckerNum)
		{
			сhoosenChecker->shape.setPosition((сhoosenChecker->col + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2,
				(сhoosenChecker->row + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2);
		}
	}
}

void CheckAnyKillerWays(std::vector <CheckerWay> possibleWay, bool &isAnyKillerWays)
{
	for (int i = 0; i < possibleWay.size(); i++)
	{
		if (possibleWay[i].isKiller == true)
		{
			isAnyKillerWays = true;
		}
	}
}
 

ChckerMovement SetChoosenCheckerToThePosition(BoardStruct &board, int whichChecker, sf::Vector2f position, std::vector <CheckerWay> possibleWay)
{
	auto newCol = position.x - 1;
	auto newRow = position.y - 1;
	Checker newChecker; 
	ChckerMovement isCheckerMoved;
	isCheckerMoved = no;
	bool isAnyKillerWays = false;
	int newCheckerNum = static_cast<int>((newRow)* BOARD_SIZE + (newCol));
	CheckAnyKillerWays(possibleWay, isAnyKillerWays);

	if (board.cells[newCheckerNum].isEmpty)
	{ 
		if (isAnyKillerWays)
		{
			for (int i = 0; i < possibleWay.size(); i++)
			{
				if (newCheckerNum == possibleWay[i].CheckerNum && possibleWay[i].isKiller && whichChecker != newCheckerNum)
				{ 
					PrepareNewCell(board, whichChecker, newCheckerNum);
					board.cells[newCheckerNum].checker.shape.setPosition((newCol + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2, (newRow + 1)* SQUARE_SIZE + CHECKERS_SIZE / 2); 
					DeleteKilledChecker(board, newCheckerNum, whichChecker);
					if (CanCheckerKillSomeoneElse(board, newCheckerNum))
					{ 
						isCheckerMoved = kill;
					}
					else
					{ 
						isCheckerMoved = setUp;
					} 
				}
			}
		}
		else
		{
			for (int i = 0; i < possibleWay.size(); i++)
			{
				if (newCheckerNum == possibleWay[i].CheckerNum && whichChecker != newCheckerNum)
				{   
					PrepareNewCell(board, whichChecker, newCheckerNum);
					board.cells[newCheckerNum].checker.shape.setPosition((newCol + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2, (newRow + 1)* SQUARE_SIZE + CHECKERS_SIZE / 2); 
					isCheckerMoved = setUp;
				}
			}
		}   

		if (isCheckerMoved == no|| (whichChecker == newCheckerNum))
		{
			board.cells[whichChecker].checker.shape.setPosition((board.cells[whichChecker].checker.col + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2,
				(board.cells[whichChecker].checker.row + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2);
		}
	} 
	IfWrongWayCheckerGoBackToStartPostion(board, whichChecker, newCheckerNum, possibleWay);
	possibleWay.clear();

	return isCheckerMoved;
}

bool  SetCheckerOnBoard(BoardStruct &board, int whichCheckerCanMove, sf::Vector2f positionOfCursor, std::vector <CheckerWay> &possibleWays, int &killingChecker, bool &isWhitePlayerTurn)
{
	int col = static_cast<int>(positionOfCursor.x / SQUARE_SIZE);
	int row = static_cast<int>(positionOfCursor.y / SQUARE_SIZE);
	float fcol = static_cast<float>(col);
	float frow = static_cast<float>(row);

	sf::Vector2f  Coordinate(fcol, frow);
	bool isSetChecker = false;
	ChckerMovement checkerMovement = SetChoosenCheckerToThePosition(board, whichCheckerCanMove, Coordinate, possibleWays);
	if (checkerMovement == setUp)
	{
		possibleWays.empty();
		isWhitePlayerTurn = !isWhitePlayerTurn;//работающий 
		killingChecker = 0;
	}
	else
	{
		if (checkerMovement == kill)
		{
			killingChecker = (Coordinate.x - 1 + (Coordinate.y - 1) * BOARD_SIZE);
		}
	}

	return isSetChecker;
}

void ClearBoard(BoardStruct &board)
{
	board.amountOfBlackCheckers = 0;
	board.amountOfWhiteCheckers = 0;
	for (int i = 0; i < TOTAL_AMOUNT_OF_CELLS; ++i)
	{
		MakeEmptySquare(board.cells[i]);
	}
}
