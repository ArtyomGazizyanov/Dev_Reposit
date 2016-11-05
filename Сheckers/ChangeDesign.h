#pragma once

void DrawDeck(BoardStruct &board, sf::RenderWindow& window);
void SetOriginOutlineColorSquare(MySquare &thisSquare);
void ColorChoosenChecker(BoardStruct &board, int whichChecker);
void CleanSquaresOutline(BoardStruct &board);
void ColorSqures(BoardStruct &board, std::vector <CheckerWay> &possibleWay); 
void DrawBackground(sf::RenderWindow &window);