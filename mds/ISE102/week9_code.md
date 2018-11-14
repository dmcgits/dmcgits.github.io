# Week 9

Classes and objects in C++

## Code exercises

This is your chance to really see the code and take it in at your own paste. Don't just copy and paste it: create the project, add empty files and start typing it in. As you go you won't be able to help but learn the details of using classes.

### 9.1 - A monster

This one has 3 files.

**main.cpp:** familiar.

```C++
#include "pch.h"
#include <iostream>

// Our own custom class
#include "Monster.h"

using namespace std;

int main()
{
	// we know how variable declarations look
	//int exampleInt = 5;

	// Monster is our own type, like int, and we can declare one.
	Monster myMonster;

	// We can call member functions
	myMonster.fight();
	myMonster.talk();

	// assign to public member variables

	myMonster.armour = 10;
	myMonster.magicPoints = 5;

	// and use member variables to control flow
	if (myMonster.magicPoints > 3)
	{
		cout << "Watch this monster do magic: \n" << endl;
		myMonster.castSpell();
	}
	else
	{
		cout << "The monster doesn't have enough magic points, no spell today kids." << endl;
	}
}
```
**Monster.h:** A real header file! We take all those definitions we've been typing above `int main()` before now and put them in a header file.

```C++
// INCLUSION GUARDS:
// Include is pretty ghetto, it literally cuts and pastes file 
// contents right into place it appears. Since the compiler is
// simple we have to ensure things aren't get included twice.

#ifndef __MONSTER_H__
#define __MONSTER_H__

// Header Files
#include <iostream>

// A class definiition begins
class Monster
{
public:
	// public member functions
	Monster();
	void fight();
	void talk();
	void castSpell();

	// public member variables
	int hitPoints;
	int magicPoints;
	int armour;

private:
	int feelings_;
}; // The end of our monster definition

#endif //__MONSTER_H__
```

**Monster.cpp:** The implementation of functions and use of variables from Monster.h.


```C++

// monster.cpp
#include "pch.h"

// start by including our definitions
#include "Monster.h"

// Access std library member functions and variables
// without std::
using namespace std;

Monster::Monster()
{
	// no initialisation
}

void Monster::fight()
{
	cout << "Fighting!! \n\n";
}

void Monster::talk()
{
	cout << "Wait.. no more fight. Talk now. \n\n" << endl;
}

void Monster::castSpell()
{
	cout << "  @@@@@*** Haha can do magic! ***@@@@@ \n\n";
}

```