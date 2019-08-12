# Week 10 Code 

## Moving a snake head around

### main.cpp

First, we window running our game

```cpp {.line-numbers}
#include <iostream>
#include "SnakeGame.h"

using namespace std;

int main()
{
	SnakeGame game;
  // 20 rows wide, 24 columns high, 
  // and make each "pixel" take up 24x24 of your high resolution screen's pixels.
	game.ConstructConsole(20, 24, 24, 24);
	game.Start();

	return 0;
}
```

### SnakeHead.h

```cpp {.line-numbers}
#pragma once

class SnakeHead
{

public:
  float x = 0.0f;
  float y = 0.0f;
  float speed = 0.0f;
  int colour = 0;

  // We're using floats for x,y,speed because at the rate the screen updates,
  // maybe 800x a second, moving 1 whole pixel per frame would
  // put us 770 pixels off screen after 1 second
};
```

### SnakeGame.h

```cpp {.line-numbers}
#pragma once
#include "olcConsoleGameEngineOOP.h"
#include "SnakeHead.h"

class SnakeGame : public olcConsoleGameEngineOOP
{
public:
  // The constructor and destructor. They always have to be declared, whether you use them or not.
  SnakeGame();
  ~SnakeGame();

protected:
  int _score = 232995;

  virtual bool OnUserCreate();
  virtual bool OnUserUpdate(float fElapsedTime);

  bool isUpKeyHeld_ = false;
  bool isDownKeyHeld_ = false;
  
  const int START_X = 10;
  const int HEAD_COLOUR = BG_DARK_YELLOW | FG_BLUE;
  const int GROUND_COLOUR = FG_DARK_YELLOW;

  // private variables can feel bad at first, like using globals
  // Remember though, we're encapsulating them. Don't go ham though.
  // Create an instance of a Fly for our blue fly
  SnakeHead _head;

  void RenderWorld();
};
```

### SnakeGame.cpp

```cpp {.line-numbers}
#include "SnakeGame.h"

// Runs when you create "SnakeGame" because you extended olcConsoleGameEngineOOP
// This is where you put everything in their starting state/position
bool SnakeGame::OnUserCreate()
{
  _head.x = _head.y = (float)START_X;
  _head.speed = 0.02f;
  _head.colour = HEAD_COLOUR;
  
  return true;
}

// Runs many times a second in "SnakeGame" because you extended olcConsoleGameEngineOOP
// This is where your game action happens
bool SnakeGame::OnUserUpdate(float fElapsedTime)
{
    // Get input
    isUpKeyHeld_ = (m_keys[VK_UP].bHeld || m_keys[VK_UP].bPressed) ? true : false;
		isDownKeyHeld_ = (m_keys[VK_DOWN].bHeld || m_keys[VK_DOWN].bPressed) ? true : false;

    // update everything
    if (isUpKeyHeld_) _head.y -= _head.speed;
		if (isDownKeyHeld_) _head.y += _head.speed;;

    // Draw the world
    RenderWorld();
    
    // OnUserUpdate has to return true for the engine to continue
    return true;
}

void SnakeGame::RenderWorld()
{
  
  // Clear the screen by drawing ground colour
  Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, GROUND_COLOUR); //

  DrawString(2, 2, L"UP: " + to_wstring(isUpKeyHeld_)); // Write score 3 pixels right, two pixels down (like arrays, start at 0)
  DrawString(2, 3, L"DN: " + to_wstring(isDownKeyHeld_)); // Write score 3 pixels right, two pixels down (like arrays, start at 0)
  // Draw the fly 
  Draw((int)_head.x, (int)_head.y, PIXEL_SOLID, _head.colour);
}

// The constructor and destructor. They always have to be declared, whether you use them or not.
SnakeGame::SnakeGame()
{
}

SnakeGame::~SnakeGame()
{
}
```




