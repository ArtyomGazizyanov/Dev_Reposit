//main.cpp - Entery point to the aplication
// 
#define _USE_MATH_DEFINES
#include "stdafx.h"
#include "Consts.h"
#include <math.h>
#include "Animations.h"



unsigned int currAnimation = 0;

using namespace sf;

struct Blocks
{
	RectangleShape rectangles[AMOUNT_OF_RECTANGLES];
	Vector2f currSize;
	Color currColor;
	float currRotation;
};
 
void initializeBlocks(Blocks &blocks)
{
	blocks.currSize = Vector2f(SQUARE_WIDTH, SQUARE_HEIGHT);
	blocks.currRotation = blocks.rectangles[0].getRotation();
	blocks.currColor = DEFAULT_COLOR;
	for (unsigned i = 0; i < AMOUNT_OF_RECTANGLES; ++i)
	{
		blocks.rectangles[i].setSize(blocks.currSize);
		blocks.rectangles[i].setFillColor(blocks.currColor);
		blocks.rectangles[i].setOrigin(SQUARE_WIDTH / 2, SQUARE_HEIGHT / 2);
		blocks.rectangles[i].setPosition(START_LEFT_POSITION + blocks.rectangles[i].getOrigin().x, ((SQUARE_HEIGHT + DISTANCE_BETWEN_SQUARES) * i) + START_TOP_POSITION + blocks.rectangles[i].getOrigin().y);
	}
}

void drawRectangles(RenderWindow &window, RectangleShape *rectangles)
{
	for (unsigned i = 0; i < AMOUNT_OF_RECTANGLES; ++i)
	{
		window.draw(rectangles[i]);
	}
}

float degreesToRads(float degrees)
{
	return degrees * M_PI / 180;
} 

void rotateBlocksASync(Blocks &blocks)
{
	if (blocks.currRotation != ANIMATIONS[currAnimation]["ROTATION"]["TO"])
	{  
		if (blocks.currRotation > ANIMATIONS[currAnimation]["ROTATION"]["TO"])
		{
			blocks.currRotation -= SPEED_ROTATION;
			 
		}
		else if (blocks.currRotation < ANIMATIONS[currAnimation]["ROTATION"]["TO"])
		{
			blocks.currRotation += SPEED_ROTATION;
			 
		}
		int middleSquare = AMOUNT_OF_RECTANGLES / 2 - 1;
		for (int i = 0; i < AMOUNT_OF_RECTANGLES; i++)
		{

			float dx = blocks.rectangles[i].getPosition().x - blocks.rectangles[0].getPosition().x;
			float dy = blocks.rectangles[i].getPosition().y - blocks.rectangles[0].getPosition().y ;
			float distance = hypot(dx, dy);
			blocks.rectangles[i].setPosition(
				(distance * sin(degreesToRads(blocks.currRotation))) + blocks.rectangles[0].getPosition().x,// ,
				(distance * cos(degreesToRads(blocks.currRotation))) + blocks.rectangles[0].getPosition().y);//);// 200000000*i * ANIMATIONS[currAnimation]["DICTANCE"]["TO"]);
			if(i % 2 == 0)
				blocks.rectangles[i].setRotation(-blocks.currRotation);
			else
				blocks.rectangles[i].setRotation(blocks.currRotation);
		}
	} 
	
}

void update(RenderWindow &window, RectangleShape *rectangles)
{
	window.clear(Color::White);
	drawRectangles(window, rectangles);
	window.display();
}

void reMoveBlocksAndReColor(Blocks &blocks)
{
	for (int i = 0; i < AMOUNT_OF_RECTANGLES; ++i)
	{
		blocks.rectangles[i].setPosition(blocks.rectangles[i].getPosition().x + (i * ANIMATIONS[currAnimation]["DISTANCE"]["TO"])  + ANIMATIONS[currAnimation]["SPEED"]["X"],
			blocks.rectangles[i].getPosition().y + (i * ANIMATIONS[currAnimation]["DISTANCE"]["TO"]) + ANIMATIONS[currAnimation]["SPEED"]["Y"]);
		blocks.rectangles[i].setFillColor(blocks.currColor);
	}
}

