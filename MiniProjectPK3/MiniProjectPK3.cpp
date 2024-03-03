#include <iostream>
#include "Client.h"
#include "Game.h"
#include <vector>
#include "MyLinkedList.h"
#include "functions.h"
#include <fstream>
#include <Windows.h>


using namespace std;

ostream& operator<<(ostream& os, Game& obj) 
{
    obj.getGame();
    return os;
}

ostream& operator<<(ostream& os, Client& obj) 
{
    obj.getClient();
    return os;
}

int main(int argc, char* argv[])
{
    struct Node* head = NULL;
    bool stop_prog = false;
    vector<string> arg(argv, argv + argc);
    vector<Client> Clients;

    Client base_client, temp_client;
    string input_client_dir, input_game_dir, output_dir;
    MyLinkedList<Client> client_list;
    MyLinkedList<Game> game_list;

    if (InputArguments(argc) == -1)
    {
        return 0;
    }

    GetDirectories(arg[1], arg[2], arg[3], arg[4], arg[5], arg[6], input_client_dir, input_game_dir, output_dir, stop_prog);
    if (stop_prog == true)
    {
        return 0;
    }

    int line_ct = base_client.returnLineCt(input_client_dir);
    
    //cout << line_ct;

    Client tempclient;
    Game tempgame;

    //reading clients from file and inserting to clients list
    for (int i = 0; i <= line_ct; i++)
    {
        tempclient.getFromFile(input_client_dir, i);
        client_list.pushBack(tempclient);
    }
    client_list.popFront();
    //reading games from file and instering to game list
    for (int i = 0; i <= line_ct; i++)
    {
        tempgame.getFromFile(input_game_dir, i);
        game_list.pushBack(tempgame);
    }
    game_list.popFront();

    int choice = 0, func_choice = 0;
    bool prog_func = true;
    do
    {
        prog_func = true;
        system("cls");
        choice = 0;
        cout << "#####GAME RENTAL#####\n";
        cout << "Enter 1 to see clients(also add/delete clients and games)\n";
        cout << "Enter 2 to see games\n";
        cout << "Enter 3 to sort clients or games\n";
        cout << "Enter 4 to write clients or games to a file\n";
        cout << "Enter 5 to search for a client by their PESEL number\n";
        cout << "Enter 6 to exit program\n";
        cin >> choice;

        //see client list/adding client and game/deleting client and game
        if (choice == 1)
        {       
            do 
            {
                system("cls");
                cout << client_list;
                cout << "\n";
                cout << "Enter 1 to add client and borrowed game\n";
                cout << "Enter 2 to delete client and borrowed game\n";
                cout << "Enter 3 to go back\n";
                cin >> func_choice;

                //adding clients
                if (func_choice == 1)
                {
                    string PESEL, name, surname, birth_date, city, adress, game_name, borrow_date, return_date;
                    //char name[100], surname[100], birth_date[100], city[100], adress[100], game_name[100], borrow_date[100], return_date[100];
                    cin.clear();
                    cin.ignore();
                    cout << "Enter PESEL: ";
                    getline(cin, PESEL);
                    cout << "Enter name: ";
                    getline(cin, name);
                    cout << "Enter surname: ";
                    getline(cin,surname);
                    cout << "Enter birth-date (D.MM.YYYY): ";
                    getline(cin,birth_date);
                    cout << "Enter city: ";
                    getline(cin,city);
                    cout << "Enter adress: ";
                    getline(cin,adress);
                    cout << "Enter the name of borrowed game: ";
                    getline(cin,game_name);
                    cout << "Enter borrow date: ";
                    getline(cin,borrow_date);
                    cout << "Enter return date: ";
                    getline(cin,return_date);
                
                    Client newclient(PESEL, name, surname, birth_date, city, adress);
                    client_list.pushBack(newclient);
                    newclient.appendFile(input_client_dir);
            
                    Game newgame(PESEL, game_name,borrow_date,return_date);
                    game_list.pushBack(newgame);
                    newgame.appendFile(input_game_dir);

                    cout << "List entry added!\n";
                    Sleep(1);
                    func_choice = 0;
                } //adding clients//adding client
                //deleting clients
                else if (func_choice == 2)
                {
                    int num;
                    cout << "Enter number of the person you wish to remove (along with games borrowed by him/her): ";
                    cin >> num;
                    client_list.deleteNode(num);
                    game_list.deleteNode(num);

                    Client temp_client;
                    Game temp_game;

                    

                    ifstream cl_file(input_client_dir), game_file(input_game_dir);
                    string line, temp1, temp2;
                    int ct = 1;
                    if (!cl_file)
                    {
                        cerr << "Error: file not found!" << "\n";
                        exit(1);
                    }
                    while (getline(cl_file, line))
                    {                        
                        if (ct < num)
                        {
                            temp1 += line + "\n";
                        }
                        if (ct > num)
                        {
                            temp1 += line + "\n";
                        }
                        ct++;
                    }
                    ct = 1;
                    while (getline(game_file, line))
                    {
                        if (ct < num)
                        {
                            temp2 += line + "\n";
                        }
                        if (ct > num)
                        {
                            temp2 += line + "\n";
                        }
                        ct++;
                    }
                    
                   /* cout << "\n" << temp;
                    Sleep(100000);*/
                    ofstream new_client_file(input_client_dir);
                    ofstream new_game_file(input_game_dir);
                    
                    if (new_client_file.is_open())
                    {
                        new_client_file << temp1;
                    }

                    if (new_game_file.is_open())
                    {
                        new_game_file << temp2;
                    }

                    func_choice = 0;
                }
                //exiting loop
                else if (func_choice == 3)
                {
                    prog_func = false;
                }//exiting loop

            } while (prog_func != false);
        }
        //see games
        else if (choice == 2)
        {
            do {
                system("cls");
                cout << game_list;
                cout << "\n";
                cout << "Enter 1 to go back\n";
                cin >> func_choice;
            } while (func_choice !=1);
        }
        //sort games/clients
        else if (choice == 3)
        {
        int type = 0;
            do {
                system("cls");
                cout << "Sort clients or games?\n";
                cout << "Enter 1 for clients\n";
                cout << "Enter 2 for games\n";
                cout << "Enter 3 to go back\n";
                cin >> type;
                if (type == 1)
                {
                    client_list.sort();
                  ofstream chosen_output_file(input_client_dir);
                    if (chosen_output_file.is_open())
                    {
                        for (int i = 1; i <= client_list.getSize(); i++)
                        {
                            chosen_output_file << client_list.getNodeData(i).getClientStr();
                        }
                        chosen_output_file.close();
                    }
                    
                    cout<<"Client list sorted.\n";
                    Sleep(1000);
                }
                else if (type == 2)
                {
                    game_list.sort();
                /*    ofstream chosen_output_file(input_game_dir);
                    if (chosen_output_file.is_open())
                    {
                        for (int i = 1; i <= client_list.getSize(); i++)
                        {
                            chosen_output_file << game_list.getNodeData(i).getGameStr();
                        }
                        chosen_output_file.close();
                    }*/
                    cout << "Game list sorted.\n";
                    Sleep(1000);
                }
            } while (type != 3);
        }
        //write clients/games to an output file
        else if (choice == 4)        
        {
        int choose = 0;
            do {
                system("cls");
                cout << "Enter 1 to write clients to file\n";
                cout << "Enter 2 to write games to file\n";
                cout << "Enter 3 to go back\n";
                cin >> choose;
                if (choose == 1)
                {
                    ofstream chosen_output_file(output_dir);
                    if (chosen_output_file.is_open())
                    {
                        for (int i = 1; i <= client_list.getSize(); i++)
                        {
                            chosen_output_file << client_list.getNodeData(i).getClientStr();
                        }
                        chosen_output_file.close();                        
                    }
                    cout << "Clients written to output file\n";
                    Sleep(1000);
                    choose = 3;
                }
                if (choose == 2)
                {
                    ofstream chosen_output_file(output_dir);
                    if (chosen_output_file.is_open())
                    {
                        for (int i = 1; i <= client_list.getSize(); i++)
                        {
                            chosen_output_file << game_list.getNodeData(i).getGameStr();
                        }
                        chosen_output_file.close();
                    }
                    cout << "Games written to output file\n";
                    Sleep(1000);
                    choose = 3;
                }
            } while (choose != 3);
        }
        //search for a client
        else if (choice == 5)
        {
        int func_choice = 0;
            do {
                int skip = 0, pesel_find = 0;
                system("cls");
                string PES;
                Client searched_client;
                cout << "Enter PESEl number of the person You wish to find: ";
                cin >> PES;

                for (int i = 1; i <= client_list.getSize(); i++)
                {
                    if (i <= client_list.getSize())
                    {
                        if (PES == client_list.getNodeData(i).getPESEL())
                        {
                            searched_client = client_list.getNodeData(i);
                        }
                        else
                        {
                            pesel_find++;
                        }
                    }
                    if(pesel_find == client_list.getSize())
                    {
                        cout << "Person with entered PESEL could not be found.\n";
                        Sleep(1000);
                        skip = 1;
                        break;
                    }
                }
                if (skip != 1)
                {
                    system("cls");
                    cout << "The person holding this PESEL number is:\n\n";
                    searched_client.getClient();
                    cout << "\n\nEnter 1 to search another\n";
                    cout << "Enter 2 to go back\n";
                    cin >> func_choice;
                    if (func_choice != 1 and func_choice != 2)
                    {
                        cout << "Entered wrong number\n";
                        Sleep(1000);
                    }
                }
                if (skip == 1)
                {
                    func_choice = 2;
                }
            } while (func_choice != 2);
        }
        //exit
        else if (choice == 6)
        {
            stop_prog = true;
            system("cls");
            cout << "Program ended.\n";
        }

        else
        {
            cout << "Entered invalid number\n";
        }

    } while (stop_prog != true);
    
    return 0;
}
