# Week 2 book bits

Code and knowledge from C++ by Game Programming

### MenuChooser.cpp
```c++
// MenuChooser.cpp 
// Demonstrates the switch statement

#include <iostream>

using namespace std;

int main()
{

	cout << "Difficulty Levels\n\n";
	cout << "1 - Easy\n";
	cout << "2 - Normal\n";
	cout << "3 - Hard\n\n";

	int choice;
	cout << "Choice : ";
	cin >> choice;

	switch (choice)
	{
	case 1:

		cout << "You picked Easy.\n";

		break;
	case 2:

		cout << "You picked Normal.\n";

		break;
	case 3:

		cout << "You picked Hard.\n";

		break;
	default:

		cout << "You made an illegal choice.\n";
	}

	return 0;
}
```

### ScoreRater.cpp

```c++
// Score Rater
// Demonstrates the if statement
#include <iostream>
using namespace std;

int main()
{
	if (true)
	{
		cout << "This is always displayed.\n\n";
	}
	if (false)
	{
		cout << "This is never displayed.\n\n";
	}
	int score = 1000;
	if (score)
	{
		cout << "At least you didn’t score zero.\n\n";
	}
	if (score >= 250)
	{
		cout << "You scored 250 or more. Decent.\n\n";
	}
	if (score >= 500)
	{
		cout << "You scored 500 or more. Nice.\n\n";
		if (score >= 1000)
		{
			cout << "You scored 1000 or more. Impressive!\n";
		}
	}
	return 0;
}
```

### GameStats
```c++
// Game Stats
// Demonstrates declaring and initializing variables
#include <iostream>
using namespace std;
int main()
{
	// defining variables of different types
	int score;
	double distance;
	char playAgain;
	bool shieldsUp;
	short lives, aliensKilled;
	
	// assigning initial values to the types, aka initialising them.
	score = 0;
	distance = 1200.76;
	playAgain = ’y’;
	shieldsUp = true;
	lives = 3;
	aliensKilled = 10;
	
	// defining a variable and initialiizing it 
	double engineTemp = 6572.89;
	
	cout << "\nscore: " << score << endl;
	cout << "distance: " << distance << endl;
	cout << "playAgain: " << playAgain << endl;
	//skipping shieldsUp since you don’t generally print Boolean values
	
	cout << "lives: " << lives << endl;
	cout << "aliensKilled: " << aliensKilled << endl;
	cout << "engineTemp: " << engineTemp << endl;
	
	int fuel;
	cout << "\nHow much fuel do you have? (enter a whole number) ";
	cin >> fuel;
	cout << "fuel: " << fuel << endl;
	
	// with `typedef` you can create a convenient shortcut
	// for multi part types like `unsigned short int`
	typedef unsigned short int ushort;
	ushort bonus = 10;
	cout << "\nbonus: " << bonus << endl;
	return 0;
}
```
