# Week 8 code: objects, structs, debugging.

## structs.cpp

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// type name = value;
int bet = 0;
const int MAX_BET = 400;

string playerName = "Gary";
vector<string> names;

// Creating a new type called inventory item
struct InventoryItem
{  
	string title;
	string category;
	int quantityMls;
	string iconPath;
	string description;
};

InventoryItem hastePotion;
InventoryItem healthPotion;

vector<InventoryItem> inventory;

int main() 
{
	//names = vector<string> { "bob", "gerry", "sally", "doris" };
	//cout << endl << "How many names? : " << names.size() << endl;

	hastePotion.title = "Potion Of Massive Speed";
	hastePotion.category = "magic items";
	hastePotion.quantityMls = 50;
	
	cout << endl << "My potion is a " << hastePotion.title << endl;

	inventory.push_back(hastePotion);
	inventory.push_back(healthPotion);

	return 0;
}
```

## SimpleMonsterOneFile.cpp

```cpp
#include <iostream>
#include <string>
using namespace std;

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

//================== Our regular old main function ===================

int main()
{
  Monster gerald; //  Other languages use new Monster(),for example. In c++ creation is automatic.

  gerald.fight(); //  Command Gerald to fight, because humans just assume monsters are violent or something.
}
```

## MonsterOneFile.cpp

```cpp
#include <iostream>
#include <string>
using namespace std;

//======================== Declare Monster class public interface
class Monster {
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
};

//===================== Actually Define Monster class functions

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

//================== Our regular old main function ===================

int main()
{
  Monster gerald; // Other languages use new Monster(),for example. In c++ creation is automatic.

  gerald.fight();
  gerald.talk();
}

```

## Monster Multi file

### main.cpp

```cpp
#include <iostream>
#include "Monster.h"    // when it's a file we use quotes

using namespace std;

int main()
{

	Monster gerald;  // Monster is our own type, like int, and we can declare one.
	Monster anne;

	gerald.fight();  // Calling member functions
	anne.talk();

	anne.armour = 10;  // assigning to member variables.
	cout << "monster armour: " << anne.armour << endl << endl;

}
```

### Monster.h

```cpp
// We need ifndef to check if this header was already included elsewhere.

#ifndef __MONSTER_H__
#define __MONSTER_H__

#include <iostream>

// A class definiition begins
class Monster
{

public:	
	Monster();      // public member functions
	void fight();
	void talk();
	
	int hitPoints;  // public member variables
	int armour;

}; // end of monster declaration. Looks a lot like a struct.

#endif //__MONSTER_H__
```

### Monster.cpp

```cpp
// start by including our definitions
#include "Monster.h"

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

```