---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Week 10 - Finding things, Reusing things, messaging

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 10 - Finding things, Reusing things, messaging](#week-10---finding-things-reusing-things-messaging)
  - [Woah, rewrite!](#woah-rewrite)
    - [Download the project](#download-the-project)
    - [Doing](#doing)
  - [Prefabs](#prefabs)
    - [Changing prefabs](#changing-prefabs)
    - [Individualising prefabs](#individualising-prefabs)
    - [Instantiating prefabs in code](#instantiating-prefabs-in-code)
  - [Finding the scene things](#finding-the-scene-things)
    - [Inspector variables](#inspector-variables)
    - [Creating things](#creating-things)
    - [Events](#events)
    - [GameObject find methods](#gameobject-find-methods)
    - [Find By Name](#find-by-name)
    - [Find By Tag](#find-by-tag)
    - [Find By Type](#find-by-type)
    - [Singleton](#singleton)
    - [GetComponent and call functions](#getcomponent-and-call-functions)
  - [More possible class attributes](#more-possible-class-attributes)

<!-- /code_chunk_output -->

## Woah, rewrite!

Since we learned a few things earlier this trimester and I've made a rough base/learning Missile Command project for you to pick through, this lesson has changed a bit! 

### Download the project

**I made some changes after Wednesday's class** to clarify things, reduce filesize and hide complexity. If you're quite confident in c#/Unity you could use the updated one without getting lost, but if not just grab the one blow it.

* Updated project
  <https://www.dropbox.com/s/4bo1vuz2psjzvrn/PlayerBatteriesUlt.7z?dl=1>
  * size reduced, removed asset packages
  * managers we don't need to really understand yet are hidden in `Later` folder
  * comments added, less relevant functions collapsed for clarity.  
  * cleaned up data types for prefab instantiation

* Unity project as taught to online class on Weds night:
  <https://www.dropbox.com/s/pqxy35eu1gq44e8/PlayerBatteries.7z?dl=1>

---

### Doing

How to make batteries, how to fire.
Demo of my game with waves and explosions.
Show how to make one part of it, discuss how to make more.
Go through some code but leave the rest to be explored. Add comments as I go through?


ideas: Prefabs, instantiation. Finding things in world with Find, getChildComponents. Classes for instances, like battery, and classes that manage (input man, battery man)


Tools:
assets in an unfinished project.
Making prefabs for batteries. 
battery manager script
battery script
Input script 
player Missile (dud)


Batteries could be sprites.

Very powerful tools this week.

---

## Prefabs

Take things you've built in the scene from parts and scripts, then reuse them.

* Make a new folder: Assets -> Prefabs
* Create->prefab
* Drag a thing from the scene heirarchy onto it.
* The thing in the scene is now an instance of the new prefab (text turned blue)
* Drag another from assets/prefabs to the stage to see it

![Making Prefabs](assets/week10/prefab_create.png)
_creating_

![Made used prefabs](assets/week10/prefab_made_used.png)
_duplicating or dragging from Assets

### Changing prefabs

Getting into our prefab and editing, propagating.

### Individualising prefabs

Do things have to all be the same? Is conformity the cost of reusability?

No, we can change our individual prefab instances a bit, and not apply the change. This is a deeper topic, so look into it and explore.

### Instantiating prefabs in code

Yes, you can spawn prefabs. That's one of their main use: peach trees, missiles, cherry pies, cherry pie customers, these are all things we'll be constantly spawning.

Lets look it up the details together. Google is our friend.
___

## Finding the scene things

There are quite a few things, and this isn't the dark ages so we want to use our visual layout from unity for position info at the very least.

> We can look at the objects, as placed, and get their position or any other info they contain. There are a number of ways.

Some of these were covered in the video I asked you to watch last week. If you did watch it you'll have the benefit of further engraving it into your memory, along with some new examples.

### Inspector variables

`public vector3 thingTransform` or `[SerializeField]` are familiar friends since weeks 2/3. 

### Creating things

If an object creates another, like we did with our Test and Player classes, it keeps a reference in a variable. That won't work for outside objects.

### Events

We can listen for events, and objects can pass us information, whole components, or their whole selves (`GameObject gameObject`).

___

### GameObject find methods

The GameObject offers a number of static methods that are very powerful. Those methods help it to act a bit like a higher level game manager that already has lists of everything in our game. **It can find them by name, tag, category and more**.

> GameObject find methods are slow/resource intensive. They're not something you do every frame. If you're going to use them, do it during awake or sleep and cache the results in a local variable.

### Find By Name

Search by the name in the inspector.

```cs
GameObject.Find("MissileTower_charlie");
```

### Find By Tag

Tags can be created and applied in unity as a way of grouping things without requiring other similarities to rely on (like sharing a component type). 

```cs
GameObjects[] spawnPoints = GameObject.FindObjectsByTag('Spawn');
```

### Find By Type

Searching by type is super handy: if you're looking for all your lightning towers, or any damageable items, just search for anything with that component.

I'm not sure how it goes with Polymorphism and finding LightningTower while looking for Tower, so we'll google it together.

```cs
GameObjects[] towers = GameObject.FindObjectsOfType<BaseTower>();
```

___

### Singleton

You can now probably see the benefit of a singleton. Access objects in the scene from anywhere. It's sort of like GameObject and the find functions, but you are making it from scratch and can structure it to your needs, along with custom functions.
That singleton of course will have to find all the objects too, using techniques above and others, but it does all of that and all other objects grab from it.

```cs

GameObject battery_1 = GameManager.instance.Batteries[GameManager.BATTERY_1];

```
___

### GetComponent and call functions

As we did with `SpriteRenderer.Sprite`. We can call these on current gameObject or on ones we have a reference to.

```cs
  void ExplodeAThing(GameObject thing)
  {
    thing.GetComponent<Explodeable>().Explode(); 
    // IRL we'd check the result of GetComponent before calling Explode
  }
```
___

## More possible class attributes

**PlayerBattery**
  - position
  - capacity
  - MissileCount
  - Id (1, 2, 3. Match mouse button)
  - isOnline
  - collider

**AlienBattery**
  - position

**City**
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

**Plane**

**ScoreText**



