#pragma once

#include "stdafx.h"
#include "Consts.h"

using namespace std;

vector<map<string, map<string, float>>> ANIMATIONS =
{
	/*{ 
		{ "SPEED",{ { "X", SPEED_X * 3 },{ "Y", 0 } } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT/4 } } },
		{ "DISTANCE",{ { "TO", 0 } } },
		{ "RED",{ { "TO", 0 } } },
		{ "GREEN",{ { "TO", 0 } } },
		{ "BLUE",{ { "TO", 100 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 0 } } }
	},
	{
		{ "SPEED",{ { "X", -SPEED_X * 2},{ "Y", SPEED_Y * 4} } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", 0} } },
		{ "RED",{ { "TO", 0 } } },
		{ "GREEN",{ { "TO", 100 } } },
		{ "BLUE",{ { "TO", 0 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 0 } } }
	},*/
	{
		{ "SPEED",{ { "X", SPEED_X / 3 },{ "Y", 0 } } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", 0} } },
		{ "RED",{ { "TO", 0 } } },
		{ "GREEN",{ { "TO", 100 } } },
		{ "BLUE",{ { "TO", 0 } } },
		{ "OPACITY",{ { "TO", 100 } } },
		{ "ROTATION",{ { "TO", 90 } } }
	},
	{
		{ "SPEED",{ { "X", 0 },{ "Y", SPEED_Y * 2} } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT } } },
		{ "DISTANCE",{ { "TO",0} } },
		{ "RED",{ { "TO", 200 } } },
		{ "GREEN",{ { "TO", 0 } } },
		{ "BLUE",{ { "TO", 0 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 90} } }
	},
	/*{
		{ "SPEED",{ { "X", 0 },{ "Y", -SPEED_Y * 4 } } },
		{ "WIDTH",{ { "TO", SQUARE_WIDTH } } },
		{ "HEIGHT",{ { "TO", SQUARE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", 0 } } },
		{ "RED",{ { "TO", 200 } } },
		{ "GREEN",{ { "TO", 0 } } },
		{ "BLUE",{ { "TO", 0 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 0 } } }
	}*/
	/*{
		{ "SPEED",{ { "X", 0 },{ "Y", SPEED_Y } } },
		{ "WIDTH",{ { "TO", RECTANGLE_WIDTH / 5 } } },
		{ "HEIGHT",{ { "TO", RECTANGLE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", 0.01 } } },
		{ "COLOR_RED",{ { "TO", 0 } } },
		{ "COLOR_GREEN",{ { "TO", 100 } } },
		{ "COLOR_BLUE",{ { "TO", 200 } } },
		{ "OPACITY",{ { "TO", 255 } } },
		{ "ROTATION",{ { "TO", 0 } } }
	},
	{
		{ "SPEED",{ { "X", -SPEED_X },{ "Y", -SPEED_Y } } },
		{ "WIDTH",{ { "TO", RECTANGLE_WIDTH } } },
		{ "HEIGHT",{ { "TO", RECTANGLE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", 0.01 } } },
		{ "COLOR_RED",{ { "TO", 100 } } },
		{ "COLOR_GREEN",{ { "TO", 0 } } },
		{ "COLOR_BLUE",{ { "TO", 20 } } },
		{ "OPACITY",{ { "TO", 200 } } },
		{ "ROTATION",{ { "TO", 0 } } }
	},
	{
		{ "SPEED",{ { "X", 0 },{ "Y", 0 } } },
		{ "WIDTH",{ { "TO", RECTANGLE_WIDTH } } },
		{ "HEIGHT",{ { "TO", RECTANGLE_HEIGHT } } },
		{ "DISTANCE",{ { "TO", 0.01 } } },
		{ "COLOR_RED",{ { "TO", 100 } } },
		{ "COLOR_GREEN",{ { "TO", 0 } } },
		{ "COLOR_BLUE",{ { "TO", 20 } } },
		{ "OPACITY",{ { "TO", 200 } } },
		{ "ROTATION",{ { "TO", 90 } } }
	}*/
};