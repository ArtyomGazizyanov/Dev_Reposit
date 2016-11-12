#include "Header.h"


void QueenCalculateDiagonal_TopLeft(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays)
{
	if (((board.cells[whichChecker].row - 1) >= 0) && ((board.cells[whichChecker].col - 1) >= 0) && board.cells[whichChecker - BOARD_SIZE - 1].isEnableToPlay)
	{
		CheckerWay topLeftChecker;
		topLeftChecker.CheckerNum = whichChecker - BOARD_SIZE - 1;
		if (board.cells[topLeftChecker.CheckerNum].isEmpty)
		{
			if (choosenDiagonal == 0)
			{
				possibleWays.push_back(topLeftChecker);
				QueenCalculateDiagonal_TopLeft(board, topLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
			}
			else
				if (choosenDiagonal == 1 && (!board.cells[whichChecker].isEmpty || possibleWays[possibleWays.size() - 1].isKiller)) //проверяем пустую клетку за найденным врагом
				{
					topLeftChecker.isKiller = true;
					possibleWays.push_back(topLeftChecker);
					QueenCalculateDiagonal_TopLeft(board, topLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
				}
		}
		else
		{ 
			if (board.cells[startChecker].checker.color != board.cells[topLeftChecker.CheckerNum].checker.color
				&& board.cells[whichChecker].checker.color != board.cells[topLeftChecker.CheckerNum].checker.color)
			{
				if (choosenDiagonal == 0)
				{
					choosenDiagonal = 1;
					QueenCalculateDiagonal_TopLeft(board, topLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays );
					choosenDiagonal = 0;
				}
				else
					if (choosenDiagonal == 1)
					{
						QueenCalculateDiagonal_TopLeft(board, topLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					}
			}
		}
	}
}

void AddNextCellToPosibleWays(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays, CheckerWay nextDiagonalCell)
{
	if (choosenDiagonal == 0)
	{
		possibleWays.push_back(nextDiagonalCell);
		QueenCalculateDiagonal_TopLeft(board, nextDiagonalCell.CheckerNum, startChecker, choosenDiagonal, possibleWays);
	}
	else
		if (choosenDiagonal == 1 && (!board.cells[whichChecker].isEmpty || possibleWays[possibleWays.size() - 1].isKiller)) //проверяем пустую клетку за найденным врагом
		{
			nextDiagonalCell.isKiller = true;
			possibleWays.push_back(nextDiagonalCell);
			QueenCalculateDiagonal_TopLeft(board, nextDiagonalCell.CheckerNum, startChecker, choosenDiagonal, possibleWays);
		}
}

void QueenCalculateDiagonal_TopRight(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays)
{
	if (((board.cells[whichChecker].row - 1) >= 0) && ((board.cells[whichChecker].col + 1) <= BOARD_SIZE) && board.cells[whichChecker - BOARD_SIZE + 1].isEnableToPlay)
	{ 
		CheckerWay topRightChecker;
		topRightChecker.CheckerNum = whichChecker - BOARD_SIZE + 1;
		if (board.cells[topRightChecker.CheckerNum].isEmpty)
		{
			if (choosenDiagonal == 0)
			{
				possibleWays.push_back(topRightChecker); 
				QueenCalculateDiagonal_TopRight(board, topRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
			}
			else
				if (choosenDiagonal == 2 && (!board.cells[whichChecker].isEmpty || possibleWays[possibleWays.size() - 1].isKiller))
				{

					topRightChecker.isKiller = true;
					possibleWays.push_back(topRightChecker);
					QueenCalculateDiagonal_TopRight(board, topRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
				}
		}
		else
		{  
			if (board.cells[startChecker].checker.color != board.cells[topRightChecker.CheckerNum].checker.color
				&& board.cells[whichChecker].checker.color != board.cells[topRightChecker.CheckerNum].checker.color)
			{
				if (choosenDiagonal == 0)
				{
					choosenDiagonal = 2;
					QueenCalculateDiagonal_TopRight(board, topRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					choosenDiagonal = 0;
				}
				else
					if (choosenDiagonal == 2)
					{
						QueenCalculateDiagonal_TopRight(board, topRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					}
			}
		}
	}
}

void QueenCalculateDiagonal_DownLeft(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays)
{ 
	if (((board.cells[whichChecker].row + 1) < BOARD_SIZE) && ((board.cells[whichChecker].col - 1) >= 0) && board.cells[whichChecker + BOARD_SIZE - 1].isEnableToPlay)
	{
		CheckerWay downLeftChecker; 
		downLeftChecker.CheckerNum = whichChecker + BOARD_SIZE - 1;
		if (board.cells[downLeftChecker.CheckerNum].isEmpty)
		{
			if (choosenDiagonal == 0)
			{
				possibleWays.push_back(downLeftChecker);
				QueenCalculateDiagonal_DownLeft(board, downLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
			}
			if (choosenDiagonal == 3 && (!board.cells[whichChecker].isEmpty || possibleWays[possibleWays.size() - 1].isKiller))
			{
				downLeftChecker.isKiller = true;
				possibleWays.push_back(downLeftChecker);
				QueenCalculateDiagonal_DownLeft(board, downLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);

			}
		}
		else
		{ 
			if(board.cells[startChecker].checker.color != board.cells[downLeftChecker.CheckerNum].checker.color
				&& board.cells[whichChecker].checker.color != board.cells[downLeftChecker.CheckerNum].checker.color)
			{
				if (choosenDiagonal == 0)
				{
					choosenDiagonal = 3;
					QueenCalculateDiagonal_DownLeft(board, downLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					choosenDiagonal = 0;
				}
				else
					if (choosenDiagonal == 3)
					{
						QueenCalculateDiagonal_DownLeft(board, downLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					}
			}
		}
	}
}

void QueenCalculateDiagonal_DownRight(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays)
{ 
	if (((board.cells[whichChecker].row + 1) < BOARD_SIZE) && ((board.cells[whichChecker].col + 1) < BOARD_SIZE) && board.cells[whichChecker + BOARD_SIZE + 1].isEnableToPlay)
	{
		CheckerWay downRightChecker;
		downRightChecker.CheckerNum = whichChecker + BOARD_SIZE + 1;
		if (board.cells[downRightChecker.CheckerNum].isEmpty)
		{ 
			if (choosenDiagonal == 0)
			{
				possibleWays.push_back(downRightChecker);
				QueenCalculateDiagonal_DownRight(board, downRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
			}
			else
				if (choosenDiagonal == 4 && (!board.cells[whichChecker].isEmpty || possibleWays[possibleWays.size() - 1].isKiller))
				{
					downRightChecker.isKiller = true;
					possibleWays.push_back(downRightChecker);
					QueenCalculateDiagonal_DownRight(board, downRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
				}
		}
		else
		{
			if (board.cells[startChecker].checker.color != board.cells[downRightChecker.CheckerNum].checker.color 
				&& board.cells[whichChecker].checker.color != board.cells[downRightChecker.CheckerNum].checker.color) 				
			{ 
				if (choosenDiagonal == 0)
				{
					choosenDiagonal = 4;
					QueenCalculateDiagonal_DownRight(board, downRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					choosenDiagonal = 0;
				}
				else
					if (choosenDiagonal == 4)
					{
						QueenCalculateDiagonal_DownRight(board, downRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					}
			}
		} 
	}
}
 

void FindPossibleWaysForQueen(BoardStruct &board, int whichChecker, std::vector <CheckerWay> &possibleWays, int choosenDiagonal)
{
	QueenCalculateDiagonal_TopLeft(board, whichChecker, whichChecker, choosenDiagonal, possibleWays);
	QueenCalculateDiagonal_TopRight(board, whichChecker, whichChecker, choosenDiagonal, possibleWays);
	QueenCalculateDiagonal_DownLeft(board, whichChecker, whichChecker, choosenDiagonal, possibleWays);
	QueenCalculateDiagonal_DownRight(board, whichChecker, whichChecker, choosenDiagonal, possibleWays);
}

void CalculateDiagonal_TopLeft(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays)
{
	if (((board.cells[whichChecker].row - 1) >= 0) && ((board.cells[whichChecker].col - 1) >= 0) && board.cells[whichChecker - BOARD_SIZE - 1].isEnableToPlay)
	{
		CheckerWay topLeftChecker;
		topLeftChecker.CheckerNum = whichChecker - BOARD_SIZE - 1;
		if (board.cells[topLeftChecker.CheckerNum].isEmpty)
		{
			if (choosenDiagonal == 0)
			{
				possibleWays.push_back(topLeftChecker);
			}
			else
				if (choosenDiagonal == 1) //проверяем пустую клетку за найденным врагом
				{					
					topLeftChecker.isKiller = true;
					possibleWays.push_back(topLeftChecker);
				}
		}
		else
		{ 
			if (board.cells[startChecker].checker.color != board.cells[topLeftChecker.CheckerNum].checker.color
				&& board.cells[whichChecker].checker.color != board.cells[topLeftChecker.CheckerNum].checker.color)
			{
				if (choosenDiagonal == 0)
				{
					choosenDiagonal = 1;
					CalculateDiagonal_TopLeft(board, topLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					choosenDiagonal = 0;
				}
				else
					if (choosenDiagonal == 1)
					{
						CalculateDiagonal_TopLeft(board, topLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays );
					}
			}
		}
	}
}

void CalculateDiagonal_TopRight(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays)
{
	if (((board.cells[whichChecker].row - 1) >= 0) && ((board.cells[whichChecker].col + 1) <= BOARD_SIZE) && board.cells[whichChecker - BOARD_SIZE + 1].isEnableToPlay)
	{
		CheckerWay topRightChecker;
		topRightChecker.CheckerNum = whichChecker - BOARD_SIZE + 1;
		if (board.cells[topRightChecker.CheckerNum].isEmpty)
		{
			if (choosenDiagonal == 0)
			{
				possibleWays.push_back(topRightChecker);
			}
			else
				if (choosenDiagonal == 2)
				{
					topRightChecker.isKiller = true;
					possibleWays.push_back(topRightChecker);
				}
		}
		else
		{
			if (board.cells[startChecker].checker.color != board.cells[topRightChecker.CheckerNum].checker.color
				&& board.cells[whichChecker].checker.color != board.cells[topRightChecker.CheckerNum].checker.color)
			{
				if (choosenDiagonal == 0)
				{
					choosenDiagonal = 2;
					CalculateDiagonal_TopRight(board, topRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					choosenDiagonal = 0;
				}
				else
					if (choosenDiagonal == 2)
					{
						std::cout << "smth!!!!" << std::endl;
						CalculateDiagonal_TopRight(board, topRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					}
			}
		}
	}
}

void CalculateDiagonal_DownLeft(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays)
{
	if (((board.cells[whichChecker].row + 1) < BOARD_SIZE) && ((board.cells[whichChecker].col - 1) >= 0) && board.cells[whichChecker + BOARD_SIZE - 1].isEnableToPlay)
	{
		CheckerWay downLeftChecker;
		if (!board.cells[whichChecker].col == 0)
		{
			downLeftChecker.CheckerNum = whichChecker + BOARD_SIZE - 1;
		}
		else
		{
			downLeftChecker.CheckerNum = whichChecker + BOARD_SIZE;
		}
		if (board.cells[downLeftChecker.CheckerNum].isEmpty)
		{
			if (choosenDiagonal == 0)
			{
				possibleWays.push_back(downLeftChecker);
			}
			if (choosenDiagonal == 3)
			{
				downLeftChecker.isKiller = true;
				possibleWays.push_back(downLeftChecker);

			}
		}
		else
		{
			if (board.cells[startChecker].checker.color != board.cells[downLeftChecker.CheckerNum].checker.color
				&& board.cells[whichChecker].checker.color != board.cells[downLeftChecker.CheckerNum].checker.color)
			{
				if (choosenDiagonal == 0)
				{
					choosenDiagonal = 3;
					CalculateDiagonal_DownLeft(board, downLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					choosenDiagonal = 0;
				}
				else
					if (choosenDiagonal == 3)
					{
						CalculateDiagonal_DownLeft(board, downLeftChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					}
			}
		}			
	}
}

void CalculateDiagonal_DownRight(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, std::vector <CheckerWay> &possibleWays)
{
	if (((board.cells[whichChecker].row + 1) < BOARD_SIZE) && ((board.cells[whichChecker].col + 1) < BOARD_SIZE) && board.cells[whichChecker + BOARD_SIZE + 1].isEnableToPlay)
	{
		CheckerWay downRightChecker;
		downRightChecker.CheckerNum = whichChecker + BOARD_SIZE + 1;
		if (board.cells[downRightChecker.CheckerNum].isEmpty)
		{
			if (choosenDiagonal == 0)
			{
				possibleWays.push_back(downRightChecker);
			}
			else
				if (choosenDiagonal == 4)
				{
					downRightChecker.isKiller = true;
					possibleWays.push_back(downRightChecker);
				}
		}
		else
		{
			if (board.cells[startChecker].checker.color != board.cells[downRightChecker.CheckerNum].checker.color
				&& board.cells[whichChecker].checker.color != board.cells[downRightChecker.CheckerNum].checker.color)
			{
				if (choosenDiagonal == 0)
				{
					choosenDiagonal = 4;
					CalculateDiagonal_DownRight(board, downRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					choosenDiagonal = 0;
				}
				else
					if (choosenDiagonal == 4)
					{
						CalculateDiagonal_DownRight(board, downRightChecker.CheckerNum, startChecker, choosenDiagonal, possibleWays);
					}
			}
		}
	}
}

void FindPossibleWays(BoardStruct &board, int whichChecker, std::vector <CheckerWay> &possibleWays, int choosenDiagonal)
{   
	CalculateDiagonal_TopLeft(board, whichChecker, whichChecker, choosenDiagonal, possibleWays);
	CalculateDiagonal_TopRight(board, whichChecker, whichChecker, choosenDiagonal, possibleWays);
	CalculateDiagonal_DownLeft(board, whichChecker, whichChecker, choosenDiagonal, possibleWays);
	CalculateDiagonal_DownRight(board, whichChecker, whichChecker, choosenDiagonal, possibleWays);
}

std::vector <CheckerWay> GetPossibleWays(BoardStruct &board, int whichChecker)
{  
	int choosenDiagonal = 0;
	std::vector <CheckerWay> possibleWays;
	ColorChoosenChecker(board, whichChecker);
	if (board.cells[whichChecker].checker.isQueen) 
	{
		FindPossibleWaysForQueen(board, whichChecker, possibleWays, choosenDiagonal);
	}
	else
	{ 
		FindPossibleWays(board, whichChecker, possibleWays, choosenDiagonal);
	}
	ColorSqures(board, possibleWays);

	return possibleWays;
}
 
