# Week 10 - Finding things, Reusing things, shooting things


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 10 - Finding things, Reusing things, shooting things](#week-10---finding-things-reusing-things-shooting-things)
  - [Todo before next lecture](#todo-before-next-lecture)
  - [Resources](#resources)
  - [Laying out our game](#laying-out-our-game)
    - [Things we may need in our game](#things-we-may-need-in-our-game)
    - [Finding those things](#finding-those-things)
  - [Talking to and commanding things](#talking-to-and-commanding-things)
    - [SendMessage](#sendmessage)
    - [BroadcastMessage](#broadcastmessage)
    - [Events](#events)
    - [GetComponent and call functions](#getcomponent-and-call-functions)
  - [Prefabs](#prefabs)
  - [Expanding the things we might need](#expanding-the-things-we-might-need)

<!-- /code_chunk_output -->


## Todo before next lecture

## Resources

## Laying out our game

Sometimes we can't solely create everything in our game model/manager and adjust the stage to suit. It's handy to lay out things visually. But to benefit from that, we need to gather info about items on the stage. How can we do that and avoid noodly confusion?

### Things we may need in our game

Well, before we get into how we'd find things, lets consider things we might need to find in our game.

* alienBatteries
* playerBatteries
* cities
* AlienMissile
* PlayerMissile
* Planes
* ScoreText
* DefendPrompt

### Finding those things

Instead of setting positions in our model using an array or reading from a text file, let's read from the scene. Those of you who watched last weeks video will remember some of these

#### Inspector variables

`public vector3 location` or `[SerializeField]` are familiar friends since weeks 2/3. 

#### Creating things

If an object creates another, it stores it as a variable.

#### Events

We can listen for events, and objects can pass us information, whole components, or their whole selves (`GameObject gameObject`).

#### Find By Name

#### Find By Tag

#### Find By Type

#### Singleton

You can now probably see the benefit of a singleton. Access objects in the scene from anywhere. That singleton of course will have to find all the objects too, but it does all of that and all other objects grab from it.

```cpp

GameObject battery_1 = GameManager.instance.Batteries[GameManager.BATTERY_1];

```
## Talking to and commanding things

There are more ways than we've used so far to inform and  command objects 

### SendMessage

### BroadcastMessage

### Events

### GetComponent and call functions

## Prefabs

## Expanding the things we might need

In missile command there are  good few objects, and we need to figure out their properties.

Luckily this isn't a code exercise, it's just imagination and things we know about games.

**alienBatteries**
  - position

**playerBatteries**
  - position
  - capacity
  - MissileCount
  - Id (1, 2, 3. Match mouse button)
  - isOnline
  - collider

**cities**
  - position
  - isDestroyed
  - collider

**AlienMissile**
  - start Pos
  - Direction/angle
  - Speed
  - Trail
  - OnLaunched
  - OnHitSomething
  - explode
  - collider

**PlayerMissile**
Prefab with long tail rect with emissive mat
 - start Pos
 - StartBattery
  - Direction/angle
  - Speed
  - Trail
  - OnLaunched
  - OnHitSomething
  - explode
  - collider

**Planes**

**ScoreText**



