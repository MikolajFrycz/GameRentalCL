#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;
using std::vector;

/// This function checks if user entered a correct number of arguemnts.
/// @param argc           Number of arguments, provided by user.
int InputArguments(int argc);

/// This function recognizes input/output files, based on the switch before a file name and stores the directory into a path string.
/// @param arg1			       First command line argument.
/// @param arg2			       Seccond command line argument.
/// @param arg3			       Third command line argument.
/// @param arg4			       Fourth command line argument.
/// @param arg5			       Fifth command line argument.
/// @param arg6			       Sixth command line argument.
/// @param in1				   First input directory.
/// @param in2				   Second input directory.
/// @param out				   Output directory.
/// @prog_stop				   Used to stop the program in main function if incorrect arguments were provided in command line.
void GetDirectories(string arg1, string arg2, string arg3, string arg4, string arg5, string arg6, string& in1, string& in2, string& out, bool& prog_stop);
