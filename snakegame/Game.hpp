#pragma once

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#include "Coordinates.hpp"
class Game
{
private:
	bool gameOver = false;
	int width, height;
	Coordinates *fruit;
	Coordinates *snake[50] = {nullptr};
	int score;
	enum direction
	{
		up,
		down,
		left,
		right
	};
	direction dir;
	int snakeSize;

public:
	Game();
	void borderSetUp();
	void fruitSetUp();
	void snakeSetUp();
	void input();
	void logic();
	// void printGame();
	void growTail();
};