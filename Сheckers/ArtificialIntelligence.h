#pragma once

void CheckAllWays_AI(BoardStruct &board);
void ChooseAMove_AI(BoardStruct &board, std::vector <AI_MoveWays> possibleWays); 
ChckerMovement MakeMove_AI(BoardStruct &board, int whichChecker, int destanationCell, bool isAnyKillerWays);
void PrepareNewCell(BoardStruct &board, int whichChecker, int destanationCell); 
void AI_makesMove(BoardStruct &board, bool &isWhitePlayerTurn, bool doPlayGamer);