void updateBlockColor(Uint8 &currentColor, const string &colorStr)
{
	if ((int)(currentColor) < ANIMATIONS[currAnimation][colorStr]["TO"])
	{
		currentColor = Uint8((int)(currentColor) + SPEED_COLOR);
	}
	else if ((int)(currentColor) > ANIMATIONS[currAnimation][colorStr]["TO"])
	{
		currentColor = Uint8((int)(currentColor) - SPEED_COLOR);
	}
}
void updateBlocksColors(Blocks &blocks)
{
	updateBlockColor(blocks.currColor.r, "RED");
	updateBlockColor(blocks.currColor.g, "GREEN");
	updateBlockColor(blocks.currColor.b, "BLUE");
	updateBlockColor(blocks.currColor.a, "OPACITY");
}

void UpdateSquareWidth(float &squareWidth)
{
	if (squareWidth < ANIMATIONS[currAnimation]["WIDTH"]["TO"])
	{ 
		squareWidth += SPEED_SIZE;
	}
	else if (squareWidth > ANIMATIONS[currAnimation]["WIDTH"]["TO"])
	{ 
		squareWidth -= SPEED_SIZE;
	}
}

void UpdateSquareHeight(float &squareHeight)
{
	if (squareHeight < ANIMATIONS[currAnimation]["HEIGHT"]["TO"])
	{
		squareHeight += SPEED_SIZE;
	}
	else if (squareHeight > ANIMATIONS[currAnimation]["HEIGHT"]["TO"])
	{
		squareHeight -= SPEED_SIZE;
	}
}

void updateBlocksSize(Blocks &blocks, Vector2f &blockSize)
{
	if (blockSize.x != ANIMATIONS[currAnimation]["WIDTH"]["TO"] || blockSize.y != ANIMATIONS[currAnimation]["HEIGHT"]["TO"])
	{  
			for (int i = 0; i < AMOUNT_OF_RECTANGLES; ++i)	
			{
				UpdateSquareWidth(blockSize.x);
				UpdateSquareHeight(blockSize.y); 
	
				blocks.rectangles[i].setPosition(blocks.rectangles[i].getPosition().x,
					((blocks.currSize.y + DISTANCE_BETWEN_SQUARES + ANIMATIONS[currAnimation]["DISTANCE"]["TO"])) * i + blocks.rectangles[0].getPosition().y);
				blocks.rectangles[i].setSize(blockSize);
			} 
		}
}

void updateBlocks(Blocks &blocks)
{
	updateBlocksColors(blocks);
	rotateBlocksASync(blocks);
	updateBlocksSize(blocks, blocks.currSize);
	reMoveBlocksAndReColor(blocks); 
}

bool doBlocksMeetAWall(Blocks blocks)
{
	double topRectanglePositionX = blocks.rectangles[0].getPosition().x + ANIMATIONS[currAnimation]["SPEED"]["X"];
	double topRectanglePositionY = blocks.rectangles[0].getPosition().y + ANIMATIONS[currAnimation]["SPEED"]["Y"];
	double bottomRectanglePositionX = blocks.rectangles[AMOUNT_OF_RECTANGLES - 1].getPosition().x + ANIMATIONS[currAnimation]["SPEED"]["X"];
	double bottomRectanglePositionY = blocks.rectangles[AMOUNT_OF_RECTANGLES - 1].getPosition().y + ANIMATIONS[currAnimation]["SPEED"]["Y"]; 

	if((   ((topRectanglePositionX - SQUARE_WIDTH / 2 < 0) || (topRectanglePositionX + SQUARE_WIDTH / 2 > SCREEN_WIDTH)) 
		|| ((topRectanglePositionY - SQUARE_HEIGHT / 2 < 0) || (topRectanglePositionY + SQUARE_HEIGHT / 2 > SCREEN_HEIGHT))) 
		|| (((bottomRectanglePositionX - SQUARE_WIDTH / 2 < 0) || (bottomRectanglePositionX + SQUARE_WIDTH / 2 > SCREEN_WIDTH))
	    || ((bottomRectanglePositionY - SQUARE_HEIGHT / 2 < 0) || (bottomRectanglePositionY + SQUARE_HEIGHT / 2 > SCREEN_HEIGHT))))
	{
		return true;
	} 

	return false;
}

void DoAnimation(RenderWindow &window, Blocks &blocks)
{
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (currAnimation < ANIMATIONS.size())
		{
			updateBlocks(blocks);
		}
		if((currAnimation + 1 <= ANIMATIONS.size()) && (doBlocksMeetAWall(blocks)))
		{ 
			currAnimation++;
		}
		else
			if (currAnimation == ANIMATIONS.size())
			{
				currAnimation = 0;
			}

		update(window, blocks.rectangles);
	}
}

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	 
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Sfml Animation", Style::Close, settings);


	Blocks blocks;
	initializeBlocks(blocks);

	DoAnimation(window, blocks);
	return 0;
}