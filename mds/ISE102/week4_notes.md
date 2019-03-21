
# ISE102 Week 4

Functions! Taking chunks of code and breaking them out into reusable bits.

## Reusing code


We'll end up writing code that is really useful, and wanting to call on it a lot. Loops let us do that last week, but there are plenty of times it won't be that simple. Reacting when a player clicks or taps, for example.

## First Function

You've already written it!

```c++

int main()
{
	return (0);
}
```

## Ways to consider functions

A function can be thought of as a fancier variable. It's just a variable that does something clever.

### Functions: smart variables

```c++
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

### Functions: macros to run a bunch of code

Encapsulating useful code in a function that may not even need to return anything. It can be of type `void`.

___
### Functions: Getting values that are always changing

`int TimeSinceUniverseStarted` above can't just be stored as a constant as it's forever changing. A function just adds `()` to the definition and now we can add code to get the up to date answer.

___

### Functions: sending data off for calculation

Get the angle to point my sprite at something:

```c++
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
 