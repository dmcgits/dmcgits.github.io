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

## 9.2 Monster with get and set

**main.cpp**

```C++
#include "pch.h"
#include <iostream>
#include "Monster.h"

using namespace::std;

int main()
{
	// Declare a variable called monster0, of type Monster. 
	// OR create an instance of CLASS CMonster called monster0.
	Monster monster;

	// Invoke an instance member function.
	monster.fight();
	monster.talk();

	// AS m_iArmour has been declared Private:
	// monster0.m_iArmour = 10; // THIS WILL NO LONGER WORK
	monster.setArmour(10);
	cout << "Monster Armour Class: " << monster.getArmour() << endl;

	monster.setName("Gorgon");
	cout << "Monster's name is = " << monster.getName() << endl;

	monster.setMagicPoints(2);
	// Instances can also be used in control structures.
	if (monster.getMagicPoints() > 3)
	{
		cout << "Casting a spell..." << endl;
	}
	else
	{
		cout << "Not enough magic points to cast spell." << endl;
	}

	return (0);
}
```

**Monster.h**

```C++
#ifndef _MONSTER_H__
#define _MONSTER_H__

class Monster
{
public:
	// Methods or member functions.
	Monster();
	~Monster();
	void fight();
	void talk();
	void castSpell();

	// Get methods
	char* getName();
	int getHitPoints();
	int getMagicPoints();
	int getArmour();

	// Set methods
	void setName(const char* name);
	void setHitPoints(int hitPoints);
	void setMagicPoints(int magicPoints);
	void setArmour(int armour);

private:
	int hitPoints_;
	int magicPoints_;
	int armour_;
	char name_[256];

};

#endif // _MONSTER_H__
```

**Monster.cpp**

```C++
#include "pch.h"
// start by including our definitions
#include <iostream>
#include "Monster.h"

// Access std library member functions and variables
// without std::
using namespace std;

Monster::Monster()
{
	// no initialisation
}

Monster::~Monster()
{
	// No destruction
}

void Monster::fight()
{
	cout << "Fighting!!" << endl;
}

void Monster::talk()
{
	cout << "No more fight. Talk now." << endl;
}

void Monster::castSpell()
{
	cout << "Haha spelling!" << endl;
}

// Get functions: return requested data in a controlled way
// These are just returning private variables, but we have the 
// freedome to return calculations or formatted, concatenated data,
// just like a web server is usually returning you a page built from 
// a script and data every time, and almost never has an actual html
// page sitting on the server.
// Or when your parents ask where you've been and you choose and.. beautify
// your private data in getStoryTheyllAccept();
// Or when I ask your your assignments and you take out the swear words
// and put in all the comments at once.

char* Monster::getName()
{
	return name_;
}

int Monster::getMagicPoints()
{
	return magicPoints_;
}

int Monster::getHitPoints()
{
	return(hitPoints_);
}

int Monster::getArmour()
{
	return armour_;
}

// Set functions: store all the data provided as private variables.
// We can choose to act on it before we store it (like changing capitalisation or changing points to percentages)

void Monster::setName(const char* name)
{
	// Use stringcopy to duplicate the contents of the string
	// (it's a char pointer and we want an safe copy of our own)
	strncpy_s(name_, name, 255);
}
void Monster::setMagicPoints(int magicPoints)
{
	if (magicPoints >= 0)
	{
		magicPoints_ = magicPoints;
	}
}

void Monster::setHitPoints(int hitPoints)
{
	// Monsters die below -10 hitpoints (maybe they can regenerate
	// or are partial zombies) so only set if above that. 
	if (hitPoints >= -10)
	{
		hitPoints_ = hitPoints;
	}
	
	// else call Monster::die() perhaps
}

void Monster::setArmour(int armour)
{
	// Only accept 0 or positive integers for armour.
	// We could add a cap here.. say if(armour > MAX_ARMOUR) armour_ = MAX_ARMOUR;
	if (armour >= 0)
	{
		armour_ = armour;
	}
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