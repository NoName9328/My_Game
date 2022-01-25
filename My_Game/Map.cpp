#include "Map.h"


void Map::ShowMap()
{
	for (size_t i = 0; i < game_map.size(); i++)
	{
		for (size_t j = 0; j < game_map[i].size(); j++)
		{
			std::cout << game_map[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::AppSnaketoMap()
{
	for (size_t i = 0; i < game_map.size(); i++)
	{
		game_map[game_map.size() / 2][game_map[i].size() / 2] = snake[0];
	}
}

Map::Map(std::string path):path(path)
{
	FillFileMap(path);
	AppSnaketoMap();
}

void Map::CreatMap(std::string path)
{
	FillFileMap(path);
	AppSnaketoMap();
}

char& Map::operator()(int posY,int posX)
{
	if (posY> game_map.size() || posX > game_map[0].size())
	{
		throw std::out_of_range("is not found position");
	}
	else
	{
		return game_map[posY][posX];
	}
}

bool Map::FillFileMap(std::string path)
{
	this->File.open(path);
	std::string line;
	if (File.is_open())
	{
		while (getline(File, line))
		{
			std::vector<char> row;
			for (char& c : line)
			{
				if (c != '\n')
				{
					row.push_back(c);
				}
			}
			game_map.push_back(row);
		}
	}
	else
	{
		return false;
	}
	File.close();
	return true;
}

