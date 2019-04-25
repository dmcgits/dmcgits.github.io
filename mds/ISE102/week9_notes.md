# Week 10 - Objects/Classes 2, Games.

Recapping last week, taking it further. Making games with the game loop.

## Objects classes recap

Some missed last week due to maniac at redfern, also objects are so important it's worth a little refresh.

### Hiding complexity

> Objects are a way of wrapping up loads of specialised stuff in an easy to use package, just like a car or an iphone. Then we stick big steering wheel and gear stick, or touch screen and home button in your face. 

  - [physical objects, encapsulation in week8 notes](week8_notes.html)

___

### Objects in code

In our c++ programs **we already use objects**. They're just data types that offer functions: you've seen it on `string` and `vector`.

```cpp
#include <iostream>
#include <string>
#include "termcolor.h"

using namespace std;
using namespace termcolor;

// constants that will be handy.
const int LONG_NAME = 15;
const int REALLY_LONG_NAME = 22;

// Declare functions
string commentOnNameLength(string aName);

int main()
{
	string name = "Aleksandrianakova";
	
	cout << yellow << "My name is " << name << endl << endl;
	cout << white << commentOnNameLength(name) << endl << endl;

	name = "Aleksandrianakovaskayavic";
	
	cout << yellow << "My name is " << name << endl << endl;
	cout << white << commentOnNameLength(name) << endl << endl;

	cout << termcolor::reset;

	return 0;
}

string commentOnNameLength(string aName)
{
	// We're going to call 3 member functions of string objects.
	// if you can type `myVariable.` and a list of variables and functions appears,
	// you have an object.
	string comment = "Oh.";
	if (aName.size() > LONG_NAME)
	{
		if (aName.size() > REALLY_LONG_NAME)
		{
			comment = "I am ded.";
		}
		else
		{
			comment = "That whole thing's your name huh? I'm going to call you ";
			comment.append(aName.substr(0, 5));  // grab first letters of name
		}
	}
	return (comment);
}

```

Looking at that code we can see the user isn't a human driver or phone user, it's our code. **A line of our main function or getValidBet function is the user**. 

> The easy to use package (interface) isn't a touch screen or button, it's a `push_back()` function to add new data to our vector,or a `length()` function telling us how many characters our string has. 

* Look again at code we wrote
  - [week8 code: objects](week8_code.html)
  - 1: A Struct  2: A Class  3: A class in its own files.
  - If you didn't come last week, start typing that code out now! 

At it's most basic an object happened between our includes area and our main function. Separating it out was mostly pulling that zone out into two files (h, cpp) and then using _#include_, exactly like we do with string and vector objects.

## Inheritance

We will introduce basic inheritance today. We'll hit it more next week, but first we need to understand it to use olcConsoleGameEngine. 

To use olcConsoleGameEngine we will need to code above the main function, which can be disorienting after coding down in main.

## A Game Is A Simulation

I started teaching games programming last year by going into the gameloop, but I want to talk first about what a game is. Sure a loop is structurally what it is, but conceptually it's a simulation.

We are simulating a snake, and the fruit it will eat, and the world she moves in.
