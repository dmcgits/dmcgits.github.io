# Clarification of exercise 1

I've chatted to a few people and **exercise 1 still has ambiguity problems**. Looking at it myself I can see two ways, and both need clarifying. 

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Clarification of exercise 1](#clarification-of-exercise-1)
	* [Two valid interpretations](#two-valid-interpretations)
	* [1: In class interpretation:](#1-in-class-interpretation)
	* [2: How I think it was probably intended](#2-how-i-think-it-was-probably-intended)

<!-- /code_chunk_output -->

## Two valid interpretations

My goal is to **solve any final problems you guys are having by being more specific about both interpretations**:  

>1. The way we spoke about it in class 
>2. How I now think it was probably intended and maybe some of you did too. 

My goal is not to make you change it from interpretation 1 to 2 or vice versa. Both are ok at this stage.

On the other I hand I do think **you should be very close to one of these two or you're off track**. If so please message me asap so we can discuss it.

## 1: In class interpretation:

> A class of type `Player`:

**It contains:**

1. A player's **name**: hidden inside class, 
2. A player's **health**: hidden inside class 
3. A **damage modifier**: hidden in the class and increases or decreases **incoming damage**. Think buff or poison.
4. A **constructor** that sets initial values for name, health, incoming damage modifier

**It exposes the following functionality** to other classes like `PlayerTester`: 	

1. **Read the player's name** via a function that returns it
2. **Affect the player's health** by a function called `ReceiveDamage()`. (remember the modifier)
3. **See the state of the player's wellbeing**. This could be seeing the health value or seeing a damage value. In that case I'd see a damage value as how much health they've lost from full health, maybe a percentage. 

> A class of type `PlayerTester` 

It does the following:
1) Creates an object from the Player class;
2) Prints out the player's health to the console
3) Does damage to the player
4) Prints out the player's health again to the console

## 2: How I think it was probably intended

> A class of type `Player`:

**It contains:**

1. The player's **name**: hidden inside class, 
2. The player's **health**: hidden inside class 
3. The player's **damage output per attack**: hidden inside class
4. A **damage output modifier**: hidden in the class and increases or decreases their damage dealt. I imagine a positive affect on damage dealt from an equipped item like a (hypothetical) ring of strength, or a negative affect from an unhealed injury.
5. A **constructor** that sets initial values for name, health, output damage, output damage modifier.

**It exposes the following functionality** to other classes like `PlayerTester`: 	

1. **Read the player's name** via a function that returns it
2. **See the player's health** but not modify it directly
3. **Call a "ReceiveDamage" function** on a player instance, which affects their health
4. **See the player's damage per atttack** but not modify it. That would take some sort of equipped item or injury.

> A class of type `PlayerTester` 

It does the following:
1. Creates an instance of (an object from) the Player class;
2. Prints out the player's health to the console
3. Does damage to the player
4. Prints out the player's health

It's also fine if you want to:

5. Print out the player's damage per attack