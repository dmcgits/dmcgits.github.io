# Week 3 Exercises

Vectors, arrays, loops.

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Week 3 Exercises](#week-3-exercises)
	* [Code](#code)
			* [TicTacToe.cpp](#tictactoecpp)
			* [LoopingEnumeratedTypes.cpp](#loopingenumeratedtypescpp)
			* [BreakContinue.cpp](#breakcontinuecpp)

<!-- /code_chunk_output -->


## Code

Type these in, don't cut and paste!

#### TicTacToe.cpp

```c++
// Tic-Tac-Toe Board
// Demonstrates multidimensional arrays
#include <iostream>
using namespace std;

int main()
{
	const int ROWS = 3;
	const int COLUMNS = 3;
	char board[ROWS][COLUMNS] = { {'O', 'X', 'O'} ,
								 {' ', 'X', 'X'} ,
								 {'X', 'O', 'O'} };
								 
	cout << "Here's the tic-tac-toe board:\n";
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	
	cout << "\n'X' moves to the empty location.\n\n";
	board[1][0] = 'X';
	cout << "Now the tic-tac-toe board is:\n";
	
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COLUMNS; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;
	}
	
	cout << "\n'X' wins!";
	return 0;
}
```
___

#### LoopingEnumeratedTypes.cpp

```c++
#include <iostream>

using namespace std;

enum EDAY
{
    Monday,
    Tuesday,
    Wednesday, 
    Thursday, 
    Friday, 
    Saturday, 
    Sunday,

    EDAY_MAX
};

int main()
{
    const EDAY myFavouriteDay = Friday;

    for (int today = Monday ; today < EDAY_MAX ; ++today)
    {
        if (Friday == today)
        {
            cout << "Hooray! It is Friday!" << endl;
        }
        else if (today > Friday)
        {
            cout << "A relaxing weekend day." << endl;
        }
        else
        {
            cout << "Have to go to school today..." << endl;
        }

        if (myFavouriteDay == today)
        {
            cout << "Today is my favourite day!!!" << endl;
        }
    }

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}
```
___

#### BreakContinue.cpp

```C++
#include <iostream>

using namespace std;

int main()
{
    // Infinite loop.
    while (true)
    {
        // Ask the user if they wish to continue playing game.
        char playerChoice = 'n';

        cout << "Continue to play? (Y)es or (N)o: ";
        cin >> playerChoice;

        // Test for upper and lower case.
        if(playerChoice == 'n' || playerChoice == 'N')
        {
            cout << "You have selected to exit the game." << endl;

            break;    // Exits the infinite loop.
        }
        else
        {
            cout << "Playing the game..." << endl;
        }
    }

    int sum = 0;
    for (int i = 0; i < 12; i++)
    {
        if (i == 2 || i == 4 || i == 8)
        {
            cout << "Found a restricted number (2, 4, 8), ";
            cout << "using continue." << endl;

            continue; // Jump to next cycle in for loop.
        }

        // If 'continue' did not happen, execute following code.
        sum += i;

        cout << endl;
        cout << "Current Value in i is: " << i << endl;
        cout << "Current Value in sum is: " << sum << endl;
        cout << endl;
    }

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}
```