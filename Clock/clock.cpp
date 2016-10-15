
////////////////////////////////////////////////////////////
// Headers:
// ctime for getting system time and
// cmath for sin and cos functions
////////////////////////////////////////////////////////////

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <ctime>
#include <cmath>
#include "Consts.h"
#include <iostream>
 
////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////

using namespace sf;

struct ClockCharacteristics
{
	Texture clockBrand;
	Texture clockBackground;
	Music SoundOfTick;
};

struct ClockHands
{
	 RectangleShape hourHand;
	RectangleShape minuteHand;
	RectangleShape secondsHand;
};

struct ClockSystem
{
	Font font;
	Text num[NUMBER_DIGITS];
	CircleShape dot[NUMBER_DOTS];
	Sprite clockBrandSprite;
	CircleShape clockCircle;
	CircleShape centerCircle;
	ClockHands clockHand;
	ClockCharacteristics clockSettings;
};

Vector2f GetReCalculatePosition(float angle, int offset)
{
	return Vector2f((CLOCK_CIRCLE_SIZE - offset) * cos(angle), (CLOCK_CIRCLE_SIZE - offset) * sin(angle));
}

bool IsGetFont(ClockSystem &clock)
{
	return (clock.font.loadFromFile("resources/cool.ttf"));
}

void SetDigitsStyle(int digit, ClockSystem &clock)
{ 
		clock.num[digit].setFont(clock.font);
		clock.num[digit].setFillColor(Color::Black);
		clock.num[digit].setStyle(Text::Bold);
		clock.num[digit].setCharacterSize(38); 
}

//CreateDigit
void CreateDigitPosition(int i, ClockSystem &clock , float angle, Vector2f windowCenter)
{
	int digit = i / 5; 
	 
   SetDigitsStyle(digit, clock);

	clock.num[digit].setString(std::to_string(digit + 1));

	Vector2f digitPosition = GetReCalculatePosition(angle, DISTANCE_FROM_CIRCLE);
	Vector2f positionText(digitPosition + windowCenter); 
	clock.num[digit].setPosition(positionText.x, positionText.y - clock.num[digit].getGlobalBounds().height / 2.0f);

	clock.num[digit].setOrigin(clock.num[digit].getGlobalBounds().width / 2.0f,
	clock.num[digit].getGlobalBounds().height / 2.0f);
}

// Create dots and place them to very right positions
void CreateSymbolsPostition(ClockSystem &clock, Vector2f windowCenter)
{
	float x, y;
	float angle = BEGINING_ANGLE;
	for (int i = 0; i < 60; i++)
	{
		x = (CLOCK_CIRCLE_SIZE - 10) * cos(angle);
		y = (CLOCK_CIRCLE_SIZE - 10) * sin(angle);
		if (i % 5 == 0)
		{
			clock.dot[i] = CircleShape(3);
			CreateDigitPosition(i, clock, angle, windowCenter);
		}
		else
		{
			clock.dot[i] = CircleShape(1);
		}
		clock.dot[i].setFillColor(Color::Black);
		clock.dot[i].setOrigin(clock.dot[i].getGlobalBounds().width / 2, clock.dot[i].getGlobalBounds().height / 2);
		clock.dot[i].setPosition(x + windowCenter.x, y + windowCenter.y);

		angle += ((PI * 2) / 60);
	}
} 

//Create outline of the clock
void CreateClocksOutline(CircleShape& clockCircle, Vector2f& windowCenter)
{
	clockCircle.setRadius(CLOCK_CIRCLE_SIZE);
	clockCircle.setPointCount(100);
	clockCircle.setOutlineThickness(CLOCK_CIRCLE_THICKNESS);
	clockCircle.setOutlineColor(Color::Black);
	clockCircle.setOrigin(clockCircle.getGlobalBounds().width / 2.0f, clockCircle.getGlobalBounds().height / 2.0f);
	clockCircle.setPosition(windowCenter.x + CLOCK_CIRCLE_THICKNESS, windowCenter.y + CLOCK_CIRCLE_THICKNESS); 
	clockCircle.setTextureRect(IntRect(40, 0, 900, 900)); 
}

// Crate another circle for center
void CreateClocksCenterCircle(CircleShape& centerCircle, const Vector2f& windowCenter)
{
	centerCircle.setRadius(CLOCK_CENTER_CIRCLE_SIZE);
	centerCircle.setPointCount(100);
	centerCircle.setFillColor(Color::Red);
	centerCircle.setOrigin(centerCircle.getGlobalBounds().width / 2, centerCircle.getGlobalBounds().height / 2);
	centerCircle.setPosition(windowCenter);
}

// Create hour, minute, and seconds hands
void SetHandsOrigins(RectangleShape& Hand)
{ 
	Hand.setOrigin(Hand.getGlobalBounds().width / 2, Hand.getGlobalBounds().height - 25);
}

