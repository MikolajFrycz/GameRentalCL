#include "Client.h"
#include<iostream>
#include <Windows.h>

Client::Client()
{
	PESEL = name = surname = birth_date = city = adress = "null";
}

Client::Client(string p, string n, string s, string bd, string c, string a)
{
	PESEL = p;
	name = n;
	surname = s;
	birth_date = bd;
	city = c;
	adress = a;
}

void Client::getFromFile(string filename, int line_num)
{
	ifstream client_file(filename);
	string line, returned;

	if (client_file.is_open())
	{
		for (int i = 1; i <= line_num; i++)
		{
			std::getline(client_file, line);
		}
	}

	int x[20];
	x[1] = 0;
	int n = 1;

	PESEL = ""; name = ""; surname = ""; birth_date = ""; city = ""; adress = "";
	bool once = true;
	for (int i = 0; i <= line.size(); i++)
	{
		if (line[i] == ',')
		{
			n++;
			x[n] = i;
			for (int i = x[n-1] + 1; i < x[n]; i++)
			{
				
				if (n == 2) 				
				{	
					if (once == true)
					{
						i--;
						once = false;
					}
					PESEL += line[i];
				}
				else if (n == 3) 
				{
					name += line[i];
				}
				else if (n == 4) 
				{	
					surname += line[i];
				}
				else if (n == 5) 
				{
					birth_date += line[i];
				}
				else if (n == 6) 
				{
					city += line[i];
				}
				else if (n == 7) 
				{
					adress += line[i];
				}
			}
		}
	}
}

int Client::returnLineCt(string filename)
{
	int ct = 0;
	string line;
	ifstream client_file(filename);

	while(getline(client_file, line)) {
		ct++;
	}

	return ct;
}

void Client::getClient()
{
	std::cout << PESEL<<",";
	std::cout << name<<",";
	std::cout << surname<<",";
	std::cout << birth_date<<",";
	std::cout << city<<",";
	std::cout << adress<<",";
}

void Client::appendFile(string file)
{
	
	ofstream client_file_append(file, ios::app);
	if (client_file_append.is_open())
	{
		client_file_append << "\n" << PESEL << "," << name << "," << surname << "," << birth_date << "," << city << "," << adress << ",";
		client_file_append.close();
	}
}

string Client::getPESEL()
{
	return PESEL;
}

string Client::getClientStr()
{
	return PESEL + "," + name + "," + surname + "," + birth_date + "," + city + "," + adress + ",\n";
}

bool Client::operator>(const Client& other) 
{
	return stoll(PESEL) > stoll(other.PESEL);
}