#include "Header.h"

int main()
{
	// Set multisampling level
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Checkers", sf::Style::Close, settings);
	BoardStruct m_board;   
	bool isHumanAgainstHuman = false;

	BuildBackground(m_board);
	SetOriginCheckers(m_board);   

	RunMenu(window, isHumanAgainstHuman);
	GameLoop(window, m_board, isHumanAgainstHuman);

	return 0;
}