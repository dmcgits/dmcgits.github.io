---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Week 9: Objects, classes, game engines


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 9: Objects, classes, game engines](#week-9-objects-classes-game-engines)
  - [Game Piece with functions](#game-piece-with-functions)
    - [main.cpp](#maincpp)
    - [GamePiece.h](#gamepieceh)
    - [GamePiece.cpp](#gamepiececpp)
  - [Using olcConsoleGameEngine](#using-olcconsolegameengine)
    - [Create the project](#create-the-project)
    - [olcConsoleGameEngineOOP includes](#olcconsolegameengineoop-includes)
    - [main.cpp](#maincpp-1)
    - [SnakeGame.h](#snakegameh)
    - [SnakeGame.cpp](#snakegamecpp)

<!-- /code_chunk_output -->


## Game Piece with functions

We can declare functions in GamePiece.h as though it were the top of a main.cpp file. Remember, .h files are added to the headers section of solution explorer.

We then add the body of functions to a cpp file with the same name as the header. Cpp files are added to the source section of solution explorer, as with main.cpp

### main.cpp
```cpp { .line-numbers }
\\ main.cpp
#include <iostream>
#include "GamePiece.h"
using namespace std;

int main()
{
	GamePiece apple;
  GamePiece cobraHead;

	//GamePiece SnakePart;
  apple.kind = GamePiece::FRUIT;
  cobraHead.kind = GamePiece::SNAKE_HEAD;

	cout << "\n\t" << "I have an Apple, located at: " << endl;
  cout << "\n\t\t" << "xSquare -> " << apple.xSquare;
  cout << "\n\t\t" << "ySquare -> " << apple.ySquare << endl;
  apple.moveUpOneSquare();

  cout << "\n\t" << "I have an Apple, located at: " << endl;
  cout << "\n\t\t" << "xSquare -> " << apple.xSquare;
  cout << "\n\t\t" << "ySquare -> " << apple.ySquare << endl;

  cout << std::boolalpha; // forces cout to print "true" instead of "1" for booleans
  cout << "\n\t\t" << "Is apple a Fruit? Answer: " << apple.isAFruit() << endl;

  cout << "\n\t\t" << "Can an apple shed skin? Answer: " << apple.canShedSkin() << endl;
  cout << "\n\t\t" << "Can a cobra head shed skin? Answer: " << cobraHead.canShedSkin() << endl;
	return 0;
}
```

### GamePiece.h
```cpp { .line-numbers }
#pragma once

// Tell c++ what a Game Piece is
// Something with an xCell location and a yCell location

// GamePiece, like all classes, must have a .h and a .cpp file.
// .h declares the class and variables and functions
// .cpp defines/fills in the function bodies
class GamePiece
{
public:
  // constants are in uppercase for identification (by convention).
  static const int FRUIT = 0;
  static const int SNAKE_HEAD = 1;
  static const int SNAKE_BODY = 2;
  
  int xSquare = 3;
	int ySquare = 6;
  int kind = FRUIT;

  bool isAFruit();
  void moveUpOneSquare();
  void moveRightOneSquare();
  bool canBePeeled();
  bool canShedSkin();

};
```
### GamePiece.cpp
```cpp { .line-numbers }
#include "GamePiece.h"

bool GamePiece::isAFruit()
{
  //if (kind == GamePiece::FRUIT)
  //{
  //  return true;
  //} 
  //return false;
  return (kind == GamePiece::FRUIT);
}

void GamePiece::moveUpOneSquare()
{
  ySquare = ySquare - 1;
  
  //ySquare -= 1;
  // move up one square
}

void GamePiece::moveRightOneSquare()
{
  // move right
}

bool GamePiece::canBePeeled()
{
  return(isAFruit());
}

bool GamePiece::canShedSkin()
{
  // A snake head or body part could shed skin
  return (kind == SNAKE_HEAD || kind == SNAKE_BODY);
}
```
## Using olcConsoleGameEngine

![Hello olc](assets/week9/hello_olc.png)
_Hello olc_
___

### Create the project 

In Visual Studio
1. create a new project from your quick start template (we made earlier). 
2. If you don't have a template create a new empty project called olcHelloWorld, to project properties -> Linker -> System and set Console in the first drop down. 
3. Create your main.cpp if you don't have one
4. **The game engine uses unicode,** so go to _project properties - general - character set_ and change from multi byte to unicode.

___

### olcConsoleGameEngineOOP includes
You need [this zip file](assets/week9/olcAndTermColor.zip)

From it copy `olcConsoleGameEngineOOP.c` and `olcConsoleGameEngineOOP.h` and paste them into the same folder as your main.cpp.

![olc in project folder](assets/week9/olc_files_in_project_folder.png)

### main.cpp

We can't include SnakeGame or use it until we create the object, so skip past main.cpp and create the `SnakeGame.h` and `SnakeGame.cpp` files.

```cpp
#include <iostream>
#include "SnakeGame.h"

using namespace std;

int main()
{
	SnakeGame game;
	game.ConstructConsole(60, 40, 16, 16);
	game.Start();

	return 0;
}

```

### SnakeGame.h

```cpp
#pragma once
#include "olcConsoleGameEngineOOP.h"

class SnakeGame : public olcConsoleGameEngineOOP
{
public:
	SnakeGame();
	~SnakeGame();

protected:
	int _score = 232995;
	
	virtual bool OnUserCreate();
	virtual bool OnUserUpdate(float fElapsedTime);

};
```

### SnakeGame.cpp

```cpp
#include "SnakeGame.h"
using namespace std;

////////// Inherited from olc engine, it runs at the start, letting you initialise things.

bool SnakeGame::OnUserCreate()
{
	m_sAppName = L"Snakesy"; // This variable is supplied by olc.
	return true;
}

//////// Also from olc, runs every frame

bool SnakeGame::OnUserUpdate(float fElapsedTime)
{
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, 0); // Fill screen with black
	
	DrawString(2, 2, L"SCORE: " + to_wstring(_score)); // Write score 3 pixels right, two pixels down (like arrays, start at 0)
	return true;
}

// Leave these empty
SnakeGame::SnakeGame()
{}

SnakeGame::~SnakeGame()
{}
```