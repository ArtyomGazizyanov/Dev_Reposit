#include "Header.h"

//using namespace sf; 

int main()
{
	// Set multisampling level
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Create the window of the application
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Checkers", sf::Style::Close, settings);
	BoardStruct m_board;   
	bool doPlayGamer = NULL;

	BuildBackground(m_board);
	SetOriginCheckers(m_board);   

	RunMenu(window, doPlayGamer);
	GameLoop(window, m_board, doPlayGamer);

	return 0;
}