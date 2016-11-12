#pragma once

void EventWindowClosed(sf::Event event, sf::RenderWindow &window);
void MouseUpEvent(sf::Event event, BoardStruct &board, int whichCheckerCanMove, bool isWhitePlayerTurn, bool isHumanAgainstHuman, bool &isMove, bool &isSetChecker);
/*void EventFocusOnTwoPlayersMenuItem(RenderWindow &window, bool &isHumanAgainstHuman);
void EventFocusOnVsAIMenuItem(RenderWindow &window, bool &isHumanAgainstHuman);
void EventFocusOnExitMenuItem(RenderWindow &window, bool &isHumanAgainstHuman);*/
void SetMenuEvents(sf::RenderWindow &window, bool &isHumanAgainstHuman, bool &isItemChoosen);
void CheckerFollowCursor(bool isMove, BoardStruct &board, int whichCheckerCanMove, sf::Vector2f positionOfCursor, sf::Vector2f deltaPosition);
void CheckChampion(BoardStruct &board, bool &isWhitePlayerWin);