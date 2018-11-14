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

## 9.7 Critters and constructors

More of a Tamagotchi than a real monster

**main.cpp**

```C++
// REMEMBER TO KEEP pch.h OR stdafx.h INCLUDE

// Library Includes
#include <iostream>

// Local Includes
#include "Critter.h"

// This Include

// Static Variables

// Static Function Prototypes

// Implementation

void passByValue(Critter _passByValue)
{
    // A copy will take place when this function is called.
    passByValue_.greet();
}

void passByReference(Critter& passByReference_)
{
    // A reference is used.
    passByReference_.greet();
}

/**
*
* Main is used for testing the critter class.
*
* 
* @return Successful completion of the application.
*
*/
int main()
{
    // Create an instance of class critter.
    Critter crit1;
    Critter crit2(1980);
    Critter crit3(1985, 10);

    crit1.hunger = 77;
    std::cout << "crit1's hunger level = " << crit1.hunger;
    std::cout << std::endl;

    crit2.hunger = 80;
    std::cout << "crit2's hunger level = " << crit2.hunger;
    std::cout << std::endl;

    crit3.hunger = 83;
    std::cout << "crit3's hunger level = " << crit3.hunger;
    std::cout << std::endl;

    crit1.greet();
    crit2.greet();
    crit3.greet();

    passByValue(crit1);
    passByReference(crit1);

    int iTemp = 0;
    std::cin >> iTemp;

    return (0);
}
```

**Critter.h**

```C++

//

#ifndef _CRITTER_H__
#define _CRITTER_H__

// Library Includes

// Local Includes

// Types

// Constants

// Prototypes

class Critter
{
    // Member Functions
public:
    // Constructors
    Critter(int hunger_ = 0);
    Critter(int hunger_, int boredom_);

    // Copy Constructor
    Critter(const Critter& rhs_);

    // Destructor
    ~Critter();

    void greet();            // Member function prototype.

protected:

private:

    // Member Variables
public:
    int hunger_;
    int boredom_;

    int* age_;

protected:

private:

};

#endif // _CRITTER_H__

```