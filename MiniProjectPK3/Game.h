#pragma once
#include <iostream>
#include "Client.h"

/// Client derived class which defines Game objects.
///
/// This class also inherits Client class attributes, from which PESEL and name attributes are used.
class Game : public Client
{
	/// Attribute containing game's borrow date.
	string borrow_date;
	/// Attribute containing game's return date.
	string return_date;
public:
	/// Zero-argument constructor.
	Game();

	/// Multi-argument constructor.
	///
	/// @param pes		PESEL of the client that borrowed the game.
	/// @param nam		Name of the game.
	/// @param borrowed	Contains date when the game was borrowed.
	/// @param returned	Contains date when the game is meant to be returned.
	Game(string pes, string nam, string borrowed, string returned);

	/// Method that reads a game from a specific line in the games input file.
	/// 
	/// @param file_name		Name of the games input file.
	/// @param line_num		Number of the line, from which game data is read.
	void getFromFile(string file_name, int line_num);

	/// Method used to print out game's data.
	void getGame();

	/// Method used to append file containing games.
	/// 
	/// It writes a new line at the bottom of the file. This line contains all the game's attributes.
	/// @param filename		Contains name of the game file.
	void appendFile(string filename);

	/// This method returns a string containing all the games's attributes written in one line.
	///
	/// It is used to append files with lines containing game's data.
	string getGameStr();

	/// Overloaded > operator used to compare games's PESEL to another's.
	///
	/// Returns true if initial game's PESEL is a higher number than the other's. Returns false otherwise.
	/// @param other		Another Game object, which PESEL is compared to the initial gamet's PESEL.
	bool operator>(const Game& other);
};

