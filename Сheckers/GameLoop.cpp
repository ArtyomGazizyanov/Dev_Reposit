#include "Header.h" 
 
void GameLoop(sf::RenderWindow &window, BoardStruct &m_board, bool &isHumanAgainstHuman)// bool isHumanAgainstHuman)
{
	bool isMove = false;
	bool gameover = false;
	bool isSetChecker = false;
	bool isWhitePlayerTurn = true;
	bool isWhitePlayerWin = false;
	std::vector <CheckerWay> possibleWays;
	sf::Vector2f deltaPosition;
	sf::Vector2f XYMouseMove(0, 0);
	int whichCheckerCanMove = 0;
	int killingChecker = 0;

	while (window.isOpen())
	{
		// сделать условие проверки кол-ва шашек или whie no gameover
		if (!gameover)
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//забираем коорд курсора
			sf::Vector2f positionOfCursor = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)  
			sf::Event event;
			while (window.pollEvent(event))
			{
				EventWindowClosed(event, window);

				if (event.type == sf::Event::MouseButtonPressed)//если нажата клавиша мыши
				{
					if (isWhitePlayerTurn)
					{
						isMove = isCheckerMoving(m_board, whichCheckerCanMove, white, killingChecker, positionOfCursor, possibleWays, deltaPosition);
					}
					else if (isHumanAgainstHuman)
					{
						isMove = isCheckerMoving(m_board, whichCheckerCanMove, black, killingChecker, positionOfCursor, possibleWays, deltaPosition);
					}					
				}
				MouseUpEvent(event, m_board, whichCheckerCanMove, isWhitePlayerTurn, isHumanAgainstHuman, isMove, isSetChecker);
			}
			AI_makesMove(m_board, isWhitePlayerTurn, isHumanAgainstHuman);
			CheckerFollowCursor(isMove, m_board, whichCheckerCanMove, positionOfCursor, deltaPosition);

			if (isSetChecker)
			{
				isSetChecker = SetCheckerOnBoard(m_board, whichCheckerCanMove, positionOfCursor, possibleWays, killingChecker, isWhitePlayerTurn);
			}
		}
		DrawDeck(m_board, window);
		DrawText(window, isWhitePlayerTurn);
		DrawChoosenChecker(m_board, window, isMove, whichCheckerCanMove);
		if (isMove) // отрисовка выбранной шашки поверх всех остальных
		{
			window.draw(m_board.cells[whichCheckerCanMove].checker.shape);
		}
		CheckChampion(m_board, isWhitePlayerWin);
		ProcessingWinning(window, m_board, isWhitePlayerWin, gameover, isWhitePlayerTurn); 

		window.display();
	}
}