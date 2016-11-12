#pragma once

#include "stdafx.h"
#include "Consts.h"

using namespace std;

vector<map<string, map<string, float>>> ANIMATIONS =
{
	{ //1
		{ "SPEED",{ { "X", SPEED_X * 3 },{ "Y", 0 } } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT/2 } } },
		{ "DISTANCE",{ { "TO", 0 } } },
		{ "RED",{ { "TO", 0 } } },
		{ "GREEN",{ { "TO", 0 } } },
		{ "BLUE",{ { "TO", 100 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 0 } } }
	},
	{//2
		{ "SPEED",{ { "X", -SPEED_X * 2},{ "Y", SPEED_Y * 5} } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH/2 } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", 0 } } },
		{ "RED",{ { "TO", 0 } } },
		{ "GREEN",{ { "TO", 100 } } },
		{ "BLUE",{ { "TO", 0 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 0 } } }
	},
	{//3
		{ "SPEED",{ { "X", SPEED_X/3},{ "Y", 0 } } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT } } },
		{ "DISTANCE",{ { "TO",  0 } } },
		{ "RED",{ { "TO", 0 } } },
		{ "GREEN",{ { "TO", 100 } } },
		{ "BLUE",{ { "TO", 0 } } },
		{ "OPACITY",{ { "TO", 100 } } },
		{ "ROTATION",{ { "TO", 90 } } }
	},
	{//4
		{ "SPEED",{ { "X", -SPEED_X / 10 },{ "Y", SPEED_Y * 10} } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH} } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", -SPEED_OF_CHANGING_DISTANCE * 3} } },
		{ "RED",{ { "TO", 180 } } },
		{ "GREEN",{ { "TO", 180 } } },
		{ "BLUE",{ { "TO", 0 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 90} } }
	},
	{//5
		{ "SPEED",{ { "X", 0 },{ "Y", -SPEED_Y * 6} } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", SPEED_OF_CHANGING_DISTANCE*0.8 } } },
		{ "RED",{ { "TO", 50 } } },
		{ "GREEN",{ { "TO", 0 } } },
		{ "BLUE",{ { "TO", 192 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 0 } } }
	} 
};