#include "Header.h" 
 
 
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

void ProcessingWinning(sf::RenderWindow &window, BoardStruct &board, bool &isWhitePlayerWin, bool &gameover, bool &isWhitePlayerTurn)
{ 
	if (board.amountOfBlackCheckers <= 0 || board.amountOfWhiteCheckers <= 0)
	{
		gameover = true;
		DrawCongratulationsText(window, isWhitePlayerWin);
		sf::Event event;
		while (window.pollEvent(event))
		{
			EventWindowClosed(event, window);
			if (event.type == sf::Event::MouseButtonReleased)
			{
				ClearBoard(board);
				BuildBackground(board);
				SetOriginCheckers(board);
				board.amountOfBlackCheckers = 12;
				board.amountOfWhiteCheckers = 12;
				gameover = false;
				isWhitePlayerTurn = true;
			}
		}
	}
}

void GameLoop(sf::RenderWindow &window, BoardStruct &m_board, bool &doPlayGamer)// bool doPlayGamer)
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
		// ������� ������� �������� ���-�� ����� ��� whie no gameover
		if (!gameover)
		{
			sf::Vector2i pixelPos = sf::Mouse::getPosition(window);//�������� ����� �������
			sf::Vector2f positionOfCursor = window.mapPixelToCoords(pixelPos);//��������� �� � ������� (������ �� ����� ����)  
			sf::Event event;
			while (window.pollEvent(event))
			{
				EventWindowClosed(event, window);

				if (event.type == sf::Event::MouseButtonPressed)//���� ������ ������� ����
				{
					if (isWhitePlayerTurn)
					{
						isMove = isCheckerMoving(m_board, whichCheckerCanMove, white, killingChecker, positionOfCursor, possibleWays, deltaPosition);
					}
					else
					{
						if (doPlayGamer)
						{
							isMove = isCheckerMoving(m_board, whichCheckerCanMove, black, killingChecker, positionOfCursor, possibleWays, deltaPosition);
						}
					}
				}
				MouseUpEvent(event, m_board, whichCheckerCanMove, isWhitePlayerTurn, doPlayGamer, isMove, isSetChecker);
			}
			AI_makesMove(m_board, isWhitePlayerTurn, doPlayGamer);
			CheckerFollowCursor(isMove, m_board, whichCheckerCanMove, positionOfCursor, deltaPosition);

			if (isSetChecker)
			{
				isSetChecker = SetCheckerOnBoard(m_board, whichCheckerCanMove, positionOfCursor, possibleWays, killingChecker, isWhitePlayerTurn);
			}
		}
		DrawDeck(m_board, window);
		DrawText(window, isWhitePlayerTurn);
		if (isMove) // ��������� ��������� ����� ������ ���� ���������
		{
			window.draw(m_board.cells[whichCheckerCanMove].checker.shape);
		}
		CheckChampion(m_board, isWhitePlayerWin);
		ProcessingWinning(window, m_board, isWhitePlayerWin, gameover, isWhitePlayerTurn); 

		window.display();
	}
}