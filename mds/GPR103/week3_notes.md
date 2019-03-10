GPR103 week3

Talk about last homework

Quick revise?

## Inheritance

Humans are pattern seeking machines. We look for things that are related, we group them, and then we find heirarchies to put them in. Inheritance here is less the idea of recieving your parents property and more your inheritance of their genes. You have what they had, modified. 

> Inheritance in programming is receiving the properties and abilities of another class/object while adding your own on top, and even modifying/replacing some of what you received.

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
   
### Tower

We had a Fireball Tower last week. This week we're cloning Field Runners 2 and want a **Gattling (gun) Tower** and a **Missile Tower**. 

![Gattling](assets/week3/tower_fr_gattling.jpg)
_Gattling guns are the spinny ones_

![Missiles](assets/week3/tower_fr_missile.jpg)
_Missiles in an array (hint?)_

**1:** Gattling fire is effectively hitscan (instant hit), missiles are projectiles
**2:** Bullets travel in a straight line. Missiles can course correct, home in.
**3:** Gattling fire is nonstop. Missiles fire in volleys.
**4:** Gattling towers add guns. Missile towers just shoot faster.

### Polymorphism

A list of towers can all return a type, a cost, an id, a footprint. They can be asked to level up, take damage, build, collapse/refund. If you're doing those generic things, you don't need to know what type of tower you have.

A bit like boxes can be stacked regardless of contents, or a bottle of softdrink stored, cooled, poured.

### Abstract

You can see then that a function we want to be in all children, like build(), might not have any need for code in the root Tower class. It's kind of a template to build all the towers off.

> We could make an empty function and put a comment asking all other coders to make sure to override it with their own code. But they might miss/ignore the comment.

What's better than asking? Forcing!

The `abstract` keyword lets us define a function with no content. It also fails to compile unless the function is overriden by any Class that inherits from it.

```cs

abstract example
```