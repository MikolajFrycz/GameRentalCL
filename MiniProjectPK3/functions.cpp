#include "functions.h"
#include "MyLinkedList.h"

using std::string;
using namespace std;

int InputArguments(int argc)
{
    if (argc < 3)
    {
        cout <<
            "No arguments!" << endl;
        return -1;
    }
    else if (argc > 7)
    {
        cout << "too many arguments!" << endl;
        return -1;
    }
    else
    return 0;
}

void GetDirectories(string arg1, string arg2, string arg3, string arg4, string arg5, string arg6, string& in1, string& in2, string& out, bool& prog_stop)
{
    if (arg1 == "-inclients")
    {
        in1 = arg2;
        if (arg3 == "-ingames")
        {
            in2 = arg4;
            if (arg5 == "-out")
            {
                out = arg6;
            }
            else
            {
                cout << "Error with command line arguments!";
                prog_stop = true;
            }
        }
        else if (arg3 == "-out")
        {
            out = arg4;
            if (arg5 == "-ingames")
            {
                in2 = arg6;
            }
            else
            {
                cout << "Error with command line arguments!";
                prog_stop = true;
            }
        }
        else
        {
            cout << "Error with command line arguments!";
            prog_stop = true;
        }
    }
    else if (arg1 == "-ingames")
    {
        in2 = arg2;
        if (arg3 == "-inclients")
        {
            in1 = arg4;
            if (arg5 == "-out")
            {
                out = arg6;
            }
            else
            {
                cout << "Error with command line arguments!";
                prog_stop = true;
            }
        }
        else if (arg3 == "-out")
        {
            out = arg4;
            if (arg5 == "-inclients")
            {
                in1 = arg6;
            }
            else
            {
                cout << "Error with command line arguments!";
                prog_stop = true;
            }
        }
        else if (arg1 == "-out")
        {
            out = arg2;
            if (arg3 == "-inclients")
            {
                in1 = arg4;
                if (arg5 == "-ingames")
                {
                    in2 = arg6;
                }
                else
                {
                    cout << "Error with command line arguments!";
                    prog_stop = true;
                }
            }
            else if (arg3 == "-ingames")
            {
                in2 = arg4;
                if (arg5 == "-inclients")
                {
                    in1 = arg6;
                }
                else
                {
                    cout << "Error with command line arguments!";
                    prog_stop = true;
                }
            }
            else
            {
                cout << "Error with command line arguments!";
                prog_stop = true;
            }
        }
        else
        {
            cout << "No clients and games files inputs given or wrong format.";
            prog_stop = true;
        }
    }
}

