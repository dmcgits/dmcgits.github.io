
# ISE102 Week 4

Functions! Taking chunks of code and breaking them out into reusable bits.

## Reusing code

We'll end up writing code that is really useful, and wanting to call on it a lot. Loops let us do that last week, but there are plenty of times it won't be that simple. Reacting when a player clicks or taps, for example.

### First Function

You've already written it!

```c++

int main()
{
	return (0);
}
```

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

### Functions: reduce all this code to an action



### Functions: simple answer to complex question


### Functions: take this data and do some work

Get the angle to point my sprite at something:

```c++
struct Point {
	float x = 0;
	float y=0;
};

int main()
{
	Point myPos = { 3.5, 2.5 }
	getLookAtAngle(myPos, targetPos);
}

```



> **Variables:** defining values like `5`, `"Kendrick"`, `true`, `35.5`

## Resources

1. Book chapters: 
   * [Standard library, vectors](book_1/cppgameprog_4_stdlib_hangman.pdf)
   * [Functions](book_1/cppgameprog_5_funcs_madlib.pdf)
   * 