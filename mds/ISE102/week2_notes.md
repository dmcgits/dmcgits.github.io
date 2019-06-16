# ISE102 Week 2


Within a code block `{ .. }` C++ is, mostly, a series of statements. A statement is easiest to think of as a mathematical formula, or physics equation.

On the left is the result, or a place to store it. Here’s a line function and Einstein’s baby:
```math
y=mx + b

E=mc^2
```

Everything on the right is collapsed into a result, and can be used interchangeably with the term on the left.
```math
y=mx+b
y=(2*1)+1
y=3
3
```

### Statement building blocks

What we're learning is the _c++_ implementations of the absolute fundamentals of coding. 

> **Variables:** defining values like `5`, `"Kendrick"`, `true`, `35.5`
> **Logic Operators:** How to compare/test values.
> **Math Operators:** +, -, = and all the rest.
> **Conditionals:** Choose what to do next, based on a value or test. 
> **Statements:** A line of code that does something
> **Enums** Defining a few constants at once

We'll start with simple variables and types, get into decision making and comparison, and then deep dive into types and assignment.

## Variables (and literals)

Let's look at this psuedocode.

```
start program LOW_HEALTH

	I have: red mana, blue mana

	If I have enough red mana: 
		cast healing spell
	Otherwise:
		If I have enough blue mana
			cast invisibility spell
		Otherwise:
			Well we're out of options. Good luck.

	let's run away no matter what

end program HANDLE_A_LOW_ON_HEALTH_SITUATION
```

I added something new this time: explicit information. In my `spilled_coffee` week 1 example it was implied: the shirt's dirtiness, the quality of the shirt, my location. This time we have `red mana` and `blue mana`, which are needed for spell casting.

> Handling a situation is: 
> **1.** Gathering information 
> **2.** Acting on it.
> How do we put information in our C++ programs? **Variables**.

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

## Adding conditionals

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
