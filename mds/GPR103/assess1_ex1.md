# Assessment 1 Exercise 1

Implement code that demonstrates the principle of encapsulation based on the spec below.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Assessment 1 Exercise 1](#assessment-1-exercise-1)
	* [Requirements](#requirements)
	* [Goals](#goals)
	* [Recommendations](#recommendations)
	* [Specification](#specification)

<!-- /code_chunk_output -->


## Requirements
* Program in either C#/ Unity or C++/SFML. Using appropriate project structures to effectively test and run the solution.
* Build the exercise to an executable.
* For the assignment you'll submit your project and also a build.

## Goals
* Use appropriate access modifiers and properties 
* Use console (Debug.Log) outputs in place of game functionality to test encapsulation and access.
* Initialise variables suitably
* Separate interface from implementation

## Recommendations

*  Block it out on paper first, or in a drawing app.
*  Psuedocode it. Once I figure out the classes I need and their variables, I often drop in function names and write the pseudocode as comments. Then replace it with c#.
*  Use lots of comments in your code to explain your thinking.

## Specification

> Make the following:

1. A Player class which has the following attributes.
   * Player Name
     * Hidden within class accessible through a function that returns the value.
   * Player Health
     * Hidden within class but can be modified through an accessible method (i.e ReceiveDamage()).
   * Player Damage
     * Visible outside fo class but not readable
   * Player Damage Modifier
      * Hidden in the class, this value can alter the amount of damage taken. Like an armour effect.
    * A Class Constructor that sets initial values for name, health, damage and damage modifier.

2. A Test Class, basically a game manager class, which:
     * Creates an instance (new object) of the Player class.
     * Does damage to the player through appropriate function/property.
     * Outputs the player health the console before and after the damage (with meaningful messages). 
