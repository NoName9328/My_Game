#pragma once
#include "Map.h"
#include "Food.h"
#include <conio.h>
#include "Snake.h"
#include "Windows.h"

class LogicGame
{
public:
	void Run();
	LogicGame();
	void PrintGameOver();
	bool SnakeMovementImplementation(char ch);
private:
	char ch;
	Map map;
	Snake snake;
	Food apple;
	bool GameOver;
};