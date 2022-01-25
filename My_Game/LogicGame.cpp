#include "LogicGame.h"

LogicGame::LogicGame()
{
	this->GameOver = false;
	ch = ' ';
	map.FillFileMap("Map.txt");
	map.AppSnaketoMap();
	map.ShowMap();
}

void LogicGame::Run()
{
	Map Game_Map("Map.txt");

	while (true)
	{

		if (GameOver == true)
		{
			PrintGameOver();
			break;
		}
		else
		{
			try
			{
				GameOver = SnakeMovementImplementation(ch = _getch());
			}
			catch (const std::exception& ex)
			{
				std::cout << ex.what();
			}
		}
	}
}

void LogicGame::PrintGameOver()
{
	std::cout << "\n\n\n\n\t\t\tGAMEOVER !\n\n\n\n\n\n";
}

bool LogicGame::SnakeMovementImplementation(char ch = _getch())
{
	static int posY = 13;//game_map.size() / 2; // 13
	static int posX = 26;//map.game_map[0].size() / 2; // 26

	ch = static_cast<int>(ch);

	switch (ch)
	{
		case 72: //UP
		{
			for (size_t i = 0; true; i++)
			{
				map(posY,posX) = ' ';
				posY = posY - 1;

				if (_kbhit())
				{
					break;
				}
				else
				{
					if (map(posY,posX) != '#')
					{
						system("cls");
						map(posY, posX) = snake[0];
						map.ShowMap();
						Sleep(200);
						//game_map[posY][posX] = ' ';
					}
					else
					{
						system("cls");
						return true;
					}
				}
			}
		}
		case 80: // DOWN
		{
			for (size_t i = 0; true; i++)
			{
				map(posY, posX) = ' ';
				posY = posY + 1;
				if (_kbhit())
				{
					break;
				}
				else
				{
					if (map(posY,posX)  != '#')
					{
						system("cls");
						map(posY, posX) = snake[0];
						map.ShowMap();
						Sleep(200);
						map(posY, posX) = ' ';
					}
					else
					{
						system("cls");
						return true;
					}
				}
			}
		}
		case 75: // LEFT
		{
			for (size_t i = 0; true; i++)
			{
				map(posY, posX) = ' ';
				posX = posX - 1;
				if (_kbhit())
				{
					break;
				}
				else
				{
					if (map(posY, posX) != '#')
					{
						system("cls");
						map(posY, posX) = snake[0];
						map.ShowMap();
						Sleep(150);
						//game_map[posY][posX] = ' ';
					}
					else
					{
						system("cls");
						return true;
					}
				}
			}
		}
		case 77: // RIGHT
		{
			for (size_t i = 0; true; i++)
			{
				map(posY, posX) = ' ';
				posX = posX + 1;

				if (_kbhit())
				{
					break;
				}
				else
				{
					if (map(posY, posX) != '#')
					{
						system("cls");
						map(posY, posX) = snake[0];
						map.ShowMap();
						Sleep(150);
						map(posY, posX) = ' ';
					}
					else
					{
						system("cls");
						return true;
					}
				}
			}
		}
		default:
		{
			break;
		}
	}
	return false;
}
