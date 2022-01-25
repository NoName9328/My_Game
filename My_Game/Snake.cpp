#include "Snake.h"

Snake::Snake()
{
	this->Longsnake = 1;
	this->DeadSneke = false;
	ObjectSnake.push_back(3);
}

int Snake::getLongSnake()
{
	return this->Longsnake;
}

bool Snake::getDeadSnake()
{
	return this->DeadSneke;
}

char& Snake::operator[](int a)
{
	if (a > ObjectSnake.size())
	{
		throw std::out_of_range("no find elem");
	}
	else
	{
		return ObjectSnake[a];
	}
}