void PaintClocksHands(ClockSystem &clock)
{
	clock.clockHand.hourHand.setFillColor(Color::Black);
	clock.clockHand.minuteHand.setFillColor(Color::Black);
	clock.clockHand.secondsHand.setFillColor(Color::Red);
}

void SetClockHands(ClockSystem &clock, Vector2f windowCenter)
{
	clock.clockHand.hourHand.setSize(Vector2f(5, 180));
	clock.clockHand.minuteHand.setSize(Vector2f(3, 240));
	clock.clockHand.secondsHand.setSize(Vector2f(2, 250)); 

	SetHandsOrigins(clock.clockHand.hourHand);
	SetHandsOrigins(clock.clockHand.minuteHand);
	SetHandsOrigins(clock.clockHand.secondsHand);

	clock.clockHand.hourHand.setPosition(windowCenter);
	clock.clockHand.minuteHand.setPosition(windowCenter);
	clock.clockHand.secondsHand.setPosition(windowCenter);
}

void DrawClockHands(ClockSystem &clock, RenderWindow &window)
{
	window.draw(clock.clockHand.hourHand);
	window.draw(clock.clockHand.minuteHand);
	window.draw(clock.clockHand.secondsHand);
}

void SetHandsRotationAccordingTime(ClockSystem &clock)
{
	// Get system time
	std::time_t currentTime = std::time(NULL);

	struct tm * ptm = localtime(&currentTime);

	clock.clockHand.hourHand.setRotation(ptm->tm_hour * 30 + (ptm->tm_min / 2));
	clock.clockHand.minuteHand.setRotation(ptm->tm_min * 6 + (ptm->tm_sec / 12));
	clock.clockHand.secondsHand.setRotation(ptm->tm_sec * 6);
} 

void CreateBrand(ClockSystem &clock, Vector2f windowCenter)
{ 
	if (clock.clockSettings.clockBrand.loadFromFile(LOGO_FILE_WAY))
	{
		Sprite clockBrandSprite;
		clock.clockBrandSprite.setTexture(clock.clockSettings.clockBrand);
		clock.clockBrandSprite.setOrigin(clockBrandSprite.getTextureRect().left + clockBrandSprite.getTextureRect().width / 2.0f,
		clock.clockBrandSprite.getTextureRect().top + clockBrandSprite.getTextureRect().height / 2.0f);
		clock.clockBrandSprite.setPosition(windowCenter.x - 47, windowCenter.y + 132);
	}
}
 
void DrawClock(ClockSystem &clock, RenderWindow& window)
{
	// Clear the window
	window.clear(Color::White);

	// Draw all parts of clock
	window.draw(clock.clockCircle);
	window.draw(clock.clockBrandSprite);

	for (int i = 0; i < 60; i++)
	{
		window.draw(clock.dot[i]);
		if (i % 5 == 0)
		{
			window.draw(clock.num[i / 5]);
		} 
	} 
	DrawClockHands(clock, window);
	window.draw(clock.centerCircle);
}

void SetTicking(ClockSystem &clock)
{
	if (clock.clockSettings.SoundOfTick.openFromFile(TICKING_SOUND_FILE_WAY))
	{
		clock.clockSettings.SoundOfTick.setLoop(true);
		clock.clockSettings.SoundOfTick.play();
	}
}

void CreateBackground(ClockSystem &clock)
{
	if (clock.clockSettings.clockBackground.loadFromFile(BACKGROUND_FILE_WAY))
	{
		clock.clockCircle.setTexture(&clock.clockSettings.clockBackground);
		clock.clockCircle.setTextureRect(IntRect(40, 0, 500, 500));
	}
}

void CreateClock(ClockSystem &clock, Vector2f windowCenter)
{  
	if (IsGetFont(clock))
	{
		CreateSymbolsPostition(clock, windowCenter);
	}
	CreateClocksOutline(clock.clockCircle, windowCenter);
	CreateClocksCenterCircle(clock.centerCircle, windowCenter);
	SetClockHands(clock, windowCenter);
	PaintClocksHands(clock);
	CreateBrand(clock, windowCenter);
	CreateBackground(clock);
}


int main()
{
	// Set multisampling level
	ContextSettings settings;
	settings.antialiasingLevel = 8;

	// Create the window of the application
	RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Analog Clock", Style::Close, settings);

	// Define windowCenter which gets the center of the window here, right after creating window
	Vector2f windowCenter = Vector2f(window.getSize().x / 2.0f, window.getSize().y / 2.0f);

	// Create a list for clock's dots
	ClockSystem clock;	
	
	CreateClock(clock, windowCenter);
	SetTicking(clock);
	 
	while (window.isOpen())
	{
		// Handle events
		Event event;
		while (window.pollEvent(event))
		{
			// Window closed: exit
			if (event.type == Event::Closed)
				window.close();
		} 
		SetHandsRotationAccordingTime(clock); 
		DrawClock(clock, window);
		// Display things on screen
		window.display();
	}
	
	return EXIT_SUCCESS;
}


