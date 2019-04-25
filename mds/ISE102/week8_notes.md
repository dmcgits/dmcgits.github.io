# ise102 week 8:  Objects and Classes

In previous years, week 8 has covered FileIO. Since we don't use it in the assignments, I'm going to use this week to introduce you to Object Oriented Programming instead, because I think you'll all make better snake games.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

1. [ise102 week 8: Objects and Classes](#ise102-week-8-objects-and-classes)
   1. [OO](#oo)
      1. [What is encapsulation?](#what-is-encapsulation)
         1. [Goldilocks factor](#goldilocks-factor)
   2. [Encapsulation in practice](#encapsulation-in-practice)
      1. [Structs](#structs)
      2. [Classes](#classes)
   3. [Debugging](#debugging)
      1. [Debugger mode](#debugger-mode)
      2. [Stepping](#stepping)
      3. [Step into, step out:](#step-into-step-out)
      4. [Step over:](#step-over)
      5. [Breakpoints](#breakpoints)
      6. [Info!](#info)
   4. [Resources](#resources)

<!-- /code_chunk_output -->

## OO

### What is encapsulation? 

It's a long word but it's a simple thing we experience every day. 

![kinder](assets/week8/kinder_surprise.jpg)
_capsule: a thing with things inside_

The objects in our every day life usually **hide the bits we don't need to know about:**

![shaver real](assets/week8/shaver_real.jpg)
![shaver patent](assets/week8/shaver_patent.jpg)
_outside v inside_

#### Goldilocks factor

> How much to hide? The answer is, as with most design questions: it depends.

 If you only open and read things on your computer, the simple magic mouse is a nice thing. If you play MOBAs, you might live or die by the macro buttons on your razer naga. 
 

![magicmouse](assets/week8/mouse_magic.jpg)
![naga](assets/week8/mouse_naga.jpg)

## Encapsulation in practice

Object Oriented design is all about encapsulation, and classes/objects are made for it.

### Structs

```cpp
// the keyword "struct" lets us define our own types of data collections.
struct InventoryItem
{  
	string title;
	string category;
	int quantityMls;
	string iconPath;
	string description;
};

// now we can make InventoryItems

InventoryItem myAxe;
myAxe.title = "My battleAxe of cleaving"
```
___

### Classes

You can see that the **struct declares a type of data, it's not a variable itself**. Like float or string, you must now declare a thing of type InventoryItem.

**Classes do the same, but for Objects**. They are like structs with methods (and a bit more).

> Classes are to recipes as objects are to meals. One is a design, the other is one of many products of that design and some work. 

```cpp
//======================== Declare Monster class =====================
class Monster {
public:
  
  void fight();   // public member function
  
  int hitPoints;  // public member variable
};

//===================== Actually Define Monster class functions =====

void Monster::fight()
{
	cout << endl << "Fighting!! \n\n";
}
```
That code goes between your `#include`s and your `main()`,like variable declarations do.

## Debugging

We’ve been using visual studio to compile our code and run the executable (.exe) file it produces in a separate console window. 
When we’ve been hunting for bugs we’ve used cout to look at changing variables, or to just make sure certain lines (maybe in a for loop or if statement) are being reached.

> There is a better way to catch bugs, and it’s name fits: **debugging mode**

We’ve been using “run without debugging; today we’ll try the alternative.
——
### Debugger mode 

Debugging mode is built around the debugger, a program that can look at and control your program’s memory and execution. Your console window will open as normal, but visual studio will change it’s whole layout to display loads of realtime info from the debugger:

![debugger](https://www.hanselman.com/blog/content/binary/Windows-Live-Writer/4915fd631fa1_14EEA/image_3.png)

Debuggers are available for most languages, and have a few common features.
—-
### Stepping  
What if you could **watch as your code executes, line by line**, and see the values of all the variables as they change? Would that make life easier than viewing a debug.log here and there?
**Step through** does exactly that.

Insert Pic of step buttons

—-
### Step into, step out:
Go into the function being called on this line, or out of a function

—-

### Step over: 
steps to the next line in current function. Treats lines with function calls like any other line.

—-

###  Breakpoints 

Stepping through is great but has one major down side: it might take a long time to reach a point of interest. What if, instead. You could choose to pause execution only at certain lines?

![Breakpoints](/assets/week8/breakpoint.jpg)
_breakpoint and hilighted code_

You do that by placing break points in your code, little red dots that appear when you click a space in the left margin of the code window, near the line numbers.

> the _break_ in _breakpoints_ comes from taking a break, pausing, not from breaking/broken.

###  Info!

Loads of info is available in debugger mode, which includes some performance profiling too. 

* Variables and their contents
* the call stack (function calls in sequence), 
* execution time, 
* contents of actual memory 
* more.

![debugger](https://www.hanselman.com/blog/content/binary/Windows-Live-Writer/4915fd631fa1_14EEA/image_3.png)
_another look at the debugger screen info_

##  Resources

Visual studio docs [debugger page:](https://docs.microsoft.com/en-us/visualstudio/debugger/navigating-through-code-with-the-debugger?view=vs-2019)
