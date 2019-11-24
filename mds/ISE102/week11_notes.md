---
html:
  embed_local_images: false
  offline: false
export_on_save:
  html: true
---
# Week 11: A working game


<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=2 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 11: A working game](#week-11-a-working-game)
  - [Moving around on keyboard input](#moving-around-on-keyboard-input)
    - [Listening for keys](#listening-for-keys)
    - [So, getting direction](#so-getting-direction)
  - [Drawing a one pixel snake.](#drawing-a-one-pixel-snake)
    - [Controlling speed](#controlling-speed)
    - [Missed inputs 1](#missed-inputs-1)
    - [Missed inputs 2](#missed-inputs-2)
    - [Drawing a clean frame each time](#drawing-a-clean-frame-each-time)
  - [Refresher: How to submit assessment:](#refresher-how-to-submit-assessment)
  - [The middle of the game loop: Collisions!](#the-middle-of-the-game-loop-collisions)
    - [Collisions in Snake](#collisions-in-snake)
  - [Game over](#game-over)

<!-- /code_chunk_output -->


## Moving around on keyboard input
It's not really snake if we can't move around. For that, we need to access the keyboard.

### Listening for keys
  You can use a char for a alphabetic/numeric/punctuation keys:
  - keyIsDown('A') 
  
  For specials, use a Microsoft-defined constant called a Virtual Keycode:
  - `keyIsDown(VK_SPACE)` for example, or `keyIsDown(VK_RIGHT)` 
  List of **virtual keycodes** provided by Microsoft:
  https://docs.microsoft.com/en-gb/windows/win32/inputdev/virtual-key-codes
  
#### Remembering keypresses
You could push keypresses into a collection, then act on them. If someone pressed just "Left", you act on that next frame and clear the vector. If they rapidly pressed "left" and "down" you could act on them in the next two frames.

It's more complicated than we really need for this one.

### So, getting direction

We listen for keys that the game allows, then we set direction accordingly.

// DIAGRAM: replace with screenshot.

```
// Top of file: 

enum Direction { RIGHT, DOWN, LEFT, UP, UNCHANGED };

Direction getDirectionInput();

// main function goes between

Direction getDirectionInput()
{
  Direction direction;
  
  if (keyIsDown(VK_UP) || keyIsDown('W')) // Allowing cursor keys or WASD
  {
    direction = Direction::UP;
  } 

  if (keyIsDown(VK_LEFT) || keyIsDown('A'))
  {
    direction = Direction::LEFT;
  }
  // CRISIS! If a player presses UP and LEFT or W and A at the same time..
  // one of those keys has to win. How do we choose? There's no right answer.
  // We just have to pick an order to our ifs: the ones lower down will
  // overwrite the higher ones.
  return direction;

}
```

// CRISIS! If a player presses UP and LEFT or W and A at the same time..
  // one of those keys has to win. How do we choose? There's no right answer.
  // We just have to pick an order to our ifs: the ones lower down will
  // overwrite the higher ones.

## Drawing a one pixel snake.

Your task during this week was to, at minimum, make a Snake class. It should have a location for the snake's head, along with speed and direction.

To draw it, we call drawpixel.

### Controlling speed
  Moving every frame would be insane. The snake would be moving at over 1000 cells per second.
  - Making game time dependent, not framerate (waiting x milliseconds to draw)
  - Code is already in RandomPixel.
  - Here it is applied to our game.
  
### Missed inputs 1
If we're only checking for inputs when we're willing to move the snake we'll miss a lot of inputs. The snake speed might be as slow as 10 cells per second, and 100ms is a long time in key press land.

So, we check for inputs every frame.
  - We can still only move at our slower rate
  - Since nothing changes unless the snake moves, we only need to update the screen when our snake moves.

### Missed inputs 2

Wait! If people input too quick, we'll still miss key presses! How?
  - Imagine moving up screen to get a fruit, you have to turn super quickly to avoid hitting the wall.
  - /// DIAGRAM:: Snake approaching fruit on wall.
  - People going up screen will rapidly press LEFT, then DOWN to turn around, by "drumming" their fingers down. Move your hand down in one movment but have the index land on _LEFT_ first, your middle finger on _DOWN_ a fraction of a second later. In fighting games it's called _plinking_.
  - If it's done very fast the newDirection will be overwritten with _DOWN_ before it's time to move again.
  - /// DIAGRAM:: frames being drawn over time down the screen, and key presses next to it. Easy to understand.
  - Changing direction to DOWN while going up will either:
    - run the head into the body, causing death
    - be ignored, if you don't thing reversing direction is a game-over offense.

#### Forcing the issue
Force a move & draw as soon as a key is pressed
 
### Drawing a clean frame each time
Our snake leaves an endless trail if we don't clear the screen. How do we clear the screen?

![](assets/week11/screen_mess_no_clear.png)

#### Clearing is filling

> Clearing the screen is just filling all cells with background colour.

I've added functions to eighties game to clear draw filled rectangles and empty ones.

![](assets/week11/fill_rect_empty_rect.png)


## Refresher: How to submit assessment:
 Remember:
  - Check your naming conventions
  - Do not rename your project folder, main.cpp, or move any files around before submitting. Don't break stuff!
  - Make sure your delivered files work. Unzip the zip you made into a temporary folder, then go in and double click the sln file. Test that it all opens and compiles properly.
  
#### Conventions
Week 6 notes cover the [naming conventions](https://dmcgits.github.io/mds/ISE102/week6_notes.html#checking-your-coding-conventions). Do it, it's worth good marks!
  
#### Zipping and naming
Zipping your files and naming the zip file is the same as in Assessment 1, but with "SnakeGame" or "Snake" instead of "SlotsGame".
    - Instructions for how to find and zip your solution folder are [here in the week 6 notes.](https://dmcgits.github.io/mds/ISE102/week6_notes.html#delivering-assessment-1-files)

## The middle of the game loop: Collisions! 

Collisions happen when two solid objects, say a hatchback and an SUV, try to occupy the same space. When it happens, there are repurcussions.

#### Game loop w collisions:  
1. Check for inputs and move things
2. Check if things occupy the same space
3. Decide the repurcussions (benefit or cost?)
4. Draw the screen
  
### Collisions in Snake

1. Snake tip sharing cell with wall
   1a. Consequence: Snake succumbs, game ends.
2. Snake sharing cell with fruit
   2a. Consequence: Snake grows a segment, score increases by 1, Fruit relocates
3. Snake tip sharing cell with own body
   3a. Consequence: Snake succumbs, game ends.
   
4. Dying on wall hit
  * Hitting fruit
    * Leave it up to people to generate more fruit
  * incrementing score

* Menus in frame based game:
  - writeWString (I should add a writeString function that casts to wstring)
  - Waiting for keypress just like movement
  - Mode/state of game: menuscreen, game screen

## Game over
..