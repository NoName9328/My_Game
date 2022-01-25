#pragma once
#include <vector>
#include <string>
#include <fstream>
#include "Snake.h"
#include <exception>

class Map
{
private:
	Snake snake;
	std::string path;
	std::ifstream File;
	std::vector<std::vector<char>> game_map;
public:
	void ShowMap();
	Map() = default;
	void AppSnaketoMap();
	Map(std::string path);
	void CreatMap(std::string path);
	bool FillFileMap(std::string path);
	char& operator()(int posY, int posX);
};