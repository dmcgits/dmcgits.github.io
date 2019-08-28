---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Week 12 - work on assessments!


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 12 - work on assessments!](#week-12---work-on-assessments)
  - [Reminders of marking points](#reminders-of-marking-points)
    - [Conventions](#conventions)
  - [Git](#git)
  - [QA Mis Com](#qa-mis-com)
  - [Scoring](#scoring)
    - [Scoring Manager](#scoring-manager)
  - [Profiling](#profiling)

<!-- /code_chunk_output -->


##  Reminders of marking points

Things from brief 

###  Conventions

Stick to them and win marks! Also be a better coder!

```cs {.line-numbers}
// GPR103 class coding conventions
// Based on common conventions for C#
// This is a series of examples. All in one file it wouldn't compile.

// Classes, the recipes for objects
// Lead with upper case, use again for subsequent words
public class AttackShip : SpaceShip // AttackShip extends the 
{
	...
}

// constants, numbers that won't change.
// Use ALL_UPPER_CASE with underscores replacing spaces
const int LIVES_REMAINING_AT_START = 3;
const float HEADSHOT_DAMAGE_MULTIPLIER = 2.5f;
const string DEFAULT_INVITE_TEXT = "You have been invited to rumble.";

// Enums are weird. My approach is to name enums like classes,
// then name the constantslike regular constants :

public enum HealthWarnings
{
  CRITICAL = 10,
  LOW = 25,
  NEED_TOP_UP = 50
}

// However the proscribed way in c# (via the .net guidlines) is to use the same `Pascal` 
// case for the constants as for the name. I'll accept either.

public enum HealthWarnings
{
  Critical = 10,
  Low = 25,
  NeedTopUp = 50
}

// public variables. Variables that code outside a class can see.
// Start lower case, upper case for subsequent words
public:
	int score = 0;
	string myTag = "";
	string myRealName = "";
	Hat topHat; 		// "H" tells us H is a class, or type.
						// "t" tells us topHat is an instance/object.

// protected or private variables. Only seen inside class.
// Use an _ and start lower case, upper case subsequent words
protected: 
	float _baseDamage = 3.2f;
	string _secretPassword = "AndSheWas";
	BroadSword _mightyBroadSword;

// functions: whether public or private, name them as you would a class. 
// leading upper case, then upper case word beginnings. Note this differs from
// c/c++
float DamagePerSecond() 
{
	// Notice how you can immediately tell I'm using my private variables
	// to calculate a return value. The leading _ tells us.
	return (_damagePerAttack * _attacksPerSecond);
}

// function arguments: the same naming convention as public variables
// local function variables: also the same convention as public variables.
float DamagePerSecond(int shotType) 
{
  int damage = _damagePerAttack * _attacksPerSecond;

  if (shotType == HEAD_SHOT) 
  {
    damage *= HEADSHOT_DAMAGE_MULTIPLIER;
  }
  
  return (damage);
}

```

##  Git

Let’s all commit our changes and push. Do it daily!

## QA Mis Com

Anything you need help with?

## Scoring

How and were do you track scoring? 
* The score text and level end screen have points
	- they’re just displays
* Missiles, cities other things contribute to scoring but it’s none of their business

### Scoring Manager

There’s enough work in scoring to justify a manager.

* Manages the great book of scoring rules.

* Listens for happenings that cause scoring, including:
	* Alien missiles destroyed
	* Cities counted at level end
	* shells/rounds/ammo left

## Profiling

Is your game crawling despite the beefy machine? Don’t guess what’s causing it, run the Unity Profiler.

https://docs.unity3d.com/Manual/ProfilerWindow.html
![profiler](https://docs.unity3d.com/uploads/Main/ProfilerWindow2.jpg)

Track down what’s killing your performance. Is your missile masking 100 missiles below because of a bug? Is there a loop in a loop generating thousands of debug messages?
