# Week 11 Code

## Snail and Navi

Moving a snail by whole cells in a frame rate independent way.

### Psuedocode

Make sure you read and understand this well before typing out the code. It is much easier to understand than reverse engineering the logic from the cpp code.

```
START MovingAtCellsPerSecond,
        NotifyChangingCells,
            TrackLastWholeCell

We have: 
    a 10x10 grid
    
    a snail with:
        a speed in cells per second
        a float position, a float last position
        a last whole cell

forever:
    multiply cells per second by fraction of a second elapsed (say 5 * 0.01)
    add that distance to position
    
    if round(position) is different from round(lastposition)
        print we've changed cells to cell round(position)
        store round(lastposition) as last whole cell
        
    clear screen, draw background and draw snail at round(position)
    print position, cell and last whole cell to screen.
    regardless, store replace last position with position
loop

END MovingAtCellsPerSecond etc
```
--- 
### SnailMain.cpp

This was started by duplicating our super basic olc SnakeGame project from week 9. It only displayed a string. Saved doing all the unicode setup, grabbing olcConsoleGameEngineOOP h/cpp files etc.

For better performance:
1. Change the "Debug" dropdown in the visual studio toolbar (next to x86 dropdown) to "Release" so it isn't compiling in debug stuff. 
2. Comment out the DrawString calls in Game.cpp, they're pretty slow.

```cpp
#include <iostream>
#include "Game.h"

using namespace std;

int main()
{
	Game game;

	game.ConstructConsole(10, 10, 64, 64);
	game.Start();
	return 0;
}
```
---
### Game.h

```cpp
#pragma once
#include "olcConsoleGameEngineOOP.h"

class Game : public olcConsoleGameEngineOOP
{
public:

	int _score = 40155;

	Game();
	~Game();
  
  struct Snail {
    float x = 0.0;
    float lastX = 0.0;
    int cellsPerSec = 15;

    int lastWholeCell = -1;

    int sprite = PIXEL_SOLID;
    int colour = BG_YELLOW | FG_BLACK;
  };

  Snail _snail;
  Snail _navi;
	// Inherited via olcConsoleGameEngineOOP
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;

	void DrawScreen();

};

```
---

### Game.cpp

```cpp
#include "Game.h"
#include <math.h>
#include <chrono>
#include <thread>

Game::Game()
{
}

Game::~Game()
{
}

bool Game::OnUserCreate()
{
  _navi.colour = BG_YELLOW | FG_BLUE;
  _navi.sprite = 0x1D5F;

  return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
	// check for input

	// update things
  _snail.x += _snail.cellsPerSec * fElapsedTime;

  if (round(_snail.x) >= ScreenWidth())
  {
    _snail.x = 0;
  }

  if (round(_snail.x) != round(_snail.lastX))
  {S
    _snail.lastWholeCell = (int) round(_snail.lastX);
  }

	// draw screen
	DrawScreen();

  _snail.lastX = _snail.x;
  this_thread::sleep_for(chrono::milliseconds(2));
	return true;
}

void Game::DrawScreen()
{
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_YELLOW | BG_YELLOW);

  Draw((int) round(_snail.x), 2, _snail.sprite, _snail.colour);
  Draw((int)round(_snail.lastWholeCell), 2, _navi.sprite, _navi.colour);
	
  DrawString(0, 4, L"x: " + to_wstring(_snail.x), BG_YELLOW | FG_RED);
  DrawString(0, 5, L"lstX: " + to_wstring(_snail.lastX), BG_YELLOW | FG_RED);
  
  DrawString(0, 7, L"Cell: " + to_wstring((int)round(_snail.x)), BG_YELLOW | FG_RED);
  DrawString(0, 8, L"lstC: " + to_wstring(_snail.lastWholeCell), BG_YELLOW | FG_RED);
  
}

```

