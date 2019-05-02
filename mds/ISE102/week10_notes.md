# Week10 Drawing and Moving

A fly stands in for our snake.

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

1. [Week10 Drawing and Moving](#week10-drawing-and-moving)
   1. [A refresher on simulated things](#a-refresher-on-simulated-things)
   2. [Rendering / Drawing](#rendering--drawing)
   3. [Building on last week's hello world base](#building-on-last-weeks-hello-world-base)
      1. [A Fly is data](#a-fly-is-data)
         1. [FlyGame.h](#flygameh)
         2. [FlyGame.cpp](#flygamecpp)
   4. [Movement](#movement)
      1. [Refine movement](#refine-movement)
      2. [Torment: the wormhole](#torment-the-wormhole)

<!-- /code_chunk_output -->

## A refresher on simulated things

Remember, programming is about imagining a world, then converting it into data and the code that moves/changes that data. Some things we imagine:

> * A magic garden that grows enchanted fruit. 
>  - It has wormhole walls that deliver you to the opposite side, so the only escape is death. 
> * A snake who grows longer by a segment when eating the fruit.
>  - It can turn only in 90 degree increments, meaning it is limited to travelling up, down, left or right.
>  - the snake's body flows through these 90 degree turns after it
>  - If it encounters its own body it thinks it has met a dangerous enemy and bites itself to death.

## Rendering / Drawing

Once you have made your simulation, you output it somehow. In a game, we do it in realtime, often as fast as our graphics card can manage. I'll go with a pixel style, reflecting the tiny screens of old Nokias, but it could easiliy be 3D, 2D sprites, Virtual Reality, whatever. 

* Some things we'd draw in a snake game:
  - Grass/ground
  - A border if you like
  - A snake
  - Fruit

## Building on last week's hello world base

Before graduating to snakes, we'll imagine a bluefly, and have it fly around the torture garden. 
* At first it will escape
* You will put it in the eternal prison of the magic garden.

To draw them, we'll build on the SnakeGame or HelloOLC class we made last week. It inherited from the olcConsoleGameEngineOOP class, and overrode the OnUserCreate and OnUserUpdate functions.

![hello olc](assets/week10/hello_olc.png)

For a refresher and more instructions, watch [One Lone Coder's getting started guide:](https://www.youtube.com/watch?v=u5BhrA8ED0o)
[![Start olc](assets/week10/start_olc.jpg)](https://www.youtube.com/watch?v=u5BhrA8ED0o)

> To draw most anything we can use _olcConsoleGameEngine's_ ```Draw()```, ```Fill()``` and ```DrawString()``` functions. 

### A Fly is data

Our fly, drawn or not, is a thing with properties: a location (x, y) and a colour. It has a size too but it's so small we'll just call it a pixel. 
* It's time for a new type of data collection, a `Fly`.
* We could definitely make it an object, but for now keep it simple with a struct.

#### FlyGame.h
```cpp
public:
  // A new type of data collection, the fly
  struct Fly
  {
    int x;
    int y;
    int colour;
  };

private:
  // These could be in OnUserCreate but I've put them into
  // constants, imagining a designer coming in to make changes.
  // On a bigger game we'd move them to a configuration class
  // or maybe a JSON/ini text file
  const int START_X = 10;
  const int FLY_COLOUR = BG_DARK_YELLOW | FG_BLUE;
  const int GROUND_COLOUR = FG_DARK_YELLOW;

  // private variables can feel bad at first, like using globals
  // Remember though, we're encapsulating them. Don't go ham though.
  // Create an instance of a Fly for our blue fly
  Fly _blueFly;

```

#### FlyGame.cpp
```cpp
bool FlyGame::OnUserCreate()
{
  blueFly.x = blueFly.y = START_X;
  blueFly.colour = FLY_COLOUR;
  return true;
}

bool FlyGame::OnUserUpdate(int fElapsedTime)
{
  // No input
  // No simulation, fly ain't moving
  
  RenderWorld();
  return true;
}

void FlyGame::RenderWorld()
{
  // Clear the screen by drawing ground colour
	Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, GROUND_COLOUR); //

  // Draw the fly
  Draw(_blueFly.x, _blueFly.y, *L"Y", _blueFly.colour);
}
```

## Movement

We can move our fly by stepping a little way each frame.

```cpp
struct Fly
  {
    int x;
    int y;
    int speed;
    int colour;
  };

...

bool isUpKeyHeld_ = false;
bool isDownKeyHeld_ = false;

...

bool OnUserUpdate(float fElapsedTime)
{
    // Get input
    isUpKeyHeld_ = (m_keys[VK_UP].bHeld || m_keys[VK_UP].bPressed) ? true : false;
		isDownKeyHeld_ = (m_keys[VK_DOWN].bHeld || m_keys[VK_DOWN].bPressed) ? true : false;

    // update everything
    if (isUpKeyHeld_) _blueFly.y -= _blueFly.speed;
		if (isDownKeyHeld_) _blueFly.y += _blueFly.speed;;

    // Draw the world
    RenderWorld();
    
}

```
### Refine movement

How's that look? We barely see it because it's gone from the screen in an instant. If our framerate is 1000fps our fly just moved 1000 pixels in a second. If your machine was slower and ran at 200fps, it would have moved 200 pixels.

We need to either
1. Move by much tinier amounts
2. Not let the frame rate dictate our movements.

or
limit the frame rate and make it predictable.

For now we'll hack the framerate with sleep. At the end of OnUserUpdate:

```cpp
    ...
    RenderWorld();

    this_thread::sleep_for(chrono::milliseconds(16));

```

### Torment: the wormhole

```cpp

if (_blueFly.y == -1)
  {
    _blueFly.y = ScreenHeight();
  } else if (_blueFly.posY == ScreenHeight()+1)
  {
    _blueFly.posY = 0;
  }

```