#include <iostream>
#include <string>

using namespace std;

int main()
{
	const int MAX_ITEMS = 10;
	string inventory[MAX_ITEMS];
	int numItems = 0;
	
	// the ++ incrementor first evaluates as its beginning number,
	// THEN it has 1 added. So for the first array access numItems returns 0, but by the
	// next line numItems is 1.
	// if it was ++numItems we'd be accessing 1, 2, 3
	inventory[numItems++] = "sword";
	inventory[numItems++] = "armor";
	inventory[numItems++] = "shield";
	
	cout << "Your items:\n";
	for (int i = 0; i < numItems; ++i)
	{
		cout << inventory[i] << endl;
	}
	
	cout << "\nYou trade your sword for a battle axe.";
	inventory[0] = "battle axe";
	
	cout << "\nYour items:\n";
	for (int i = 0; i < numItems; ++i)
	{
		cout << inventory[i] << endl;
	}
}