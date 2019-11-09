---
html:
  embed_local_images: false
  offline: false
export_on_save:
  html: true
---
# ISE102 Week 9: Snakes, Frames, Objects

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=2 orderedList=false} -->

<!-- code_chunk_output -->

- [ISE102 Week 9: Snakes, Frames, Objects](#ise102-week-9-snakes-frames-objects)
  - [Assessment 3: Snake](#assessment-3-snake)
    - [Answering the brief](#answering-the-brief)
    - [Extras after requirements](#extras-after-requirements)
    - [Bullet points:](#bullet-points)
  - [Delivering the assessment](#delivering-the-assessment)
    - [Create your solution with the right name](#create-your-solution-with-the-right-name)
  - [Things to learn while making Snake](#things-to-learn-while-making-snake)
    - [Games with Frames](#games-with-frames)
    - [Drawing big 80s pixels.](#drawing-big-80s-pixels)
  - [Making pixel games with `eightiesGame.h`](#making-pixel-games-with-eightiesgameh)

<!-- /code_chunk_output -->

## Assessment 3: Snake

### Answering the brief

As a coder, you are a maker. You build things for people, and when you make something for someone it followes a design, a plan, a _brief_. Our's is the assessment 3 brief from blackboard:

The brief: <https://laureate-au.blackboard.com/bbcswebdav/pid-7475676-dt-content-rid-31789150_1/xid-31789150_1>

### Extras after requirements

When someone needs something made, they do enjoy extras. When they are extras. That means they're built on top of the requirements. Do them instead of a requirement and you'll be risking whatever the return was for your work:  marks, payment, promotion.                              

### Bullet points:

Write down the requirements in your own language. It helps clarify your own questions.

#### Due date

End of sunday (11:55pm) Module 6.2 (end of week 12).
**1 Sept 2019.**

#### General Requirements
Worth 40% of total marks.
- Object oriented program.
- Console / dos prompt
- Visual Studio 2017

#### Minimum viable product
* Snake never stops moving
* Snake teleports across screen after hitting edge
* Snake has segments aka body parts
* Fruit randomly appears
* Snake can eat fruit,
* Snake gets longer when eating fruit by adding to tail
* Each fruit gives a point
* score must be displayed
* If snake collides with self it dies, ending the game
* Use the good-programming ideas Danny described in class.

#### Extended features 
Add some these to do better than pass/credit.
Alternately, we are allowed to add original new features.
* specifically 2-5 extra features
* Diff fruits with diff affects (buff or debuff)
* Obstacles: deadly blocks
* High score that stays through multiple games. easy = variable. hard = save and load high score.
* Difficulty settings
* Restart without rerunning the game.

## Delivering the assessment

Not everyone caught the delivery requirements first time round, let's makesure they're here and easy to refer to.

1. Use **Visual Studio 2017**. Not 2019 or 2015.
2. Use our new **_ISE102 80s Game_** template.

### Create your solution with the right name

You need to deliver a file named like so:

**_ISE102_Lastname_Firstname_SnakeGame.zip_**

Mine, for example, would be:

**_ISE102_Mcgillick_Danny_SnakeGame.zip_**

* To avoid breaking anything (by renaming)  **use this format (without .zip) for your solution name**. 
* In Visual Studio, go to _File -> New Project_
* Select _Visual C++_ and **_ISE102 80s Game_**. (we'll make that template in this class)
* Enter **SnakeGame** as the project name
* Enter **ISE102_Lastname_Firstname_SnakeGame** as the solution name (substituting your own last and first names).

![creating solution](assets/week9/snakeGame_80s_project_create.png)
_Use Empty Project unless you have a template (mine is outlined in orange)

## Things to learn while making Snake

### Games with Frames

Frame based like any console game, not query-response-console based. On console a game refreshes **30 times every second.** On a PC it goes up to 60hz, and in FPS games often as high as 144hz.

Regardless of how it's different, don't forget it's the same four things:

> **1. Storage 
> 2. Input 
> 3. Processing
> 4. Output**


#### Game loop for frame based games:

So it's much like our slot game, but the game continues doing things whether you touch the keyboard or not:
  - We **don't** pause the game every loop to wait for a typed response
  - We **do** check input every loop, but proceed to
    - process what's happening in game world (movement, collisions, pickups, damage)
    - draw whatever has happened

``` { .line-numbers }
Make and initialise variables.      // Storage

While Player Hasn't Quit:
  Check for user input.                 // INPUT
  Process what's happening in game      // PROCESSING
  Draw the outcome.                     // OUTPUT
Loop
```

### Drawing big 80s pixels.

Mobile games in the 90s and early 2000s something common with really early console and computer games. HUGE PIXELS. To make a game, we're going to go for this look.. but without having to leave the console.

![](assets/week9/nokia_2100_screen.jpg)
_A glorious Nokia 2100 screen_

![](assets/week9/pro_football_fairchild_channel_f.jpg)
_Check out 'Pro Football' on the Fairchild Channel F_.
![](assets/week9/console_fairchild_channel_f.png)
_The Fairchild Channel F console_

![](assets/week9/desert_fox_fairchild.jpg)
_'Desert Fox' for Fairchild.

![](assets/week9/whizball_fairchild.png)
_'Whizball' for Fairchild.

![](assets/week9/snake_huge_pixels.png)
_An example of huge pixel snake_

## Making pixel games with `eightiesGame.h`

We'll use a library that treats the windows console/terminal like low resolution screen, and by drawing a square text character instead of letters, it treats each potential character on screen as a pixel.

I've taken an engine called _**OLC Console Game Engine**_ by _One Lone Coder_, and chopped it down to a simpler form that we'll just call Eighties (80s) Game.

#### Download and run our new template
The solution linked below is a kind of hello world for making our frame-based, big pixel games. 

[ISE102_80s_Game.zip](assets/week9/ISE102_80s_Game.zip)

Download it, open it in Visual Studio, retarget it, and hit ctrl-F5 to see the screen below.

![](assets/week9/eighties_hello_world.png)
_The green square is a "pixel". The number is the approximate frames per second. It might be wrong._

#### Export yourself a new template

As before, use _Visual Studio's_ **_Project -> Export as Template_**. Call it ISE102 80s Game. 

Now you can start a pixel based game any old from **_File - New Project_**. Be aware though, I'll supply updated versions of the .h file in upcoming weeks. 