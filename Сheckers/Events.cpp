#include "Header.h"

void EventWindowClosed(sf::Event event, sf::RenderWindow &window)
{
	if (event.type == sf::Event::Closed)
		window.close();
}
 
void MouseUpEvent(sf::Event event, BoardStruct &board, int whichCheckerCanMove, bool isWhitePlayerTurn, bool isHumanAgainstHuman, bool &isMove, bool &isSetChecker)
{
	if ((event.type == sf::Event::MouseButtonReleased) && (board.cells[whichCheckerCanMove].isEnableToPlay && (isWhitePlayerTurn || isHumanAgainstHuman)))//если отпустили клавишу
	{ 
		isMove = false;
		isSetChecker = true;
	}
}

void EventClickOnTwoPlayersMenuItem(sf::RenderWindow &window, bool &isHumanAgainstHuman, bool &isItemChoosen)
{ 
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			isHumanAgainstHuman = true; 
			isItemChoosen = true;
		}
	}
}

void EventClickOnVsAIMenuItem(sf::RenderWindow &window, bool &isHumanAgainstHuman, bool &isItemChoosen)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			isHumanAgainstHuman = false;
			isItemChoosen = true; 
		}
	}
}

void EventClickOnExitItem(sf::RenderWindow &window, bool &isHumanAgainstHuman, bool &isItemChoosen)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::MouseButtonReleased)
		{
			window.close();
		}
	}
}



void EventFocusOnTwoPlayersMenuItem(sf::RenderWindow &window, bool &isHumanAgainstHuman, bool &isItemChoosen)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//забираем коорд курсора
	sf::Vector2f positionOfCursor = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)  
	sf::RectangleShape twoPlayersItemFrame = Set2PlayersItemFrame(); 
	while (twoPlayersItemFrame.getGlobalBounds().contains(positionOfCursor.x, positionOfCursor.y))
	{ 
		if (twoPlayersItemFrame.getGlobalBounds().contains(positionOfCursor.x, positionOfCursor.y))
		{
			EventClickOnTwoPlayersMenuItem(window, isHumanAgainstHuman, isItemChoosen);
			window.draw(twoPlayersItemFrame);
			window.display();
		}
		pixelPos = sf::Mouse::getPosition(window);
		positionOfCursor = window.mapPixelToCoords(pixelPos); 
	}
}


void EventFocusOnVsAIMenuItem(sf::RenderWindow &window, bool &isHumanAgainstHuman, bool &isItemChoosen)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//забираем коорд курсора
	sf::Vector2f positionOfCursor = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)  
	sf::RectangleShape vsAIItemFrame = SetVsIAItemFrame();
	while (vsAIItemFrame.getGlobalBounds().contains(positionOfCursor.x, positionOfCursor.y))
	{
		if (vsAIItemFrame.getGlobalBounds().contains(positionOfCursor.x, positionOfCursor.y))
		{
			EventClickOnVsAIMenuItem(window, isHumanAgainstHuman, isItemChoosen);
			window.draw(vsAIItemFrame);
			window.display();
		}
		pixelPos = sf::Mouse::getPosition(window);
		positionOfCursor = window.mapPixelToCoords(pixelPos);
	}
}

void EventFocusOnExitMenuItem(sf::RenderWindow &window, bool &isHumanAgainstHuman, bool &isItemChoosen)
{
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//забираем коорд курсора
	sf::Vector2f positionOfCursor = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)  
	sf::RectangleShape exitItemFrame = SetExitItemFrame();
	while (exitItemFrame.getGlobalBounds().contains(positionOfCursor.x, positionOfCursor.y))
	{
		if (exitItemFrame.getGlobalBounds().contains(positionOfCursor.x, positionOfCursor.y))
		{
			EventClickOnExitItem(window, isHumanAgainstHuman, isItemChoosen);
			window.draw(exitItemFrame);
			window.display();
		}
		pixelPos = sf::Mouse::getPosition(window);
		positionOfCursor = window.mapPixelToCoords(pixelPos);
	}
}
 
void SetMenuEvents(sf::RenderWindow &window, bool &isHumanAgainstHuman, bool &isItemChoosen)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		EventWindowClosed(event, window);

		EventFocusOnTwoPlayersMenuItem(window, isHumanAgainstHuman, isItemChoosen);
		EventFocusOnVsAIMenuItem(window, isHumanAgainstHuman, isItemChoosen);
		EventFocusOnExitMenuItem(window, isHumanAgainstHuman, isItemChoosen);
	}
}


void CheckerFollowCursor(bool isMove, BoardStruct &board, int whichCheckerCanMove, sf::Vector2f positionOfCursor, sf::Vector2f deltaPosition)
{
	if (isMove)
	{
		board.cells[whichCheckerCanMove].checker.shape.setPosition(positionOfCursor.x - deltaPosition.x, positionOfCursor.y - deltaPosition.y);
	}
}

void CheckChampion(BoardStruct &board, bool &isWhitePlayerWin)
{
	if (board.amountOfBlackCheckers == 0)
	{
		isWhitePlayerWin = true;
	}
	else
		if (board.amountOfWhiteCheckers == 0)
		{
			isWhitePlayerWin = false;
		}
}