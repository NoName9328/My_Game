#pragma once
#include<vector>
#include<iostream>
#include<exception>

class Snake
{
public:
	Snake();
	int getLongSnake();
	bool getDeadSnake();
	char& operator[](int a);
private:
	int Longsnake;
	bool DeadSneke;
	std::vector<char> ObjectSnake;
};