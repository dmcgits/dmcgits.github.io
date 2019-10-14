---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# ISE102 Week 5: More about functions

Functions are the main workhorse of your programs. You'll make objects to hold functions, an you'll create variables for functions to act on them. Functions are the **do** in programming.

Code in the notes is duplicated here: [week5_code.html](week5_code.html)


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ISE102 Week 5: More about functions](#ISE102-Week-5-More-about-functions)
  - [Default arguments](#Default-arguments)
    - [Arguments in a game](#Arguments-in-a-game)
    - [Hadoken with arguments](#Hadoken-with-arguments)
    - [Default values for arguments](#Default-values-for-arguments)
  - [Function Overloading](#Function-Overloading)
  - [Passing values and vectors versus arrays](#Passing-values-and-vectors-versus-arrays)
  - [To Do](#To-Do)
  - [Resources](#Resources)

<!-- /code_chunk_output -->

## Default arguments

_Parameters_, or _arguments_, are the info you give to a function to do its work. Here's some psuedocode for a real life example. In real life we're constantly asking for help that requires something be passed to the helper.

```
situation NeedDrinkRefrigerated --------------------------

  Ask a helper:
    put my drink in the fridge (this can of coke), watch to see if they did.
  If helper did put drink in fridge:
    say thanks

end ----------------------------------------------------

...

helper PutDrinkInFridge ( can of drink ) ----

  if (got can of drink ):
    put can of drink in fridge
    return confirmation that yes, it's in fridge
  otherwise:
    ERROR: CANNOT REFRIGERATE IMAGINARY DRINK IN REAL FRIDGE

end ----------------------------------------------

```

Also: 
  * Going to post office and supplying a letter or parcel to the clerk. 
  * Ordering McDonalds and supplying credit card
  * Asking DJ to play your jam requires the name of your jam.

### Arguments in a game

In Street Fighter 4, Ryu throws balls of chi energy (_hadoken_) from his hands. They can be **blue** (air) or **red** (fire). Each also has different affects. There are also more variants for other characters.

![hadoken](assets/week5/hadoken_variants.jpg)

> If we're going to have a function that throws hadokens, it'll need to know what colour type throwing.

### Hadoken with arguments

```cpp
#include ________
#include <Windows.h>
using namespace ___;

// Set up constants to describe each hadoken. These will be /// integers 0, 1 and 2, to computer but readable english to us.
enum HadokenType
{
  AIR_HADOKEN,
  FIRE_HADOKEN,
  METSU_HADOKEN
};

// A function we call each time someone executes a hadoken
____ throwHadoken(HadokenType type)
{
  switch (type)
  {
  ____ AIR_HADOKEN:
    cout << "\tAIR HADOKEN!! ~~~~*O}\n\n";
    break;
  ____ FIRE_HADOKEN:
    cout << "\tFIRE HADOKEN!! ~~~~33}}\n\n";
    break;
  }
  return;
}

int main()
{
  cout << "\n\n\tPress A for air hadoken, F for fire hadoken, Q for Quit. \n\n";

/// Variables to keep track of the state of keyboard presses
  ____ userHasQuit = false;
  ____ aIsHeld = false;
  ____ fIsHeld = false; // Initialise each as unheld

  while (!userHasQuit)
  {
    // The 0x8000 thing a flag windows uses to represent key state. The single & joins the two using "binary and"
    if (GetKeyState('A') & 0x8000)
    {
      // if a isn't already down, throw a hadoken
      if (!aIsHeld)
      {
        aIsHeld = true;
        throwHadoken(AIR_HADOKEN);
      }
    }
    else {
      if (aIsHeld) aIsHeld = false;
    }

    if (GetKeyState('F') & 0x8000)
    {
      // if a isn't already down, throw a fireball
      if (!fIsHeld)
      {
        fIsHeld = true;
        throwHadoken(__________);
      }
    }
    else {
      if (fIsHeld) fIsHeld = ____;
    }

    if (GetKeyState('Q') & 0x8000)
    {
      userHasQuit = ____;
    }

  }
  return(_);

}
```
___

### Default values for arguments

Some things are so common that people would reasonably expect them to just be the default setting. Air hadokens are thrown so much more than fire hadokens that people just think of them as _the_ hadoken.

In C++ **you can define a default value for an argument**. 
* If you call the function with no argument it will use the default value.
* If you provide an argument itt'll be used instead. The default is ignored.

Make a new project, DefaultArgs.

> I've added some color spice to the example. 
> * Save [termcolor.h](assets/week5/termcolor.h) to your DefaultArgs project folder, where the cpp files are already located.
> * In solution explorer, under the DefaultsArgs project: right click _Header Files_ and _add -> existing item_


```c++
#include _________
#include <Windows.h>
#include "termcolor.h"
using namespace ___;

enum HadokenType
{
  AIR_HADOKEN,
  FIRE_HADOKEN,
  METSU_HADOKEN
};

// Air hadokens are thrown so often (compared to fire) that 
// people think of them as just "hadokens". I'll set them as default.
____ throwHadoken(HadokenType type = AIR_HADOKEN)
{
  switch (type)
  {
  ____ AIR_HADOKEN:
    cout << "\tAIR HADOKEN!! " << termcolor::white << termcolor::on_blue << "~~~~*O}\n\n" << termcolor::reset;
    break;
  ____ FIRE_HADOKEN:
    cout << "\tFIRE HADOKEN!! " << termcolor::yellow << termcolor::on_red << "~~~~33}}\n\n" << termcolor::reset;
    break;
  }
  return;
}

int main()
{
  cout << termcolor::reset << "\n\tPress A for air hadoken, F for fire hadoken, Q for Quit. \n\n";

  ____ userHasQuit = false;
  ____ aIsHeld = false;
  ____ fIsHeld = false;

  while (!userHasQuit)
  {
    if (GetKeyState('A') & 0x8000)
    {
      // if a isn't already down, throw a fireball
      if (!aIsHeld)
      {
        aIsHeld = true;
        throwHadoken();
      }
    }
    else {
      if (aIsHeld) aIsHeld = false;
    }

    if (GetKeyState('F') & 0x8000)
    {
      // if a isn't already down, throw a fireball
      if (!fIsHeld)
      {
        fIsHeld = true;
        throwHadoken(__________);
      }
    }
    else {
      if (fIsHeld) fIsHeld = _____;
    }

    if (GetKeyState('Q') & 0x8000)
    {
      ____ << termcolor::reset;
      userHasQuit = ___;
    }

  }
  return(_);

}
```
![Bjarne not bad](assets/week5/bjarne_oo.jpg)
_Now you have his attention_

___

#### Defaults for multiple arguments

Some funcs have multiple args, and a couple will be rarey changed. It's good to be able to default those ones that aren't often used.

From the textbook:
```c++
// setting up a displaywidth and height
// colourdepth and fullscreen become optional
// with default values

void setDisplay(int height, int width, int depth = 32, bool fullScreen = true);

```

Once you start supplying defaults, you can't stop:

```C++
void setDisplay(int width, int height, int depth = 32, bool fullScreen);

// compile error, the final argument is missing a default.
```

The same goes for passing arguments. you can't leave out bit depth and leave in depth but then supply a value for fullscreen. the compiler would know what you mean here because there are different types. If they were both bools or ints it would have no idea which one you mean.

**eg**
___

## Function Overloading

> Sometimes you might want the same function to do a very similar thing but with different argument types. 
 
If you want to use an equip function for things of type Armour and things of type Weapon, you might think you need to come up with two function names:

```c++

void equipWeapon(Weapon someWeapon)
{}

void equipArmour(Armour someArmour)
{}
```

But _C++_ lets you use the same function name with a different argument list, and just picks the right one depending on what you pass in.
```c++

void equip(Weapon someWeapon)
{ }

void equip(Armour someArmour)
{}
```

A more basic example might be you want to convert lots of types to strings. Say an int, a float, a double, a Boolean String. Instead of 
`intToString(int), floatToString(float)` etc you can use

```C++
String toString(int toConvert)
{
	String converted = // some int conversion 
	return(converted)
}

String toString(float toConvert)
{
	String converted = // some float conversion 
	return(converted)
}
```

You end up with the same amount of functions, but you don't have a lot of different names to say the same thing. There are arguments over whether this is good or bad practise, and not all languages support it.

## Passing values and vectors versus arrays

Normally parameters are passed as a copy. You can mess with them in your function and cause no issues:

```c++
void printMyHeight(int someonesHeight)
{
	someonesHeight = 2;
	cout << "SHE'S ONLY " << someonesHeight << " FEET TALL!\n\n";
}

int main()
{
	cout << "How tall are you?\n\n";
	int height = 6;
	printMyHeight(height);

	cout << "Thanks. I'm actually " << height << " feet tall.\n\n";
}
```

Let's jump to [week5_code.html](week5_code.html) for the other two examples.


## To Do
1. Your assignment should be basically done and bug free this week, you only want to be cleaning up bugs and adding extra features/polish next week.
2. Complete all Sololearn modules up to and including functions. (It's weird you have to do pointers before functions, but push through)
3. Book chapter?

## Resources

1. Termcolor: [termcolor.h](assets/week5/termcolor.h)
