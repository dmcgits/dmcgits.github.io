# Week 5: Design Patterns

Programming leads to lots of code. Lots of code leads to lots of files and objects and madness. 

> Design patterns are abstract ways of thinking about big programs and saves us from madness.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Week 5: Design Patterns](#week-5-design-patterns)
	* [Assessment 1 due end of this week.](#assessment-1-due-end-of-this-week)
		* [Encapsulation exercise](#encapsulation-exercise)
		* [Inheritance/Polymorphism exercise](#inheritancepolymorphism-exercise)
		* [Engine Implementation](#engine-implementation)
	* [Design patterns and the Gang Of Four](#design-patterns-and-the-gang-of-four)
		* [Patterns in Game Design](#patterns-in-game-design)
	* [Static functions and variables](#static-functions-and-variables)
		* [I lied about classes](#i-lied-about-classes)
		* [Using statics to make utility classes](#using-statics-to-make-utility-classes)
			* [What are Unity API calls](#what-are-unity-api-calls)
			* [Our utility class, Helpies](#our-utility-class-helpies)
		* [Singletons](#singletons)
		* [Example of needing to access an important object.](#example-of-needing-to-access-an-important-object)
			* [Singleton code](#singleton-code)
			* [Singletons work because of statics](#singletons-work-because-of-statics)
	* [Exercises](#exercises)
	* [Resources](#resources)
			* [gameprogrammingpatterns dot com:](#gameprogrammingpatterns-dot-com)
			* [Do factory](#do-factory)

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

## Static functions and variables

If you've ever used a unity api function without creating an object, say `Mathf.Round(number)`, or `Camera.main`, or `Input.mousePosition`, you've used a static function/variable. Classes like `Mathf` and `Input` can be thought of as utility classes. You don't make objects out of them, you use them .

### I lied about classes

Sort of. For most purposes yes, classes are simply designs that are made real in the form of objects. But it turns out it's useful to be able to call functions on classes without wasting cycles and memory creating objects. The way to achieve this is with static functions. 

### Using statics to make utility classes

Sounds a lot like something we might do in an assessment. Let's look at how we can enclose a couple of _Unity API_ calls in a single function, and call it from an object.

#### What are Unity API calls

> **API** stands for **Application Programming Interface**. What it actually means is **a way to control something with code**. Whether it's facebook's platform and user data, or an arduino, or the unity game engine. They write a bunch of code that does amazing things, and then give us a bunch of functions we can call to control it.

The Unity API is documented here:
<https://docs.unity3d.com/ScriptReference/>

![Unity API reference for Camera.main](assets/week5/unity_api_camera.png)

It's dead easy: you look up the Camera class, find a function you need, and they explain it. They have source code too. All those autocomplete suggestions in Unity when you type Transform or Camera or Vector3? They're all fully explained and demonstrated.

#### Our utility class, Helpies

[week5_code_utility.html](week5_code_utility.html)

![Utility test: pointy](assets/week5/utility_pointy_unity.png)

### Singletons

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

1. Finish the assignment!
2. Catch up on Sololearn, you need a certain amount of _c#_ to be automatic. Time you lose looking up basics, or on confusing errors, that's all potential coding time gone.

## Resources

More detail on what we've covered here today. If a pattern  sounds like a good thing to use in assessment 2 or 3, go read more about it.

#### gameprogrammingpatterns dot com:

Easy to read, gaming focussed.

1. <http://gameprogrammingpatterns.com/component.html>
2. <http://gameprogrammingpatterns.com/double-buffer.html>
3. <http://gameprogrammingpatterns.com/subclass-sandbox.html>
4. <http://gameprogrammingpatterns.com/type-object.html>
   
#### Do factory
 Has loads of patterns explaine in c#/.net
 <https://www.dofactory.com/net/design-patterns>
