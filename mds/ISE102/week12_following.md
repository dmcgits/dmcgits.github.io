# Structs and Following

Hey guys, here's everything I explained in week 12 about making train carraiges follow a driver.

I haven't pasted in the example of placing fruit randomly as it's simpler than what we have below. You just change "Carriage" to "Fruit", store them in a `vector< Fruit > fruitBasket` instead of a `train`. Then place them randomly by setting (for example) their posX and posY to `rand() % 20` , a random number between 0 and 19. Then loop through your `fruitBasket` when it's time to draw them to their location `fruitBasket[i].posX`, `fruitBasket[i].posY`. You can put a numer in place of `i` to access that item in the `vector`, just like arrays.

```C++
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

using namespace std;

struct Carriage {
	int posX = 0;
	int posY = 0;
	int oldX = 0;
	int oldY = 0;

	string variety = "mandarin";
};

const int NUM_CARRIAGES = 4;

int main()
{
	// To create a collection of things, sort of like an infinite shelf to put them on in your cupboard, make a vector using the syntax below:
	// vector < Class > name;
	// Ours is called train, because a train is a collection of carriages.
	vector < Carriage > train;
	srand(time(NULL));

	// You wold just do this at the beginning, in OnUserCreate
	for (int i = 0; i < NUM_CARRIAGES; i++)
	{
		Carriage tempCarriage = Carriage();
		if (i == 0) // 0 is the first carriage, or the driver
		{
			//I'll put the driver at 5, 5
			tempCarriage.posX = 5;
			tempCarriage.posY = 5;
			// And I'll store those positions in "oldX" and "oldY for now. The game is starting
			// so it's never been anywhere before.
			tempCarriage.oldX = tempCarriage.posX;
			tempCarriage.oldY = tempCarriage.posY;
		}
		// The other carriages can just have 0,0, their default values.
		train.push_back(tempCarriage);
	}

	// Look through the train and check what we stored
	for (int j = 0; j < train.size(); j++)
	{
		cout << j << ": " << train[j].posX << "," << train[j].posY << " old: " << train[j].oldX << "," << train[j].oldY << endl;
	}

	for (int j = 0; j < 5; j++)
	{ // Try moving for 5 frames

		  // Now lets try following. You would do this every frame. We'll just set every carriage's location (except the driver)
		// to the old position of the carriage in front.
		for (int i = 0; i < train.size(); i++)
		{
			// A train can remember it's history by 
			// STORING IT'S CURRENT POSITION BEFORE MOVING TO A NEW ONE
			train[i].oldX = train[i].posX; // copy my posX into oldX
			train[i].oldY = train[i].posY;

			if (i == 0) {
				// if i == 0 we're dealing witht he driver, and it's just going to move down the screen one pixel in the y.
				train[i].posX += 0;
				train[i].posY += 1;
			}
			else { // If i>=1 then it isn't the driver. It's not in 0, the front of the vector.
				// If my train starts at 0 (like all vectors) and a train carriage is at 3, then it is behind carriage 2.
				// Therefore a train at i is behind i-1. if i = 3, then i-1 equals 2. 
				// All a carriage has to do is follow the guy in front by setting posX, posY to other guy (or i-1)'s oldX, oldY.
				train[i].posX = train[i - 1].oldX;
				train[i].posY = train[i - 1].oldY;
			}
		} // Go back to top of for loop and move next carriage.

	}
	cout << "----------------------- after moving --------------------" << endl;
	
	// Look through the train again and see if the carriages followed
	for (int j = 0; j < train.size(); j++)
	{
		cout << j << ": " << train[j].posX << "," << train[j].posY << endl;
	}
	int pause;
	cin >> pause;
}
```