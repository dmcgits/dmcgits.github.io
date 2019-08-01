---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Week 12 - Polymorphism/Snake

---

## Polymorphism

We covered it last week in enough detail to understand, though not to use. We can come back to it later in lesson if people want that extra level with an example.

---

## Snake!

Why people came to class.

### We're stuck, how do we add the body/tail?

To solve the programming puzzle, solve the real world problem:

> How do articulated things move?

---

#### Train engines and carriages

Think of a train and carriages: 
* Where is the force applied to the rails?
* How is it transferred to the carriages?

If the engine is pulling, the carriages are passive and rely on their links. 

A question arises: 
> Carriage a is in front of b: is carriage a dragging b along? Or is b clinging to a for a ride? 

Both are true, like acrobats performing monkey grip. But in code `a` is either commanding `b` to its next position, or `b` is interrogating `a`.

---

#### The trick question

Trains can be pushed by the rear engine. 
* The snake doesn't have to be a head pulling segments. 
* The tail could be pushing all segments ahead of it, and the head only chooses the direction.

---

### Fruit and Snake Bits

How do you know if you ate fruit? We're adding fruit to our scene, and it's safe to say an array (vector) is going to store them.

> **Quick Question**: Why can't I use a `const` in the `case` bit of my `switch` statements? Why does it tell me "not a constant expression"
> **Answer:** A long, unsatisfying reason. You can do it though by making your `const` a `static const`.

**Fruit.h** has some static constants. You can access them via the class name whether an object has been created or not:

```C++
#pragma once

class Fruit
{

public:
		// Constants
	static const int RED_APPLE	= 1;
	static const int GRAPE		= 2;

		// Variables
	int		posX		= 0;
	int		posY		= 0;
	int		colour		= 0;

		// Construct
	Fruit	();
	Fruit	(int posX, int posY, int kindOfFruit);
		// Destroy
	~Fruit	();

	// Member Functions
	int		getKind	();
	bool	setKind	(int kind);
	
protected:
	
	int kind_	= 0;
	
};
```

```C++
#include "Fruit.h"
#include "rgbi_colours.h"
#include <vector>

Fruit::Fruit()
{
}

Fruit::Fruit(int x, int y, int kindOfFruit = Fruit::RED_APPLE)
{
	posX = x;
	posY = y;
	setKind(kindOfFruit);
}

Fruit::~Fruit()
{
}

bool 
Fruit::setKind(int kind)
{
	kind_ = kind;
	
	switch (kind_) 
	{
	case (RED_APPLE):
		colour = FG_RED | BG_RED;
		break;
	case (GRAPE):
		colour = FG_MAGENTA | BG_MAGENTA;
		break;
	}
	return (true);
}

int
Fruit::getKind()
{
	return kind_;
}
```
 ---

![fruit cd](assets/week12/fruit_cd.jpg)
_Fruit class diagram_

### Hold your fruit
To use these `Fruit` as they come and go, we need to track them in a collection.  We've used arrays like `Fruit myFruitArray[5]` but they're inflexible. The `vector` class has some new syntax to its definition, but once you know that it's very friendly to use:

```C++
	// include the vector class from the standard library
	#include <vector>
	
	// Create an empty vector to contain objects of class Fruit.
	// vector< classOfObjects > nameOfVector;
	vector< Fruit > fruits;

	// Create a new fruit at x=5, y=5. Make it a Red Apple
	Fruit apple1 = Fruit(5, 5, Fruit::RED_APPLE);
	
	// Push it on to the back of the vector.
	fruits.push_back(apple1);

	// Some example vectors of other types:
	vector< int > goalsIScoredInEachGameThisSeason;
	vector< string > linesOfMySadPoem;
	vector< Hat > myTeamFortressHats;
	vector< Achievement > cheevs;

```

---

### How do you know you ate fruit?

Fruit has a position. You have a position. But there are many fruits. You'll need to **step through your vector with a loop**.

```C++
// A function that checks if we're eating fruit, and returns true
// if we are. Takes a vector of objects of the Fruit class.
bool isEatingFruit( vector< Fruit > fruits )

	for (int i = 0; i<fruits.size(); i++)
	{
		// Get the fruit at i (first time 0, second time 1 and so on)
		Fruit fruit = fruits[i];
		
		// Is it at the same point on the screen?
		if (xPos_ == fruit.posX && yPos_ == fruit.posY) {
			// Then we ate the fruit!
			// Grow.
			addSegment();
			
			return(true);
		}
	}
	return(false);
}
```

### How do you add more to your snake?

Who should add the segments? The snake or the engine?

___

## How do you know if you ate yourself?

Ask these easy questions:
1. Where is my head?
2. Where is each segment of my body?
3. Is my head.. on any of my body segments?
   
Feels like the fruit question doesn't it?

---

## How do I quit?

Return type of `OnUserUpdate()` will do for now.

---

## Class Diagrams

![](assets/week12/class_top.jpg)

_Top level class diagram_

![](assets/week12/class_exp.jpg)

_expanded class diagram_