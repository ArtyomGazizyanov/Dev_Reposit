#pragma once

void ClearBoard(BoardStruct &board);
void SetOriginCheckers(BoardStruct &board);  
void SetOriginSettingsOfChecker(Checker &checker);
void BuildBackground(BoardStruct &board); 
void DeleteChecker(Checker &checker);
Checker CopyChecker(Checker &checker);
void  ReplaceChecker(MySquare &destinationSquare, MySquare &donorSquare); 
void DeleteKilledChecker(BoardStruct &board, int const &newCheckerNum, int const &whichChecker);
void MakeEmptySquare(MySquare &cell);
ChckerMovement SetChoosenCheckerToThePosition(BoardStruct &board, int whichChecker, sf::Vector2f position, std::vector <CheckerWay> possibleWay);
void changeCheckertoQueen(Checker &checker, CheckerColor const &checkerColor);
void CheckIsCheckerQueen(BoardStruct &board, int newCheckerNum, int whichChecker);
sf::Vector2f GrabTheChecker(BoardStruct &board, int currChecker, int &whichCheckerCanMove, sf::Vector2f positionOfCursor,
	std::vector <CheckerWay> &possibleWays);
bool isCheckerMoving(BoardStruct &board, int &whichCheckerCanMove, CheckerColor checkerColor, int killingChecker, sf::Vector2f positionOfCursor,
	std::vector <CheckerWay> &possibleWays, sf::Vector2f &deltaPosition);
bool  SetCheckerOnBoard(BoardStruct &board, int whichCheckerCanMove, sf::Vector2f positionOfCursor,
	std::vector <CheckerWay> &possibleWays, int &killingChecker, bool &isWhitePlayerTurn);