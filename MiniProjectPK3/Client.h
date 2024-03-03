#pragma once
#include <string>
#include <fstream>

using namespace std;

/// Class which defines Client objects
/// 
/// Client type objects store data read from client input file. Clients are stored in a doubly linked list object in the main function.
class Client
{
protected:
	/// PESEL number of the client.
	string PESEL;
	/// Name of the client.
	string name;
	/// Surname of the client.
	string surname;
	/// Date of birth of the client.
	string birth_date;
	/// City of the client's residence.
	string city;
	/// Adress under which client lives.
	string adress;
public:
	/// Zero-argument constructor.
	Client();

	/// Multi-argument constructor
	/// 
	/// All the string type parameters are clients attributes.
	Client(string p, string n, string s, string bd, string c, string a);

	/// Method that reads a client from a specific line in the clients input file.
	/// 
	/// @param filename		Name of the client input file.
	/// @param line_num		Number of the line, from which client data is read.
	virtual void getFromFile(string filename, int line_num);

	/// Method used to return the line count from an input file.
	///
	/// @param filename		Name of a chosen input file.
	virtual int returnLineCt(string filename);

	/// Method used to print out client data in the console.
	///
	/// It prints all the client attributes in a column, from name to adress.
	virtual void getClient();

	/// Method used to append file containing clients.
	/// 
	/// It writes a new line at the bottom of the file. This line contains all the client's attributes.
	/// @param file		Contains name of the client file.
	void appendFile(string file);
	
	/// This method returns PESEL attribute of the client.
	string getPESEL();

	/// This method returns a string containing all the client's attributes written in one line.
	///
	/// It is used to append files with lines containing client's data.
	string getClientStr();

	/// Overloaded > operator used to compare client's PESEL to another's.
	///
	/// Returns true if initial client's PESEL is a higher number than the other's. Returns false otherwise.
	/// @param other		Another Client object, which PESEL is compared to the initial client's PESEL.
	bool operator>(const Client& other);
};

