#pragma once

std::vector <CheckerWay> GetPossibleWays(BoardStruct &board, int whichChecker);
void FindPossibleWays(BoardStruct &board, int whichChecker, std::vector <CheckerWay> &possibleWays, int choosenDiagonal);
void FindPossibleWaysForQueen(BoardStruct &board, int whichChecker, std::vector <CheckerWay> &possibleWays, int choosenDiagonal);
void AddNextCellToPosibleWays(BoardStruct &board, int whichChecker, int startChecker, int &choosenDiagonal, 
	std::vector <CheckerWay> &possibleWays, CheckerWay nextDiagonalCell);