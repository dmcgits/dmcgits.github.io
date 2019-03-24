# Games Programming Week 4

Programming leads to lots of code. Lots of code leads to lots of files and objects and madness. 

> Design patterns are abstract ways of thinking about big programs and saves us from madness.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Games Programming Week 4](#games-programming-week-4)
	* [Assessment 1 due end of this week.](#assessment-1-due-end-of-this-week)
		* [Encapsulation exercise](#encapsulation-exercise)
		* [Inheritance/Polymorphism exercise](#inheritancepolymorphism-exercise)
		* [Engine Implementation](#engine-implementation)
	* [Design patterns and the Gang Of Four](#design-patterns-and-the-gang-of-four)
		* [Patterns in Game Design](#patterns-in-game-design)
	* [Singletons](#singletons)
		* [Example of needing to access an important object.](#example-of-needing-to-access-an-important-object)
			* [Singleton code](#singleton-code)
			* [Singletons work because of statics](#singletons-work-because-of-statics)
	* [Exercises](#exercises)
	* [Resources](#resources)
			* [Gang of Four?](#gang-of-four)
			* [Singletons](#singletons-1)
			* [gameprogrammingpatterns dot com:](#gameprogrammingpatterns-dot-com)

<!-- /code_chunk_output -->


## Assessment 1 due end of this week.

Yes, it is **due end of Sunday, March 31.** 
These are brief reminders, in my own words, of what is in each exercise. READ THE PDF BRIEF CAREFULLY.
**[Assessment 1 pdf on the server](https://laureate-au.blackboard.com/bbcswebdav/pid-7197505-dt-content-rid-11808948_1/xid-11808948_1)**

You are delivering 3 Exercises:

### Encapsulation exercise
 Create the `Player` class which is tested by a test class, eg: `TestPlayer`. If you're at all confused about this [do the exercise in week 2's notes.](https://dmcgits.github.io/mds/GPR103/week2_notes.html?nocache#access-functions-aka-properties). It creates a test class, puts it on a sprite, and uses it to create and test a class.

### Inheritance/Polymorphism exercise
 Create a base `Class` with variables and functions. Create classes that derive from it. `Override` a `virtual` function. Put the different child classes in one `List` and iterate over them, calling a function. Almost exactly what we did in [week 3 in the section on polymorphism](https://dmcgits.github.io/mds/GPR103/week3_notes.html#polymorphism). The classes themselves are up to you. Inventory items, types of spells, types of door lock, whatever.

### Engine Implementation
You need to create a `Class` that provides a useful, fairly generic function. This function should make use of **at least 2 Unity API calls** and return a result. Having it call multiple Unity API calls instead of just one is what makes it useful.. otherwise we'd just make the api call. Create a **test class** that shows this off running in the engine.
**We'll write out an example of this today using a Singleton or a static class.**

____

## Design patterns and the Gang Of Four

Design patterns, a group of dudes called the Gang Of Four. In the photos they turned out to be disappointing. You've seen kinda pudgey white programmers from the 80s. So imagine there were 6 and this is them:

![special six](assets/week5/special_six.png)
_Programming patterns were based on animal movements._

### Patterns in Game Design

* Game Loop (game logic)
* Double buffering (graphics)
* Composition - Unity components
* Type Object - A little like composition. A way to create variants from a text file rather than a million class definitions.
* Subclass Sandbox - beats me. [Better read.](http://gameprogrammingpatterns.com/subclass-sandbox.html)
  
___

## Singletons

Make a singleton. I can be called handyutils. Because I want it to have some state, I'll make it a singleton, not a static.
GetAngleFromAToB
___

### Example of needing to access an important object.
Some code showing two different classes in two different places that need to access the game model. How do they to that? If they each make one, it'll be different. Do all classes have to know how to find it? What if that method changes?

#### Singleton code

#### Singletons work because of statics

Statics are like exceptions to the rule of encapsulation. Instead of every chair object being unique, imagine all chairs had a single component, say the cushion, and if you damaged one cushion you damaged them all. It's like quantum entanglement.

___

## Exercises

Finish the assignment!
Catch up on Sololearn, you need a certain amount of _c#_ to be automatic or you'll lose programming time to googling-errors time

## Resources

#### Gang of Four?

#### Singletons

#### gameprogrammingpatterns dot com:

1. <http://gameprogrammingpatterns.com/component.html>
2. <http://gameprogrammingpatterns.com/double-buffer.html>
3. <http://gameprogrammingpatterns.com/subclass-sandbox.html>
4. <http://gameprogrammingpatterns.com/type-object.html>