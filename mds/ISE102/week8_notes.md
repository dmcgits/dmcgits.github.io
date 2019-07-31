# ise102 week 8:  Objects and Classes

In previous years, week 8 has covered FileIO. Since we don't use it in the assignments, I'm going to use this week to introduce you to Object Oriented Programming instead, because I think you'll all make better snake games.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ise102 week 8:  Objects and Classes](#ise102-week-8-objects-and-classes)
  - [Snake as a board game](#snake-as-a-board-game)
    - [Objects](#objects)
    - [Designs for objects](#designs-for-objects)
    - [The schematic/plan/design](#the-schematicplandesign)
    - [What about in code?](#what-about-in-code)
    - [The schematic in code](#the-schematic-in-code)
  - [Debugging](#debugging)
    - [Debugger mode](#debugger-mode)
    - [Stepping](#stepping)
    - [Step into, step out:](#step-into-step-out)
    - [Step over:](#step-over)
    - [Breakpoints](#breakpoints)
    - [Info!](#info)
  - [Resources](#resources)

<!-- /code_chunk_output -->

## Snake as a board game

Board games. They have two basic parts minimum, usually.

1. Board
2. Pieces

We've all played Snake. What happens in the game? 

![snake phone](assets/week1/snake.png)

So maybe we have a **simple board**, divided into a **grid of squares**, in a grassy colour.

![grid](assets/week8/board_snake_grass.png) 

What pieces would ou need? Where do they go?

![snake plastic](assets/week8/snake_plastic.jpg)
![fruit bits](assets/week8/fruit_wood_2.png)

### Objects

What properties do each of these objects have? 
* There can be many of them, same but different.
* Position on the grid.
* Fruit has maybe colour? A name?
* A snake needs to go places. What things do we need to know for an object to travel in space?

### Designs for objects
Okay, if we wanted to get our snake board game made, we could go to a maker of game boards and say 
> "Hey, we designed a board game. Make it for us. How much will it cost to make 100 sets?

What will the ask us next?

What if we wanted one hundred laptops? Dinner for 12? A fleet of trucks? 10 orc grunts?

### The schematic/plan/design

You make things from a design. Maybe there's a prototype object too, which the design describes. A version made from that design, and you will make more.

### What about in code?

A guy at Xerox was asked how much would you need to write to explain a whole programming language. He said one page. They laughed and said go on then.

To make it self evident to the person looking at the page it needed to relate to their experience. 
* He did it
* It was small talk
* He was very clever
* Small talk treated things as objects. The code and data for a thing, like a snake head or a fruit, go together.

Let's make an object. A GamePiece.

### The schematic in code

Our plan or design, in c++, is called a Class. A class defines what a fruit will be. You can make many pieces of fruit from that one design. Same with trucks: you want them made, you design one in a class. Then you can declare as many variables of type Truck as you want.

```cpp
/// File: truck.h

class Truck {
  public:
    int speedInKph = 0;
    float weightInTonnes = 3.6;
};
```

```cpp
/// File: world_of_trucks_main.h
#include "Truck.h"

int main()
{
  Truck boringOldTruck;
  Truck neighboursFancyTruck;
}

```

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
