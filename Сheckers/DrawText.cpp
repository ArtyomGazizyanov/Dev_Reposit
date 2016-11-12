#include "Header.h"

sf::Font InitFont()
{
	sf::Font font;//шрифт 
	font.loadFromFile("resources/fonts/font.ttf");//передаем нашему шрифту файл шрифта
	return font;
}

sf::Text SetWhichTurnText(sf::Font &font, bool isWhitePlayerTurn)
{
	sf::Text whichTurnText("", font, 25);
	if (isWhitePlayerTurn)
	{
		whichTurnText.setString("White player"); 
		whichTurnText.setFillColor(sf::Color::White);
		whichTurnText.setOutlineColor(sf::Color::Black);
	}
	else
	{
		whichTurnText.setString("Black player"); 
		whichTurnText.setFillColor(sf::Color::Black);
		whichTurnText.setOutlineColor(sf::Color::White);
	} 
	whichTurnText.setStyle(sf::Text::Bold | sf::Text::Underlined);
	whichTurnText.setOutlineThickness(2.0);
	
	return whichTurnText; 
}

sf::Text SetCongratulationsText(sf::Font &font, bool isWhitePlayerWin)
{
	sf::Text CongratulationsText("", font, 50);
	if (isWhitePlayerWin)
	{
		CongratulationsText.setString("White player WIN!");
		CongratulationsText.setFillColor(sf::Color::White);
		CongratulationsText.setOutlineColor(sf::Color::Black);
	}
	else
	{
		CongratulationsText.setString("Black player WIN!");
		CongratulationsText.setFillColor(sf::Color::Black);
		CongratulationsText.setOutlineColor(sf::Color::White);
	}
	CongratulationsText.setStyle(sf::Text::Bold);
	CongratulationsText.setOutlineThickness(2.0);

	return CongratulationsText;
}

void DrawCongratulationsText(sf::RenderWindow &window, bool isWhitePlayerWin)
{
	sf::Font font = InitFont();
	sf::RectangleShape background((sf::Vector2f(SCREEN_WIDTH, SCREEN_HEIGHT)));
	background.setFillColor(CONGRATULATIONS_BACKGROUND_COLOR);
	window.draw(background);

	sf::Text CongratulationsText = SetCongratulationsText(font, isWhitePlayerWin);
	CongratulationsText.setPosition(SCREEN_WIDTH / 2 - 250, SCREEN_HEIGHT/2 );//задаем позицию текста, отступая от центра камеры
	window.draw(CongratulationsText);//рисую этот текст 
}

void DrawText(sf::RenderWindow &window, bool isWhitePlayerTurn)
{
	sf::Font font = InitFont();
	sf::Text WhichTurnText = SetWhichTurnText(font, isWhitePlayerTurn);
	WhichTurnText.setPosition(SCREEN_WIDTH- 200, SCREEN_HEIGHT - 450); 
	window.draw(WhichTurnText); 
}

sf::Text SetTitle(sf::Font &font)
{ 
	sf::Text gameTitle("checkers", font, 55);
	gameTitle.setFillColor(sf::Color::Black);
	gameTitle.setOutlineColor(sf::Color::Red);
	gameTitle.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 250);
	return gameTitle;
}

sf::Text Set2PlayersItem(sf::Font &font)
{
	sf::Text gameTitle("2 players", font, 50);
	gameTitle.setFillColor(sf::Color::Black);
	gameTitle.setOutlineColor(sf::Color::Red);
	gameTitle.setPosition(SCREEN_WIDTH / 2 - 100, SCREEN_HEIGHT / 2 - 50);
	return gameTitle;
}

sf::RectangleShape Set2PlayersItemFrame()
{
	sf::RectangleShape itemsFrame((sf::Vector2f(220, 70)));
	itemsFrame.setPosition(SCREEN_WIDTH / 2 - 110, SCREEN_HEIGHT / 2 - 50);
	itemsFrame.setOutlineColor(BLUE);
	itemsFrame.setFillColor(EMPTY_COLOR);
	itemsFrame.setOutlineThickness(3);

	return itemsFrame;
}

sf::RectangleShape SetVsIAItemFrame()
{
	sf::RectangleShape itemsFrame((sf::Vector2f(320, 70)));
	itemsFrame.setPosition(SCREEN_WIDTH / 2 - 170, SCREEN_HEIGHT / 2 + 50);
	itemsFrame.setOutlineColor(BLUE);
	itemsFrame.setFillColor(EMPTY_COLOR);
	itemsFrame.setOutlineThickness(3);
	return itemsFrame;
}

sf::Text SetVsIAItem(sf::Font &font)
{
	sf::Text gameTitle("vs. computer", font, 50);
	gameTitle.setFillColor(sf::Color::Black);
	gameTitle.setOutlineColor(sf::Color::Red);
	gameTitle.setPosition(SCREEN_WIDTH / 2 - 150, SCREEN_HEIGHT / 2 + 50);
	return gameTitle;
}
 
sf::RectangleShape SetExitItemFrame()
{
	sf::RectangleShape itemsFrame((sf::Vector2f(120, 60)));
	itemsFrame.setPosition(SCREEN_WIDTH / 2 - 50, SCREEN_HEIGHT / 2 + 150);
	itemsFrame.setOutlineColor(BLUE);
	itemsFrame.setFillColor(EMPTY_COLOR);
	itemsFrame.setOutlineThickness(3);
	return itemsFrame;
}

sf::Text SetExitItem(sf::Font &font)
{
	sf::Text gameTitle("exit", font, 50);
	gameTitle.setFillColor(sf::Color::Black);
	gameTitle.setOutlineColor(sf::Color::Red);
	gameTitle.setPosition(SCREEN_WIDTH / 2 - 30, SCREEN_HEIGHT / 2 + 150);
	return gameTitle;
}

void DrawMenu(sf::RenderWindow &window)
{
	sf::Font font = InitFont();
	window.clear(BODY_COLOR);

	sf::Text title = SetTitle(font);
	window.draw(title);

	sf::Text playersItem = Set2PlayersItem(font); 
	window.draw(playersItem); 

	sf::Text vsIAItem = SetVsIAItem(font);
	window.draw(vsIAItem);

	sf::Text exitItem = SetExitItem(font);  
	window.draw(exitItem);
	 
	window.display();
}