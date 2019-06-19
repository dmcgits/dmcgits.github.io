---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Clarification of exercise 1

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Clarification of exercise 1](#Clarification-of-exercise-1)
  - [Original brief](#Original-brief)
  - [Clarified](#Clarified)

<!-- /code_chunk_output -->

## Original brief

The original brief for Assessment 1 Exercise 1 has a few ambiguities that caused people trouble last trimester. I've trried not to change the actual task, just clarify it.

[Original PDF Direct Download](https://laureate-au.blackboard.com/bbcswebdav/pid-7523974-dt-content-rid-11808948_1/xid-11808948_1)

## Clarified

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
