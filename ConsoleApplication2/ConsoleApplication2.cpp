// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}


/* we take out the functionality of displaying the board
** this way we can display beginner/intermediate/... boards
** with just this function.*/
void display_board(char** board, int rows, int columns)
{
    for (rows=0; rows<8; rows++) 
    {
        for (columns=0; columns<8; columns++)
        {
            if (board[rows][columns] == 'e')
            { cout<<"- ";} //dash if guessed and no bomb
            else if (board[rows][columns] == 'x')
            {cout<<"X ";} // X marks a marked bomb
            else
            { cout<<". ";} //point if not guessed, or if bomb
        }
        
        cout<<endl;
    }
}

/* we take out the functionality of playing i.e. marking fields,
** again so that this can apply to all levels */
void play_board(char** board, int rows, int columns, int mines)
{
    int guessed_mines = 0; //keep track of number of correctly guessed mines
    int X, Y;   //user specified X/Y coordinates
    char userchoice;
    
    //we need to do the following in a loop until either the player hits a bomb
    //or the player finds the mines and wins the game
    do
    {
        display_board(board, rows, columns);

        cout<<"Enter X Co-ordinate (>=0)"<<endl;
    	cin>>X;
    	cout<<"Enter Y Co-ordinate (>=0)"<<endl;
    	cin>>Y;
    	cout<<"Enter M to make move, B to mark as bomb"<<endl;
    	cin>>userchoice;
    	if (Y>columns||X>rows)
    	    cout << "You have entered the wrong Co-ordinates, Please Retry" << endl;

        //if user choses Move and hits a bomb, game ends
	    if (userchoice=='M' && board[X][Y] == 'b')
	    {
            cout << "Boom!";
            break;
        }
        //if user choses mark Bomb on a bomb field, set value to x
	    else if (userchoice=='B' && board[X][Y] == 'b') 
	    {
            board[X][Y] = 'x';
            guessed_mines++;
        }         
        //possibly you may want to add a check when user marks bomb but field is empty.
	    //if field is empty and not already marked as bomb, mark as [e]mpty.
        else
	    {
            if (board[X][Y] != 'x') board[X][Y] = 'e';
        }
    } while (guessed_mines < mines);
    
    //if the number of guessed mines is indeed the number of mines in the board, win
    if (guessed_mines == mines)
    {
        cout << "You won!" << endl;
        //you can insert a question here like "play again? next level?"
    }
}

void beginner() { //Beginner

    int rows=9, columns=9;

    //declare and fill the board matrix, can't use regular array as we're passing
    //this to functions, don't worry about it now, just know this is an ugly quickfix.
	char** beginnerboard = new char *[rows];  
    for (int i=0;i<rows;i++)
    {
        beginnerboard[i] = new char[columns];
    }
    //assign bombs by putting the letter "b" in certain fields of our board
	beginnerboard[2][3] = 'b';
	beginnerboard[4][1] = 'b';
	beginnerboard[1][1] = 'b';
	beginnerboard[5][3] = 'b';
    
    //play the game
    play_board(beginnerboard, rows, columns, 4);
    system ("pause");
    delete[] beginnerboard;
}

void leaguetable() //Table
{
	system("cls");
	cout << "This is the League Table" << endl;
	system ("pause");
}

void displayMenu() //Menu
{
        char choice;

        system("cls");
        cout << "Welcome to Minesweeper" << endl;
        cout << "1.Beginner" << endl;
        cout << "2.Intermediate" << endl;
        cout << "3.Expert" << endl;
        cout << "4.League Table" << endl;
        cout << "5.Exit" << endl;
        cout << "Please enter your menu choice: ";
        cin >> choice;

        switch (choice)
        { 
                case '1' : 
                    beginner(); 
                    break;
                case '2' : break;
                case '3' : break;
                case '4' : leaguetable();
                           break;
                case '5' : cout << "Thanks for playing minesweeper" << endl;
                           break;

                default :
                       cout << "Please enter a value between 1 and 5" << endl;
                       system ("pause");
                          
        }
}

int main()
{
    displayMenu();
    system("pause");
    return 0;
}