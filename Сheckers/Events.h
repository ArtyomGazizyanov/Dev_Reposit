#pragma once

void EventWindowClosed(sf::Event event, sf::RenderWindow &window);
void MouseUpEvent(sf::Event event, BoardStruct &board, int whichCheckerCanMove, bool isWhitePlayerTurn, bool doPlayGamer, bool &isMove, bool &isSetChecker);
/*void EventFocusOnTwoPlayersMenuItem(RenderWindow &window, bool &doPlayGamer);
void EventFocusOnVsAIMenuItem(RenderWindow &window, bool &doPlayGamer);
void EventFocusOnExitMenuItem(RenderWindow &window, bool &doPlayGamer);*/
void SetMenuEvents(sf::RenderWindow &window, bool &doPlayGamer, bool &isItemChoosen);
void CheckerFollowCursor(bool isMove, BoardStruct &board, int whichCheckerCanMove, sf::Vector2f positionOfCursor, sf::Vector2f deltaPosition);