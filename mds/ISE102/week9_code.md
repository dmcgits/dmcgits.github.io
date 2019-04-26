# Using olcConsoleGameEngine

![Hello olc](assets/week9/hello_olc.png)
_Hello olc_
___

## Create the project 

In Visual Studio
1. create a new project from your quick start template (we made earlier). 
2. If you don't have a template create a new empty project called olcHelloWorld, to project properties -> Linker -> System and set Console in the first drop down. 
3. Create your main.cpp if you don't have one
4. **The game engine uses unicode,** so go to _project properties - general - character set_ and change from multi byte to unicode.

___

## olcConsoleGameEngineOOP includes
You need [this zip file](assets/week9/olcAndTermColor.zip)

From it copy `olcConsoleGameEngineOOP.c` and `olcConsoleGameEngineOOP.h` and paste them into the same folder as your main.cpp.

![olc in project folder](assets/week9/olc_files_in_project_folder.png)

## main.cpp

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

## SnakeGame.h

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

## SnakeGame.cpp

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