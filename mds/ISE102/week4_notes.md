---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# ISE102 Week 4

Functions!

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ ISE102 Week 4
](#ise102-week-4)
  - [ Functions: like smart variables
](#functions-like-smart-variables)
  - [ First Function
](#first-function)
    - [ Functions: smart variables
](#functions-smart-variables)
    - [ Functions as macros
](#functions-as-macros)
    - [ Functions: Getting values that are always changing
](#functions-getting-values-that-are-always-changing)
    - [ Functions: sending data off for calculation
](#functions-sending-data-off-for-calculation)
  - [ Exercises
](#exercises)
  - [ Resources
](#resources)

<!-- /code_chunk_output -->


## Functions: like smart variables

What if variables could do more than just store information? What if they could return different answers each time, depending on various factors?

> I want to know much potion was drunk, but I only know the potion remaining and the capacity of the bottle.

Psuedocode
```
start_program PRINT_POTION_DRUNK

  I know: potion remaining, bottle capacity

  print out result of CALC_POTION_DRUNK 
  print out "mls of potion has been drunk."

------
  function CALC_POTION_DRUNK
    subtract potion remaining from bottle capacity, store result
    return the resulting number
  end_function CALC_POTION_DRUNK 
------

end_program PRINT_POTION_DRUNK
```
Now in c++:
```cpp
#include <iostream>
using namespace std;

int potionRemaining = 30;
int bottleCapacity = 100;

int potionDrunk()
{
  int amountDrunk = bottleCapacity - potionRemaining;

  return (amountDrunk);
}

int main()
{
  int drunk = potionDrunk();

  cout << drunk << "mls of potion have been drunk.";
}
```

## First Function

You've already written it!

```c++ { .line-numbers }

int main()
{
	return (0);
}
```

### Functions: smart variables

```c++ { .line-numbers }
int height = 10;
cout << height << endl;
// outputs 10
```
When we write a variable name in c++, like height, it's replaced by whatever data (say an integer) is in the bit of memory height points to. The variable is "evaluated". The variable points to some memory, and the evaluation is whatever data is there.

A function, then, in a sense, is just a variable that points to code and returns the expected data type:

```cpp
//Variable: 
 int height = 10;

// function
int getHeight()
{
	int answer = 5+5;
	return (answer);
}

long long int timeSinceUniverseStarted;

long long int tsus()
{
	return (currentTime - wheneverUniverseStarted);
}

cout << timeSinceUniverseStarted << endl;

```
`
### Functions as macros

Macros in games or productivity apps usually just do a series of things fo you. 
* Macros save you clicks/keypresses
* `void` functions save you writing the same code multiple times
* `void` means "nothing"; functions of type `void` return nothing.

```cpp
#include <iostream>
using namespace std;

void displayQuitMessage()
{
  // \n\n inserts 2 empty rows, \t inserts 4 spaces
  cout << "\n\n"; // Move down 2 rows
  cout << "\tQuitting again? Aren't you tired of running away?" <<  endl;
  cout << "\tPress enter to confirm you are running away: ";
  
  cin.get(); //Listen for input ending with enter

  // A void function doesn't return anything. 
  // Return here just means "return to point were this function was called"
  return;
}

int main()
{
  // call a function to display quit message.
  displayQuitMessage();  
}
```

___
### Functions: Getting values that are always changing

`int TimeSinceUniverseStarted` above can't just be stored as a constant as it's forever changing. A function just adds `()` to the definition and now we can add code to get the up to date answer.

___

### Functions: sending data off for calculation

Get the angle to point my sprite at something:

```c++ { .line-numbers }
struct Point {
	float x = 0.0f;
	float y = 0.0f;
};

struct Sprite {
	float rotation = 0.0f;
}

float getLookAtAngle(Point lookerPoint, Point targetPoint)
{
	// Use pythagoras and aTan2 to get the angle
	float result = 0f;
	// result = all that pythagoras and trig stuff;
	// Always return data matching our function's declared type (float)
	return (result);
}

int main()
{
	Point myPos = { 3.5f, 2.5f };
	Point targetPos = { 1.1f, 6.2f}; 
	Sprite arrow;

	while(true)
	{
		float angle = getLookAtAngle(myPos, targetPos);
		arrow.rotation = angle;
	}

}

```
___

## Exercises

1. Write out and run the code in:
   * [week4_code.html](week4_code.html)
   * [week4_book_bits.html](week4_book_bits.html)
2. **Work on Assignment.** You have everything you need now to complete it.
3. **Complete the 4th module in Sololearn: Functions.** And yep, you need to complete the first 3 to unlock it.
   
___

## Resources

1. Read the chapter on functions in our C++ through games textbook. Skim the bits that are easy but you'll learn some things as you go.
   * Functions: [book_1/cppgameprog_5_funcs_madlib.pdf](book_1/cppgameprog_5_funcs_madlib.pdf)
 