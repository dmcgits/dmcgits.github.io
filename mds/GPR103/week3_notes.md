#GPR103 week3 - Inheritance and Polymorphism.




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

```cs
Class Tower
{

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

```cs
Class GattlingTower : Tower
{

}

Class MissileTower
{

}
// code for GattlingTower, MissileTower
```
 
> Food for thought: both are **tracking** towers. Doesn't really belong in a generic tower, but also duplication is bad. This is where `Class TrackingTower` might come up.

## Polymorphism

One thing taking on multiple forms.

![Bludgie](assets/week3/pokemon_bludgie.png)
_They're all Bludgie though really - Aussie Pokedex by Paul Robertson_

A bunch of towers can all return a type, a cost, an id, a footprint. They can be asked to level up, take damage, build, collapse/refund. We don't need to know what type of tower we have for those generic things. That means we can handle them in a collection as plain old Towers - using them as their base class.

```cs
// List uses base type `Tower` even though we never make an instance of `Tower` directly.
List<Tower> towers = new List<Tower>();

// We can add in anything that extended/derived from `Tower`
towers.add(new GattlingTower());
towers.add(new MissileTower());

towers[0].build();
```


A bit like boxes can be stacked regardless of contents, or a bottle of softdrink stored, cooled, poured.

### Abstract

You can see then that a function we want to be in all children, like build(), might not have any need for code in the root Tower class. It's kind of a template to build all the towers off.

> We could make an empty function and put a comment asking all other coders to make sure to override it with their own code. But they might miss/ignore the comment.

What's better than asking? Forcing!

The `abstract` keyword lets us define a function with no content. It also fails to compile unless the function is overriden by any Class that inherits from it.

```cs

abstract example
```