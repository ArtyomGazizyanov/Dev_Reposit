#pragma once

sf::Font InitFont();
void DrawText(sf::RenderWindow &window, bool isWhitePlayerTurn);
void DrawCongratulationsText(sf::RenderWindow &window, bool isWhitePlayerWin);
void DrawMenu(sf::RenderWindow &window);
sf::RectangleShape Set2PlayersItemFrame();
sf::RectangleShape SetVsIAItemFrame();
sf::RectangleShape SetExitItemFrame();