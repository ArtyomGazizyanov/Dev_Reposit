#include "Header.h"
 
void RunMenu(sf::RenderWindow &window, bool &doPlayGamer)
{ 
	bool isItemChoosen = false;
	while (window.isOpen() && !isItemChoosen)
	{
		SetMenuEvents(window, doPlayGamer, isItemChoosen); 
		window.clear(BODY_COLOR); 
		DrawMenu(window);
	}
}