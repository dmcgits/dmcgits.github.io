# ISE102 Week 2

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ISE102 Week 2](#ise102-week-2)
  - [TO ADD](#to-add)
  - [Computer, do maths.](#computer-do-maths)
    - [Equations in mathematics / physics](#equations-in-mathematics-physics)
    - [Equations in a slot machine](#equations-in-a-slot-machine)
    - [In C++](#in-c)
- [include <iostream>](#include-iostream)
- [include <iostream>](#include-iostream-1)
- [include <iostream>](#include-iostream-2)

<!-- /code_chunk_output -->

## TO ADD
Explain a1 slot machine.
 * go hard into not googling tutes on slot machines, not scoring 0 for your assignment. 
 * Instead, google "generating random numbers in c++", "comparing numbers in c++", "validating input c++"

 The slot machine and variables/conditionals
 * The slot machine starts with capturing user input and checking if it's valid.


## Computer, do maths.

Computers (analogue and digital ) were designed by mathematicians and logicians like Alan Turing and John Von Neumann, based on centuries of theory by their predecessors. They were built by engineers.

Universal computers like we have now (as opposed to machine's like Turing's enigma breaker)replaced and outperformed even very large rooms of women with analog calculators. They took over the calculations of firing tables for artillery and solving the physics of explosives arranged to compress the uranium core of an atomic bomb into criticality. When they weren't busy on this work, they might also run simulations of cellular automata (Arthur Burks).

No wonder then, that statements in code looks mathemathical equations/functions.

>Within a code block `{ .. }` C++ is, mostly, a series of statements. A statement brings to mind a mathematical/logical expression, or physics equation.
>
> On the left is a symbol for the result. On the right, an expression which is solved, collapsed into a result. 

### Equations in mathematics / physics

Einstein’s baby:

\[ E=mc^2 \]

A solution for a parabola:

\[ y=x^2 \]

### Equations in a slot machine

When you gamble, you hand over your bet. That is gone, you are down to your starting cash - bet. Anything you win is added to that. If a win (2 of a kind, 3 of a kind) returns your bet multiplied by a whole number (say 3x, 5x) then:

\[ myCashAfter = (myCashBefore - bet) + (bet * winMultiplier)\]

### In C++

These formulas/functions in C++ statement form
  * a variable on the left. A symbol to store your answer in.
  * an equals sign denotes assignment: assigning the right side to the left
  * an expression on the right side. This reduces to a solution like our line equation above.

```cpp

int main()
{
  int playerCash = 2000;      // Create variables that can hold information. We can
  int bet = 0;                // assign values to them if they are on the left of an "="    int winMultiplier = 3;      // We read their value by using their name anywhere else.
        

  cout << "Please enter a bet ($10-$500):" << endl;   // Print text asking the user clearly for a bet within a range

  // One more way to change a variable is to accept console input with 'cin'. This command lets
  // the player input a number at the console and hit enter to finish.
  cin >> bet;        // 'cin >>' means "send the console intput to the variable 'bet'"                                

  playerCash = (playerCash - bet) + (bet * winMultiplier);
  
  cout << "You won 3x your bet! Now you have $" << playerCash; // Display the result
}
```


```
E = m * pow(c, 2);


### Variables (and literals)

How do we define these symbols, these places information is stored. First, variables for our line equation:

```cpp
float y = 0.0f; // initialising y to 0. The decimal point and f make it floating point aka decimal.
float m, x, b;

// imagine code here where things are assigned to m, x and b.

y = m * x + b;

cout << "y is: " << y << endl;
```

Variables are _declared_ as _type_, _name_ and _initial value_.

```cpp
float pi = 3.14f;
int polygonSides = 5;

string warriorName = "HillPuncher";
```

___

## Statement building blocks

Storage, maths, logic and decision making, all in c++.

> **Variables:** defining values like `5`, `"Kendrick"`, `true`, `35.5`
> **Logic Operators:** How to compare/test values.
> **Math Operators:** +, -, = and all the rest.
> **Conditionals:** Choose what to do next, based on a value or test. 
> **Statements:** A line of code that does something
> **Enums** Defining a few constants at once

We'll start with simple variables and types, get into decision making and comparison, and then dive further into types and assignment.

### Games!

Let's look at this psuedocode.

```
start program LOW_HEALTH_ENCOUNTER

	I have: red mana, blue mana
  I know: Spells require an amount of mana of a certain colour

	If I have enough red mana: 
		cast healing spell
	Otherwise:
		If I have enough blue mana
			cast invisibility spell
		Otherwise:
			Well we're out of options. Good luck.

	let's run away no matter what

end program LOW_HEALTH_ENCOUNTER
```

>I added something new to the pseudocode this time: explicit information. Things I have, things I know.
>
> In my `spilled_coffee` week 1 example it was implied: the shirt's dirtiness, the quality of the shirt, my location. This time we have `red mana` and `blue mana`, which are needed for spell casting. They're like variables in c++ but not nailed down yet.

Our psuedocode said we have `red mana, blue mana`. Let's write that in _C++_:

```c++
#include <iostream>

// We define a variable like this:
// (type) (name) = (value);

int redMana = 20;
int blueMana = 100;

int main()
{
	
}
```

### Adding conditionals

We discussed decision making last week. We asked if something is true or false; then we take an action. 

```
	If I have enough red mana: 
		cast healing spell
```
Let's change that to _C++_. We've found more implied information too.. how much red mana is needed for a healing spell? 

```c++
// LowHealth.cpp
#include <iostream>
using namespace std;

// We define a variable like this:
// (type) (name) = (value);

int redMana = 20;
int blueMana = 100;

// A variable that never changes is a constant, or const.
// Write it in capitals so people know.
const int HEALING_RED_MANA = 60;
const int INVISIBILITY_BLUE_MANA = 80;

int main()
{

	cout << "I'm low on health.." << endl;	
	
	// If I have enough red mana:
	if ( redMana > HEALING_RED_MANA )
	{
		// cast healing spell
		cout << "Magic bandaid!!" << endl;
	}
	
}
```

That's if our "if" taken care of. What about our otherwise?

```c++
	if ( redMana > HEALING_RED_MANA )
	{
		// cast healing spell
		cout << "Magic bandaid!" << endl;
	}
	else
	{
		if (blueMana > INVISIBILITY_BLUE_MANA)
		{
			//cast invisibility spell
			cout << "Magic blindfold!" << endl;
		}
	}
```

Take away the white space, the specifics, and you get:

```c++
// Basic fork in the road. Based on a test, we choose one of two outcomes.
if (test) { code A } else { code B}
```

The code up there gets a bit ugly with the extra parentheses. It's common to put conditions on the `else`, so _c++_ lets us shorten it to "else if". We'll add the `run away no matter what` too.

```c++
// LowHealth.cpp
#include <iostream>

using namespace std;

// We define a variable like this:
// (type) (name) = (value);

int redMana = 20;
int blueMana = 100;

// A variable that never changes is a constant, or const.
// Write it in capitals so people know.
const int HEALING_RED_MANA = 60;
const int INVISIBILITY_BLUE_MANA = 80;

int main()
{

	cout << "I'm low on health.." << endl;

	// If I have enough red mana:
	if (redMana > HEALING_RED_MANA)
	{
		// cast healing spell
		cout << "Magic bandaid!" << endl;
	}
	//Otherwise:
		//If I have enough blue mana
			// cast invisibility spell
	else if (blueMana > INVISIBILITY_BLUE_MANA)
	{
			// cast invisibility spell
			cout << "Magic blindfold!" << endl;
	}

	// run away no matter what.
	cout << "Run away!" << endl;
}

```

## Powerpoint!
Switch, while, for, enum.
Logical and mathematical operators.
ints, floats, longs, shorts, char.

## Exercises

1. Code from the text book:
   * [week2_book_bits.html](week2_book_bits.html)
2. Type out and run some of the [week 2 exercises](week2_code.html). I recommend at minimum `2.1`, `2.5`, `2.6`, `2.7`. 
   * The handy bit in `2.6` is understanding the fall through option in switch statements. Super useful, people always miss it at first. There are few other ways to handle options with so little code.
   * It's good if you get bored defining variables and typing cout. Also good to get bored of trying logical comparisons. If you can get to where this stuff is easy and obvious you're on your way.
3. Work through sololearn c++ part 2: Conditionals and Loops.

## Resources

1. The book:
   * [chap 1](book_1/cppgameprog_1_variables_io.pdf)
   * [chap 2](book_1/cppgameprog_2_conditionals_game_loop.pdf)
   * [chap 3](book_1/cppgameprog_3_loops_strings_arrays.pdf)
