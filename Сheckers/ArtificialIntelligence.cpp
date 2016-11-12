#include "Header.h"
  
void AI_makesMove(BoardStruct &board, bool &isWhitePlayerTurn, bool isHumanAgainstHuman)
{
	if (!isHumanAgainstHuman && !isWhitePlayerTurn)
	{
		CheckAllWays_AI(board);
		isWhitePlayerTurn = true;
	}
}

void CheckAllWays_AI(BoardStruct &board)
{
	int choosenDiagonal = 0;
	int currentCheckWay = 0;
	std::vector <AI_MoveWays> possibleWays_AI;
	AI_MoveWays temp_AI;
	std::vector <CheckerWay> possibleWays;
	for (int i = 0; i < TOTAL_AMOUNT_OF_CELLS; i++)
	{
		if (board.cells[i].checker.color == black)
		{ 
			FindPossibleWays(board, i, possibleWays, choosenDiagonal);
			if (board.cells[i].checker.isQueen)
			{
				FindPossibleWaysForQueen(board, i, possibleWays, choosenDiagonal); 
			}
			else
			{
				FindPossibleWays(board, i, possibleWays, choosenDiagonal); 
			}
			if (possibleWays.size() > 0)
			{ 
				temp_AI.possibleWays = possibleWays;
				temp_AI.num = i;
				possibleWays_AI.push_back(temp_AI);
				temp_AI.possibleWays.clear();
				temp_AI.num = 0; 
			}
			possibleWays.clear();
		}
	} 
	ChooseAMove_AI(board, possibleWays_AI);
	possibleWays_AI.clear();
}

void PrepareNewCell(BoardStruct &board, int whichChecker, int destanationCell)
{ 
	CheckIsCheckerQueen(board, destanationCell, whichChecker);
	CleanSquaresOutline(board);
	ReplaceChecker(board.cells[destanationCell], board.cells[whichChecker]);
	MakeEmptySquare(board.cells[whichChecker]);
}

ChckerMovement MakeMove_AI(BoardStruct &board, int whichChecker, int destanationCell, bool isAnyKillerWays)
{ 
	int newRow = destanationCell / BOARD_SIZE;
	int newCol = destanationCell - newRow * BOARD_SIZE; 
	ChckerMovement isCheckerMoved = no;
	if (board.cells[destanationCell].isEmpty)
	{
		if (isAnyKillerWays)
		{ 
			PrepareNewCell(board, whichChecker, destanationCell);
			board.cells[destanationCell].checker.shape.setPosition((newCol + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2, (newRow + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2);
			DeleteKilledChecker(board, destanationCell, whichChecker); 
			isCheckerMoved = kill;
		}
		else
		{  
			PrepareNewCell(board, whichChecker, destanationCell);
			board.cells[destanationCell].checker.shape.setPosition((newCol + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2, (newRow + 1) * SQUARE_SIZE + CHECKERS_SIZE / 2);
			isCheckerMoved = setUp;
		}
	}
	return isCheckerMoved;
}

void ChooseAMove_AI(BoardStruct &board, std::vector <AI_MoveWays> possibleWays_AI)
{
	bool isAnyKillWays = false;
	int whichChecker;
	int whichMove;
	std::vector <AI_MoveWays> killerWays;
	std::vector <int> valibleCheckerToMove;
	for (int i = 0; i < possibleWays_AI.size(); i++)
	{
		for (int j = 0; j < possibleWays_AI[i].possibleWays.size(); j++)
		{ 
			if (possibleWays_AI[i].possibleWays[j].isKiller)
			{  
				AI_MoveWays tempKilerWay;
				CheckerWay tempCheckerWay;
				isAnyKillWays = true;  
				tempKilerWay.num = possibleWays_AI[i].num;
				tempCheckerWay.CheckerNum = possibleWays_AI[i].possibleWays[j].CheckerNum;
				tempCheckerWay.isKiller = true;
				tempKilerWay.possibleWays.push_back(tempCheckerWay);
				killerWays.push_back(tempKilerWay);
			}
		}
	}

	if (isAnyKillWays)
	{
		whichChecker = std::rand() % killerWays.size();	 
		whichMove = std::rand() % killerWays[whichChecker].possibleWays.size(); 
		MakeMove_AI(board, killerWays[whichChecker].num, killerWays[whichChecker].possibleWays[whichMove].CheckerNum, isAnyKillWays);
	}
	else
	{		
		for (int i = 0; i < possibleWays_AI.size(); ++i)
		{
			valibleCheckerToMove.push_back(possibleWays_AI[i].num);
		}
		whichChecker = std::rand() % valibleCheckerToMove.size();
		whichMove = std::rand() % possibleWays_AI[whichChecker].possibleWays.size();  
		MakeMove_AI(board, valibleCheckerToMove[whichChecker], possibleWays_AI[whichChecker].possibleWays[whichMove].CheckerNum, isAnyKillWays);
    } 	
}

