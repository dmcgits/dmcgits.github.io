---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# ISE102 Week 3 - Loops, Collections


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ ISE102 Week 3 - Loops, Collections
](#ise102-week-3-loops-collections)
  - [ Week 2 recap
](#week-2-recap)
  - [ Loops
](#loops)
    - [ While Loops
](#while-loops)
    - [ Basketball in _C++_
](#basketball-in-_c_)
    - [ Menu selection loop
](#menu-selection-loop)
      - [ FarmSim.cpp 
](#farmsimcpp)
    - [ For Loops
](#for-loops)
    - [ `do..while` Loops
](#dowhile-loops)
  - [ Do some code Exercises
](#do-some-code-exercises)
  - [ Break 
](#break)
  - [ Assignment 1 Discussion
](#assignment-1-discussion)
  - [ Collections
](#collections)
    - [ Arrays
](#arrays)
      - [ Initializing Arrays
](#initializing-arrays)
      - [ Abilities
](#abilities)
      - [ Shortcomings
](#shortcomings)
    - [ Multidimensional Arrays
](#multidimensional-arrays)
      - [ TicTacToe.cpp
](#tictactoecpp)
    - [ Vectors
](#vectors)
  - [ Exercises
](#exercises)
  - [ Resources
](#resources)

<!-- /code_chunk_output -->

## Week 2 recap

Data types and conditionals. `if`, `switch`, data types, declaring variables. Comparisons with operators like `>=`, `==`, `!`, `\\`.
1. Sololearn, how far did we get? 
   * If you completed module 2 of Sololearn you will have covered loops. Did it stick?
2. Week 2 code exercises. 


## Loops

Loops are not just an abstract bit of logic proessing. A loop is going to work each day except weekends and holidays. It's watching a series on Netflix, then finding a new series, watching that, and so on.

Of most interest to us: the heart of a video game is a loop. It's a loop that launches many other loops.

``` {.line-numbers}
// A 3 shot basketball game /////////////////

start_program Basketball

	Info on hand: Tries allowed, tries remaining 
	Info we'll track: score

	While tries remaining > 0:
		
		Ask player to hit enter to shoot the ball
		Decide if player made the shot
		
		If they did hit the shot:
			Give them 3 points
		Otherwise
			Give them 0 points
		
		Reduce tries remaining by 1
	loop

	Tell them their score
	Thank them for playing.

end_program Basketball
```

### While Loops

The easiest first loop to learn is the `while` loop. It has this simple structure:

```c++ {.line-numbers}

   while(test) 
   {
      // This code will execute repeatedly until
      // (test) is false.
   }
```

What's the minimum code we need for loop that doesn't go on for ever? Something to make the loop go, and something to make it stop.

```c++ {.line-numbers}

   while(true) // Always evaluates to true, so this is an infinite loop
   {
      break;   // Break ends a loop
   }
   
   // What will that code do?

```
**To make a useful loop**, then, we need **a variable** that we can use in the test, it has to have **an initial value**, and **it has to change** while the loop runs. For it to run a set number of times, we'll create a counter (or index).

>_**initialise**_
>while (_**condition**_)
>{
>    _**increment**_;
>}

### Basketball in _C++_

Replacing those requirements with c++:

```c++ {.line-numbers}

// initialise
int count = 0;

// condition
while ( count < 10 )
{   
   cout << count << " "; // This is so humans can watch
      
   // increment
   count++;
} 

// output:
// 0,1,2,3,4,5,6,7,8,9
```

Easy! Here's the pseudocode basketball game loop written in c++. 

```c++ {.line-numbers}
#include <iostream>
using namespace std;

//Info on hand: Tries allowed, tries remaining 
const int TRIES_ALLOWED = 3;

int triesRemaining;
//Info to track: score
int score = 0;

int main()
{
	// INITIALIZE
	triesRemaining = ________;
	bool shotMade;

	//While tries remaining > 0:
	while (triesRemaining > 0)
	{
		shotMade = false;
		// Ask player to hit enter to shoot the ball
		cout __ "Hit enter to shoot" __ endl;
		cin.get();

		//Decide if player made the shot
		shotMade = true;

		//If they did hit the shot:
		if (_____)
		{
			___ << "Noice! +3 Points.\n";
			// Give them 3 points
			score __ 3;
		} 
		// otherwise
			//Give them 0 points
		
		//Reduce tries remaining by 1
		triesRemaining___;
	} // loop

	//Tell them their score
	//Thank them for playing.
	_________
	_________

} //end_program Basketball
```

### Menu selection loop

That's iteration sorted, but not all loops are counted. The condition evaluates to `true`/`false`, so any comparison will work. Including a choice from a menu.

```
// A menu game loop //////////////

start_program FarmingSim

   While the player hasn't quit:
      
      Show them this menu
      1. Play FarmSim
      2. Options
      3. Quit

      Get their selection
      
      If it's anything exept Quit:
         enter that section
      otherwise:
         note player has quit.
   loop

end_program FarmingSim
```

This loop relies on **initializing** a variable, we could call it `hasPlayerQuit`. The **condition** is that they haven't quit. The **change to the variable** comes from player input.

See if you can finish the translation from _psuedocode_ to _c++_

#### FarmSim.cpp 
```C++ {.line-numbers}
#include <iostream>
using namespace std;

int main()
{
	// INITIALISE variable
	____ userHasntQuit = true;

	// loop with CONDITION
	____ ( userHasntQuit ) // True to begin with
	{
		____ << "1. Play FarmSim" << ____;
		____ << "2. Options" << ____;
		____ << ________ << ____;

		int menuChoice = __;
		____ << "Enter a number to choose: "; 
		cin >> ______;

		switch (____)
		{
			____ 1:
				____ << "You just played FarmSim" << ____;
				break;
			____ 2:
				____ << "You have no options" << ____;
				break;
			____ 3:
				// CHANGE variable
				_____ = _____;
				break;
			default:
				____ << "Try again genius. 1, 2 or 3." << ____;
		}
	}
}
```
___

### For Loops

For loops are way of having the **init**, **condition** and **increment** in a single line. It's almost always used for loops with a counter.

> for ( **initialize**; **condition**, **increment**)
> {
> 	// do things
> }

And with example code filled in: 

```c++ {.line-numbers}
for (int triesRemaining=TRIES_ALLOWED; triesRemaining > 0; triesRemaining--)
{
	// Do things
}

// The counter is commonly known as an "index", and the convention for
// a counting loop is to use int i. If you have a loop/loops inside the outer one,
// we go up the alphabet to keep them isolated. i, j, k, etc

// Do something 10 times
for ( int i = 0; i < 10; i++ )
{
	//Do something 3 times
	for ( int i = 0; j < 3; j++ )
	{
		cout << "I'll be printed 30 times.\n";
	}
}
```

**Pro**: Shorter definition of loop all in one place. Less chance of forgetting to initialise or increment your counter variable.
**Con**: Harder syntax to read/remember for new programmers.

___

### `do..while` Loops

Like a while, with the condition checked at the end. Happens at least once no matter what. A normal while loop will execute 0 times if the condition is never met. I don't recall seeing these used.

```c++ {.line-numbers}
do
{
	cout << "Long cat is long"" << endl;
	// now check if cat is still Long
} while ( catIsLong );
```
## Do some code Exercises

Link to first code exercises

___

## Break 
___

## Assignment 1 Discussion

Assessment pdf [Link](https://laureate-au.blackboard.com/bbcswebdav/pid-7150381-dt-content-rid-8562028_1/xid-8562028_1)
___

## Collections

Lots of data goes together. Potions, cows, seed types, gems collected.

### Arrays

Arrays are for storing collections of things. They aren't directly based on a real world storage metaphor like a pantry or toolbox. An array is just a series of chunks of memory, one after another, set aside to hold the same data type.

We've declared integers like `int faveNumber;` grab 32bits of memory, and to use it by name. With an Array you can declare:

`int faveNumbers[5]` 

and reserve 5 integers worth of memory, and access each of them with the same name and an _index_ like so: 

```c++ {.line-numbers}
x = faveNumbers[2]; 
y = faveNumbers[4];` 
```

Arrays for inventory items:

```c++ {.line-numbers}
#include <iostream>
#include <String>;

// Hero's inventory from the textbook
// demonstrates arrays.
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
```

#### Initializing Arrays

```c++ {.line-numbers}
// This is our first time seeing a new use of the curly braces.
// Normally they mean code block.
// Here they define a set of data values.
int luckyNumbers[5] = { 7, 42, 64, 3, 386 };

// Actually it's not that strict. If you have 5 elements in the array, it can
// figure out the size
int luckyNumbers[] = { 7, 42, 64, 3, 386 };

// if you have more than 5 but you only initialise 5, the rest will be 0
int luckyNumbers[20] = { 7, 42, 64, 3, 386 };

// As a result you can set the first to 0, and the rest 
// will be set to 0, to initialise all items. 
int sooooManyZeroes[2500] = {0};

```

#### Abilities

Can store things, it works.

#### Shortcomings

Once you set the size you're stuck with it. It can also be painful to check. You can only overwrite what's in there.

### Multidimensional Arrays

What if each cell in an array was.. an Array?

#### TicTacToe.cpp

___

### Vectors

A friendly, more flexible version of Arrays. Really, what we want from Arrays a lot of the time.

Vectors are provided in the c++ std library, are a class rather than a basic type, and provide useful functions and properties:
  * `capacity()`, `size()`: max size, actual size
  * `push_back()` to add a new element to the end 
  * `begin()` and `end()` pointers
  * `insert()`, `erase()`
  * Read more: <https://www.geeksforgeeks.org/vector-in-cpp-stl/>

```c++ {.line-numbers}
// C++ program to illustrate the 
// capacity function in vector 
#include <iostream> 
#include <vector> 

using namespace std;

int main()
{
	vector<int> g1;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	cout << "Size : " << g1.size();
	cout << "\nCapacity : " << g1.capacity();
	cout << "\nMax_Size : " << g1.max_size();

	// resizes the vector size to 4 
	g1.resize(4);

	// prints the vector size after resize() 
	cout << "\nSize : " << g1.size();

	// checks if the vector is empty or not 
	if (g1.empty() == false)
		cout << "\nVector is not empty";
	else
		cout << "\nVector is empty";

	// Shrinks the vector 
	g1.shrink_to_fit();
	cout << "\nVector elements are: ";
	//for (auto it = g1.begin(); it != g1.end(); it++)
	//	cout << *it << " ";
	for (int j = 0; j < g1.size(); j++)
	{
		cout << g1[j] << ", ";
	}

	return 0;
}
```

___

## Exercises
1. If you didn't type out the Array/Vector code above, do that.
2. Add a random outcome to the basketball game. Our shooter, over time, should hit 60% of their shots.
3. Work on assessment 1
4. Week 3 [code exercises](week3_code.html) 
___

## Resources

1. The book!
   * [Chapter 1 pdf](book_1/cppgameprog_1_variables_io.pdf)
   * [Chapter 2 pdf](book_1/cppgameprog_2_conditionals_game_loop.pdf)
   * [Chapter 3 pdf](book_1/cppgameprog_3_loops_strings_arrays.pdf)
   
 