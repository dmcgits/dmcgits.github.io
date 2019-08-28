# Week 12 - work on assessments!


##  Reminders of marking points

Things from brief 

###  Conventions

Stick to them and win marks! Also be a better coder!

### QA Mis Com

Anything you need help with?


##  Git

Let’s al commit our changes and push. Do it daily!

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

###  Profiling

Is your game crawling despite the beefy machine? Don’t guess what’s causing it, run the Unity Profiler.

https://docs.unity3d.com/Manual/ProfilerWindow.html
![profiler](https://docs.unity3d.com/uploads/Main/ProfilerWindow2.jpg)

Track down what’s killing your performance. Is your missile masking 100 missiles below because of a bug? Is there a loop in a loop generating thousands of debug messages?
