#include "Game.h"

Game::Game()
{
	PESEL = "none";
	name = "none";
	borrow_date = "none";
	return_date = "none";
}

Game::Game(string pes, string nam, string borrowed, string returned)
{
	PESEL = pes;
	name = nam;
	borrow_date = borrowed;
	return_date = returned;
}

void Game::getFromFile(string file_name, int line_num)
{
	ifstream game_file(file_name);
	string line, returned;

	if (game_file.is_open())
	{
		for (int i = 1; i <= line_num; i++)
		{
			std::getline(game_file, line);
		}
	}

	int x[20];
	x[1] = 0;
	int n = 1;

	PESEL = ""; name = ""; borrow_date = ""; return_date = "";
	bool once = true;
	for (int i = 0; i <= line.size(); i++)
	{
		if (line[i] == ',')
		{
			n++;
			x[n] = i;
			for (int i = x[n - 1] + 1; i < x[n]; i++)
			{
				if (n == 2) {
					if (once == true)
					{
						i--;
						once = false;
					}
					PESEL += line[i];
				}
				else if (n == 3) {

					name += line[i];
				}
				else if (n == 4) {

					borrow_date += line[i];
				}
				else if (n == 5) {

					return_date += line[i];
				}

			}
		}
	}
}

void Game::getGame()
{
	std::cout << PESEL << "," << name << "," << borrow_date << "," << return_date;
}

void Game::appendFile(string filename)
{
	ofstream game_file_append(filename, ios::app);
	if (game_file_append.is_open())
	{
		game_file_append << "\n" << PESEL << "," << name << "," << borrow_date << "," << return_date << ",";
		game_file_append.close();
	}
}

string Game::getGameStr()
{
	return PESEL + "," + name + "," + borrow_date + "," + return_date + ",\n";
}

bool Game::operator>(const Game& other) 
{
	return stoll(PESEL) > stoll(other.PESEL);
}
