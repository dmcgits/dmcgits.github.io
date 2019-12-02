---
html:
  embed_local_images: false
  offline: false
export_on_save:
  html: true
---
# Week 12: Slithering

## Assessment 3: final stage

* Reminder of what'll get marks.
    - [Ultimo Assessment 3](https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_7976100_1&course_id=_76681_1)
    - [Online Assessment 3](https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_7956906_1&course_id=_76906_1)
* Flow and feel:
  - Forget it's c++, that it's a uni project: what's missing?
  - People play the game for a max snake length and score. Make sure they get time to know/bask in their results
  - People need a chance to see the game is open and play - Get a "press to start" option in.
* Extra features:
  * Rubric values extra features added on top of what I've walked you through. Shows you can bend what you know toward fun. As above.


### Moving a snake 1: Conga.

There are many ways to move a snake. I'll briefly cover this method, and go in depth with the next.

In Conga line:
- the leader dances forwards
- the next in line feels (hands on shoulders/hips) or sees them moving and
- congas along after them to fill the gap. 

Our snake can work the same way, each segment following the one in front.

![](assets/week12/conga_tf2.jpg)

Pros:
  - Flexible, powerful.
  - If it clicks for you - it's straightforward
Cons:
  - Requires solid understanding of objects and references.
  - Doesn't click for everyone in this short project.

## Moving a snake 2: keep a journal

If you know where the head has been, you can draw a body.

### Super simple: Leave a trail

![](assets/week12/light_floor_trail.jpg)

  * Remember when we didn't clear the screen? We were left with one long noodle of white pixels along the snake head's path.
  * Just by not being erased, the screen is a record of the path taken.
  ![](assets/week11/screen_mess_no_clear.png)
  
  * If we could somewhow clear everything except the last few cells of path taken, the fruit, the border etc we'd have a moving snake!
  
  ![](assets/week12/snake_history_simple_no_clear.png)

  ..but figuring that out would be _complicated_. Let's do it another way.
  
#### Remembering where you've been

We'd get the same effect if we:
1: **Cleared** the screen
2: **Remembered the path travelled**, a list of cells visited. A log of the Snake's journey.
3: Looped through, say, the 8 most recent cells and drew a pixel.

![](assets/week12/snake_as_path_travelled.png)

  - We'd need to store the cells we'd travelled through using memory.
  - We'd need to put new cells at the front
  - We'd need to delete excess history
  - There's no history at the start, so we'd have to create some pre-history when the game starts. 

### Doing it in code

 - How can you **store a long list** of values in memory using C++? A **vector**. 

  ```cpp
    // In Snake.h declare a public variable to hold our path.
    // Declare an empty collection to hold every location we visit
    vector<Cell> pathTravelled; 
  ```
  - Setting up a bit of prehistory for our starting length.

  ```cpp
    ///// Snake.cpp constructor
    // INITIALISE SNAKE
    // add some cells representing the first snakebits
    for (int i = 0; i < snake.length + 1; i++)
    {
      // add a cell for each bit of our starting length.
      pathTravelled.push( {startX, startY});
    }
    
  ```

#### Adding Snake constructor arguments

To set up our snake pre-history we needed our starting position. We can make those arguments to the Snake() constructor.

It'll let us create a new snake at 5,10 by declaring 
```cpp 
// Snake declaration in  main.cpp:
Snake snake = Snake(5,10);
```

To add the arguments:

```cpp
// In Snake.h, change the constructor:
  Snake(int startX = 5, int startY = 5);
  ~Snake();                              // destructor doesn't change
```
```cpp
// In Snake.cpp, the constructor becomes:
Snake::Snake(int startX, int startY)
{
  for (int i = 0; i < length + 1; i++)
  {
    // add a cell for each bit of our starting length.
    pathTravelled.push_back({ startX, startY });
  }
}
```
#### Adding to the beginning of a vector

- We're dealing with recent history though. It'd be nice to push stuff into the start of our vector, and later trim off any excess history. This keeps our snake head at the front of the collection.. index `[0]`.

You can insert things into a vector at any position.  C++ provides handy references to certain places, like `myVector.begin()`. 

```cpp
  // Insert cellTo at the beginning of the vector
  pathTravelled.insert(pathTravelled.begin(), cellTo);

```
> More on `vector::insert()` [at GeeksForGeeks.](https://www.geeksforgeeks.org/vector-insert-function-in-c-stl/)
  
If you **start at 5,5** and move right for a few frames, the vector will look like so:
```
0: 8,5  // current cell
1: 7,5
2: 6,5
3: 5,5  // starting cell
```

#### Moving the snake the new way

Since **`pathTravelled[0]`** is always our current location, or front of our snake.. it's the head! We don't need **`headCell`** anymore.

![](assets/week12/snake_head_is_0.png)
_A closer look at our 0 index, the Snake's head_

To move, then, **`Snake::move()`** needs to:
- Make a copy of the current location **`pathTravelled[0]`**
- Use **`direction`** to move that copy
- Insert it into pathTravelled as our new head position.
- The travel journal/snake is up to date!

```cpp
  Cell cellTo = pathTravelled[0];
  
  switch (direction)
  {
  case Direction::UP:
    cellTo.y -= 1;    // 0 is top of screen, so moving up = subtraction  
    break;
  // etc etc
  }

  pathTravelled.insert(pathTravelled.begin(), cellTo);
```


### Drawing the Snake

It follows that drawing a pixel at `pathTravelled[0]` is the same as drawing the head.

**In main.cpp:**
```cpp
drawPixel(fruit.cell.x, fruit.cell.y, fruit.color);
drawPixel(snake.pathTravelled[0].x, snake.pathTravelled[0].y, snake.color);
```
We know the snake's **`length`** too, so loop through that many pathTravelled to draw your other snake pixels.

![](assets/week12/snake_body_is_length.png)

**In main.cpp:**
```cpp
// Fill in the blanks in main.cpp
for (______; i < snake.length; ____)
{
  // Draw a pixel in the Snake's colour
  drawPixel(snake.pathTravelled[_].x, snake.pathTravelled[_].y, snake.color);
}
```

#### Trim what we don't need

![](assets/week12/snake_as_path_travelled.png)
_The same diagram as above, for reference_

Rather than keep a journal of every cell we've ever visited, it'd be nice to trim off the old ones like in the diagram.

* We can resize the vector to the snake's length. 

```cpp
// after moving to a new cell and adding it to the front of pathTravelled,
pathTravelled.resize(length);
```

> More on `vector::resize()` [at GeeksForGeeks](https://www.geeksforgeeks.org/vector-resize-c-stl/) 

## Eating a fruit.

We've shortchanged ourselves. How?

When we eat a fruit **where do we put the new tail?** With only enough travel history to cover our existing pieces, we're guessing.

* Don't trim so much.
* A spare cell (or more) of history gives us flexibility to add to the tail.
* When we move and call resize, add a little something on top of length.

```cpp
// after moving to a new cell and adding it to the front of pathTravelled,
pathTravelled.resize(length+1);
```

#### Adding the tail

Ideas??

## Adding a start/end/pause screen

It's just a screen where we're not listening for arrows/wasd and not simulating our snake.

It's our Snake game loop under different conditions so.. use a conditional! `if` or `switch`.

```
if screen is START_GAME 
  show "press key to start"
  if key pressed change screen to PLAYING
else if 
  screen is PLAYING
  snake stuff
  if dead 
    change screen to GAME_OVER
else if
  screen is GAME_OVER
  make cause of death visible
  say something nice/mean/whatever
  show "press key to start over"
  if key pressed change screen to PLAYING
end if

```
