#GPR103 week3 - Inheritance and Polymorphism.

Designing objects with reuse and extension in mind.

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [GPR103 week3 - Inheritance and Polymorphism.](#gpr103-week3-inheritance-and-polymorphism)
	* [Last week and homework](#last-week-and-homework)
	* [Inheritance](#inheritance)
		* [Examples of inheritance](#examples-of-inheritance)
		* [Why inheritance in programming?](#why-inheritance-in-programming)
		* [Towers to build](#towers-to-build)
			* [Base Tower](#base-tower)
			* [Tower.cs](#towercs)
			* [Unique towers](#unique-towers)
			* [GattlingTower.cs](#gattlingtowercs)
			* [MissileTower.cs](#missiletowercs)
	* [Polymorphism](#polymorphism)
	* [Assignment 1 part 2](#assignment-1-part-2)
	* [Virtual/Abstract functions](#virtualabstract-functions)
	* [Overriding functions](#overriding-functions)
	* [Exercises](#exercises)

<!-- /code_chunk_output -->

## Last week and homework

Last week's topic was **Object oriented design**, specifically **Encapsulation through Classes, Access Modifiers, Properties**

Part 1 of assignment. 
* Did we get there? 
* Did it make more sense once you'd translated the ideas to your own Class vs copying the FireballTower.
* Did you come up with questions? If you answered them, where did you go for answers? Unity videos, Microsoft docs?
* Questions about wording?

## Inheritance

Humans are pattern seeking machines. **We look for things that are related, we group them, and then we find heirarchies to put them in**. Inheritance here is less the idea of recieving your parents property and more your inheritance of their genes. You have what they had, modified.

> Inheritance in programming is receiving the properties and abilities of another class/object while adding your own on top, and even modifying/replacing some of what you received.

It's like genetic inheritance, but it's also like how products/designs inherit elements from earlier products. Or how a PC inherits all the stuff Intel put in the CPU and chipset. 

We can do this because of the **encapsulation** we did last week. How on earth would you even approach this if things weren't globbed into Classes?

### Examples of inheritance

![Controller Geneology](assets/week3/controllers_geneology.jpg)
_Blurry but lovingly made geneology of controllers - [Casey Bisson](https://www.flickr.com/photos/maisonbisson/2646315272/)_

Nintendo have been real diversity generators of console controllers. The NES pad created a new family, then the SNES pad with shoulder buttons, the N64 controller with its analogue sticks. Each set the stage for the next, old features rarely disappeared.

>Classic programming class examples are `Canine::Dog::Labrador`, `Vehicle::Car::Hatchback::Jazz`. Notice `Canine` and `vehicle` are both fairly abstract; mostly words you see on forms. With each stage you get more concrete.

Game engines evolve too. Here's a link to one tree of FPS engines: [fps engine inheritance](assets/week3/fps_geneology.png)

### Why inheritance in programming?

1. It helps us think about things. We can break a program down into units and understand their relationships. Especially true in games, which are basically simulations of (parts of) worlds.
2. Avoids loads of duplicated code. If you have to change something basic about towers, like the code to click on them or place them, who wants to change every single tower type? 
3. Inheritance gives you stuff for free. Who doesn't love free stuff?
4. Extending (inheriting from) a class lets you take something useful but generic and make it more specific. 
   
### Towers to build

We had a Fireball Tower last week. This week we're cloning Field Runners 2 and want a **Gattling (gun) Tower** and a **Missile Tower**. 

![Gattling](assets/week3/tower_fr_gattling.jpg)
_Gattling guns are the spinny ones_

![Missiles](assets/week3/tower_fr_missile.jpg)
_Missiles in an array (hint?)_

**1:** Gattling fire is effectively hitscan (instant hit), missiles are projectiles
**2:** Bullets travel in a straight line. Missiles can course correct, home in.
**3:** Gattling fire is nonstop. Missiles fire in volleys.
**4:** Gattling towers add guns. Missile towers just shoot faster.

___

#### Base Tower

It's pretty obvious that we'll be starting from the base `Class Tower` here and extending it. What's common to both towers? 

**Class: Tower**
* Attributes (information):
  * `health`, `position`, `currentLevel`, `ready` (not building/levelling up)
* Functions:
  * `build()`, `collapse()`, `levelUp()`
  
We won't go nuts and define a full game ready tower for this exercise.

#### Tower.cs
```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Tower : MonoBehaviour
{
	protected int _health = 100;
	protected Vector2 _position;
    protected int _level = 1;

    public Tower()
    {
        
    }
    
    void Start() {
    }
    
    public void Build(Vector2 position)
    {
        _position = position;
    }

    public void levelUp()
    {
        Debug.Log("Levelling up");
    }
    
    public int CurrentLevel
    {
        get { return _level; }
    }

	public int Health
	{
		get { return _health; }
		set { _health = value; }
	}

    private void Collapse()
    {
        Debug.Log("Collapse.");
    }

}

```

> Some **terms used for a base class**: parent, ancestor, base, super.

___
#### Unique towers

Now our derived classes. Each is "derived" from Tower.

>**Class GattlingTower**:
>  * `turrets`, `damagePerSecond`
>
>**Class MissileTower**:
>  * `pods`, `firingRate`, `damagePerProjectile`, fire()

![Gattling Tower](assets/week3/sprite_gattling_tower.png)

#### GattlingTower.cs

```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GattlingTower : Tower {

	protected int _turrets = 1;
	protected int _damagePerSecond = 8;

	// Use this for initialization
	void Start() {
		Debug.Log("I am Gattling.");
	}
	
	public int DamagePerSecond
	{ 
		get { return _damagePerSecond; }
	}
	
}

```
![Missile Tower](assets/week3/sprite_missile_tower.png)
#### MissileTower.cs

```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MissileTower : Tower {

	protected int _firingRate = 1;
	protected const int NUM_PODS = 9;
	protected float _damagePerProjectile = 1.0f;

	// Use this for initialization
	void Start() {
		Debug.Log("I am Missile.");
	}

	public float DamagePerProjectile
	{
		get { return _damagePerProjectile; }
		//set	{ _damagePerSecond = value;	}
	}

	public int FiringRate
	{
		get { return _firingRate; }
	}

	protected void Fire()
	{
		Debug.Log("Fire!");
	}
}

```
 
> **Food for thought:** both towers **track** their opponents, but some won't. Where do we implement it? Doesn't really belong in a generic tower, but also duplication is bad. This is where `Class TrackingTower` might come up. Or we might want to mix inheritance and composition designs.

## Polymorphism

One thing taking on multiple forms.

![Bludgie](assets/week3/pokemon_bludgie.png)
_They're all Bludgie though really - Aussie Pokedex by Paul Robertson_

A bunch of towers can all return a type, a cost, an id, a footprint. They can be asked to level up, take damage, build, collapse/refund. We don't need to know what type of tower we have for those generic things. That means we can handle them in a collection as plain old Towers - using them as their base class.

_**Busted example, change to public list. Can't use prefab instantation.**_

```cs
// List uses base type `Tower` even though we never make an instance of `Tower` directly.
List<Tower> towers = new List<Tower>();

// We can add in anything that extended/derived from `Tower`
towers.add(new GattlingTower());
towers.add(new MissileTower());

towers[0].build();
```

A bit like boxes can be stacked regardless of contents, or a bottle of softdrink stored, cooled, poured.

## Assignment 1 part 2

Polymorphism! Creating a **base class and 3 derived classes**. Store them in an **array of their base type**, and  **call functions**. Use and **override** a **virtual function**.

This should be a [link to pdf brief on blackboard](https://laureate-au.blackboard.com/bbcswebdav/pid-7197505-dt-content-rid-11808948_1/xid-11808948_1). Make sure you're logged in to blackboard, and message me if it's not working.

## Virtual/Abstract functions

You can see then that a function we want to be in all children, like build(), might not have any need for code in the root Tower class. It's kind of a template to build all the towers off.

> We could make an empty function and put a comment asking all other coders to make sure to override it with their own code. But they might miss/ignore the comment.

What's better than asking? Forcing!

The `abstract` keyword lets us define a function with no content. It also fails to compile unless the function is overriden by any Class that inherits from it.

```cs

virtual example
```

## Overriding functions

> How do you make a function that has already been defined? **Override** it.

## Exercises

1. Watch the videos and type out the code in these Unity tutorials on inheritance, polymorphism, method overriding and collections (lists/dictionaries)
   * <https://unity3d.com/learn/tutorials/topics/scripting/inheritance?playlist=17117>
   * <https://unity3d.com/learn/tutorials/topics/scripting/polymorphism>
   * <https://unity3d.com/learn/tutorials/topics/scripting/overriding?playlist=17117>
   * <https://unity3d.com/learn/tutorials/modules/intermediate/scripting/lists-and-dictionaries?playlist=17117>
2. Complete part 2 of assignment 1.

