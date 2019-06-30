---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Week 4 Exercises

Functions and scope

## Contents


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ Week 4 Exercises
](#week-4-exercises)
  - [ Contents
](#contents)
  - [ Code
](#code)
      - [ 4.1 SlotsGame
](#41-slotsgame)
    - [ 4.2 Scope
](#42-scope)
    - [ 4.3 Function
](#43-function)
    - [ 4.4 Function with prototype (definition) 
](#44-function-with-prototype-definition)
    - [ 4.5 Limiting Rand Range
](#45-limiting-rand-range)
    - [ 4.6 Variable Scope With Range
](#46-variable-scope-with-range)

<!-- /code_chunk_output -->


## Code

Type these in, don't cut and paste!

#### 4.1 SlotsGame

The **most important outcome** of this really short and pretty easy exercise is this: **You have a working core for your game that matches the brief!** It gets a menu choice and exits if it's 2. 

> It doesn't matter that you faked the choice, didn't show the menu, or deal with other menu choices. You have functions with names that tell you, later, where to put the code that does it for real. 

You can forget about the big picture for a bit and write code to display the choices, or how to validate the numbers they entered. That's just grindwork you know you can eventually do. 

> It's hard to panic about a project that already appears to work. If you mess up calculations later or forget a bit, **you're still able to compile, zip and submit a working assignment at any point.**

Shows a few things:
1. Figuring out the the birds-eye-view structure of your game in pseudocode but basically translating the first part of the assignment brief.
2. Replacing that pseudocode with a couple variables, some if/while statments, and function calls!
3. Figuring out a function declaration based on plain english description of it's job and the answer it's meant to give you. A menu choice is 1, 2 or 3 so getValidMenuChoice has to give you an int, who cares how it does it right now.
4. How to return data from a function. All it needs to do is be of the right type. Return 0 works for a function of type int, return false or true returns for a bool function.
5. How to use void as the return type for functions that just do work.

```c++ { .line-numbers }
#include <iostream>

using namespace std;

int getValidMenuChoice();
void displayQuitMessage();

int five = 5;

int main()
{
	bool playerHasntQuit = true;
	int menuChoice = -1;

	while (playerHasntQuit)
	{
		int whileFive = 5;
		menuChoice = getValidMenuChoice();
		if (menuChoice != 2)
		{
			// Go to a section
		}
		else
		{
			playerHasntQuit = false;
			displayFinalWords();
		}
	}
	
	/*
	While player hasn't quit: 
		Get a valid menu choice
		If they haven't chosen to quit:
			Use their choice to jump into section
		otherwise
			Note they've quit
			Display final words
	loop
	*/
}

int getValidMenuChoice()
{
	int menuFive = 5;
	cout << "Choose from menu: (i chose 2 for you);" << endl;
	return (2);
}

void displayQuitMessage()
{
	cout << "Bye loser" << five << endl;
	return;
}
```
___

### 4.2 Scope

```c++ { .line-numbers }
#include <iostream>
using namespace std;

int main()
{
    int x = 9;

    for (int i = 0; i < 1; i++)
    {
        int j = 77;

        cout << "----------------------" << endl;
        cout << "Inside of the for loop" << endl;
        cout << "----------------------" << endl;

        cout << "Value in x = " << x << endl;
        cout << "Value in i = " << i << endl;
        cout << "Value in j = " << j << endl;
    }

    cout << "-----------------------" << endl;
    cout << "Outside of the for loop" << endl;
    cout << "-----------------------" << endl;

    cout << "Value in x = " << x << endl;
//    cout << "Value in i = " << i << endl;
//    cout << "Value in j = " << j << endl;

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}
```
___

### 4.3 Function

```c++ { .line-numbers }

#include <iostream>
using namespace std;

float Area()
{
    float fPI = 3.14f;
    float fRadius = 0.0f;

    cout << "Enter a radius of a circle: ";
    cin >> fRadius;

    float fArea = fPI * fRadius * fRadius;

    return (fArea);
}

int main()
{
    cout << "Area = " << Area() << endl;

    // Do some other work.
    cout << "Other work..." << endl;

    cout << "Area = " << Area() << endl;

    // Do some other work.
    cout << "Other work..." << endl;

    cout << "Area = " << Area() << endl;

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}

```

___

### 4.4 Function with prototype (definition) 


```c++ { .line-numbers }
#include <iostream>
using namespace std;

// Prototype or definition. 
// Just like a variable declaration, but with parentheses and arguments.
float cube(float x);

int main()
{
    float input0 = 0.0f;

    cout << "Enter a real number: ";
    cin >> input0;
    cout << input0 << "^3 is = " << cube(input0) << endl;

    float input1 = 0.0f;
    cout << "Enter another real number: ";
    cin >> input1;
    cout << input1 << "^3 is = " << cube(input1) << endl;

    float input2 = 0.0f;
    cout << "Enter a third real number: ";
    cin >> input2;
    cout << input2 << "^3 is = " << cube(input2) << endl;

    // Wait for input, stops the Command Prompt closing automatically.
    int iTemp;
    cin >> iTemp;

    return (0);
}

float cube(float x)
{
    float fResult = x * x * x; // x^3 = x * x * x

    return (fResult);
}

```
___

### 4.5 Limiting Rand Range

```c++ { .line-numbers }
#include <iostream>
#include <cstdlib> // Provides rand()
#include <ctime> // Provides time()

using namespace std;

int main()
{
  srand( time(0) ); // Seed the random generator.
  signed int iRand1 = 1 + rand() % 20;
  signed int iRand2 = 1 + rand() % 20;
  cout << "d20 rolled = " << iRand1 << endl;
  
  if (iRand1 > 18)
  {
    cout << "Possible Critical..." << endl << endl;
  }
  cout << "d20 rolled = " << iRand2 << endl;
  
  if (iRand1 > 18 && iRand2 > 18)
  {
    cout << "CRITICAL!!! Damage x2!" << endl << endl;
  } else
  {
    cout << "No critical. Just normal damage." << endl;
  }
  
  return (0);
}
```

### 4.6 Variable Scope With Range

```c++ { .line-numbers }
#include <iostream>

using namespace std;

// Declare global PI value
float g_PI = 3.14f;
// Declare function
float SphereVolume(float fRadius);

int main()
{
  cout << "PI = " << g_PI << endl;
  cout << endl;
  float fInput0 = 0.0f;
  
  cout << "Enter a sphere radius: ";
  cin >> fInput0;

  // Ask SphereVolume to return the volume of a sphere
  // for the user's entered radius  
  float fV = SphereVolume(fInput0);
  cout << "V = " << fV << endl;
  
  return (0);
}

float SphereVolume(float fRadius)
{
  // Using a global along with the argument (local scope) 
  // to calculate the sphere volume
  float fV = (4.0f / 3.0f) * g_PI * fRadius * fRadius * fRadius;
  
  // Do a job, pass back a value.
  return (fV);
}
```