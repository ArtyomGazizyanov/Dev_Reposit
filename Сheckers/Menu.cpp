#include "Header.h"
 
void RunMenu(sf::RenderWindow &window, bool &isHumanAgainstHuman)
{ 
	bool isItemChoosen = false;
	while (window.isOpen() && !isItemChoosen)
	{
		SetMenuEvents(window, isHumanAgainstHuman, isItemChoosen); 
		window.clear(BODY_COLOR); 
		DrawMenu(window);
	}
}