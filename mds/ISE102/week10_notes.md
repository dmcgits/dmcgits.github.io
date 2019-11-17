---
html:
  embed_local_images: false
  offline: false
export_on_save:
  html: true
---
# Week 10: Objects and movement
<!-- 
## Approach

Last trimester this was about 
-->

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderedList=true} -->

<!-- code_chunk_output -->

- [Week 10: Objects and movement](#week-10-objects-and-movement)
  - [Last week](#last-week)
  - [Exam comments](#exam-comments)
  - [Slots comments](#slots-comments)
  - [This week](#this-week)
  - [Snake: Problems to solve](#snake-problems-to-solve)
  - [Making and moving the snake 1](#making-and-moving-the-snake-1)
  - [The score](#the-score)
  - [Moving the snake 2: segments](#moving-the-snake-2-segments)

<!-- /code_chunk_output -->


## Last week
We created a template and began drawing in code.

Tasks I laid out for people to work through at home:

Draw a border around a coloured background
Make the border flash
Draw cell numbers in the top and left margin (partial code provided)

**How did we do?**

## Exam comments

Questions that caught people:
1. Which is the not operator?
2. What are the values of these enums?
3. Values of b1, b2, b3, b4?
4. How many times will "hello" be printed?
5. Switch fall through

## Slots comments

1. Never use rand() without using srand() to seed it.
2. Don't use a series of ifs without else if unless you're dead certain of logic.

## This week

- Problems that must be cracked to make Snake
- Custom objects - How can objects help
- Let's move a thing with code
- Let's use key presses to change how a thing moves

## Snake: Problems to solve

We can do things like fill the screen and draw a border. There are new problems that need resolving: What are they?

1. **Moving a snake 1**
A Snake is made of at least 1 segment and moves around the screen at speed. It has a location and appearance. It reacts to inputs.

2. **Showing and updating a score**
A score is an amount that grows as you play and appears on screen all the time.  

3. **Moving a snake 2: segments**
The snake has more than one segment. It has to be able to grow. It has to turn corners and have the body follow the path of the apparent 'head'
  3a. Defining a snake as many segments
  3b. Segments appearing to following snake head

4. **Making Fruit**
   4a. Defining fruit 
   4b. We've drawn random pixels, apply it to generating fruit locations 

## Making and moving the snake 1

  a. Getting keyboard input realtime
  b. Defining a snake
  c. Defining a segment
  d. Moving a snake (on segment)
  e. Refreshing screen
  f. Controlling game speed/update

## The score
A score is an amount that grows as you play and appears on screen all the time.
  a. Adding a score variable
  b. Drawing "Score: x" to screen every frame

## Moving the snake 2: segments

  a. 