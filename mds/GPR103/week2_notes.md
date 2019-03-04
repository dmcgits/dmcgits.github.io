# GPR103 Week 2 (module 1.2)

Object oriented design principles.
> **Quick definitions:**
> * Encapsulation: putting data/code that go together into a capsule (class).
>    * Cohesion: When the stuff in that capsule really does belong together  
>    * Coupling: when a class reaches too specifically into another can be easily broken by changes in that class.
> * Abstraction: The outside view of encapsulation. You see the simplest controls: the interface.

Super quick 
## Encapsulation 

At the heart of OOD is encapsulation. The word has many syllables, but it embodies two simple things we see every day. 

![kinder](assets/week2/kinder_surprise.jpg)
_capsule: a thing with things inside_

And it's what we expect of all the tools in our every day life: **Hide the bits I don't need to know about**

![shaver real](assets/week2/shaver_real.jpg)
![shaver patent](assets/week2/shaver_patent.jpg)
_outside v inside_

### Maximum encapsulation is not a virtue in itself

The answer to most any interface question is: it depends. If you only open and read things on your computer, an Apple magic mouse is a very nice thing. If you play mobas, you might live or die by your razer naga. If you live the office live, a microsoft mouse is a safe middle ground. It's not good vs bad, it's appropriate vs inappropriate.

![magicmouse](assets/week2/mouse_magic.jpg)
![naga](assets/week2/mouse_naga.jpg)
![rat](assets/week2/mouse_rat.jpg)
_!!_

## Classes and Objects refresher

Objects are the basic way we bundle up data, say our player data, with the code that acts on it. eg `health`, `TakeDamage()`, `fireMana`, `waterMana`, `castSpell(whichSpell)`.

Classes: thing in itself, the definition. The recipe, the blueprint.

Objects: a physical, individual thing made from a class. So if you have a chair design, you might have 4 real chairs based on that at your dinner table. One has a slightly softer cushion, one has a ding in the leg, one is mum's favourite. The design never has these real world properties, only ideal values.

### Good cohesion

Examples of things that are moderate/high cohesion. Definitions are a bit abstract, maybe examples like xboxController and ps4Controller as implementations of consoleController

## Details of strong encapsulation

How do we encapsulate our code and data in practise?

### Scope

Scope (simplified) is where variables are only invisible inside the code blocks {} in which they're defined. If a variable is defined in a for loop, it doesn't exist outside it. In a function, only code in the function can see it.

```cs
    int age = 5;

    function setAge(int newAge = 3)
    {
        int localAge = newAge;
        age = localAge; // fine
        
        // draw x things
    }

    function talk() 
    {
        Debug.Log(drawnThings); // error, variable not defined
        Debug.Log(newAge); // also bad.
        Debug.Log(age);  // Logs "5" to console
    }
}
```
### Access modifiers vs access methods (properties)

**Access modifiers** are what we've used so far to allow/bar access to the delicate insides of a class. They offer control, they're vital. They're also dumb. Once they're defined they never react to change, like a sign on a gate. 

```c++
    // public: any class has access
    public int name;

    // protected: any class that inherits this one has access
    protected int weight;

    // private: Only this class has access
    private int health_ = 0;

    // no modifier: defaults to private
    int speed_ = 0;

    // public const: we can make it public while preventing
    // others changing.. but we can't change it either.
    public const int MAX_HEALTH = 100;

```

**Access methods** (aka setters/setters aka properties) are more like a security guard. They do the same job but react to changes and apply conditions.

> **In game situation:** An arrow is going to hit our Orc Rogue for 20 damage and she has 15 health. How do we avoid ending up with negative health?

Translated to a **Coding problem:** 
1) Control what player health values can be set. 
2) Has a set range 0-100 for example
3) Sometimes though, that's modified by enchancements/poisons. 

One way is to **allow an enemy arrow to do the check**:
  * it looks at our minimum health
  * it adjusts its damage to match health left. 
  
Seems ok for the first weapon, but **becomes a huge mess later**: anything damaging the player has to worry about our health range. It's waaaay to many chances for a human coder to mess up, and not the arrow's problem

**The solution is a private health variable and a public setter function.** We'll need a getter now too. Psuedocode:
```
    Class Player
    ...
    function SetHealth ( amount )
        if amount is outside 0-100 range
            set health to nearest limit of range
        otherwise
            set health to amount    

    function GetHealth ()
        return health
```
It's such a useful and common solution, c# has built in syntax to tidy it up and make errors less likely.

```cs
using System;

public class Player
{
   private int _health;

    // no need to write SetHealth(int value), GetHealth()
    // with correct function definitions etc
   public int Health 
   {
        get { return _health };
        set {
            if (value < 0) _health = 0;
            if (value > 100) _health = 100;
      };
   }

   public void takeDamage( int damage )
   {
       // we can pass use the accessor methods ourselves here
       // It's tidier than calling functions too.
       Health -= damage;
   }
```

## Did we understand the lingo and ideas of OO design? 

This week we're going to be doing the the first part of assignment 1, the Killer Robot exercise. Can we now translate the requirements?

>- Initialising members to appropriate default values. 
>- Constructor and Destructor 
>- Separate interface from implementation
>- "private member variables"
>- "accessor methods (properties)"

I'll let you try it yourself, but if you don't get them just ask.


## Reminder of code basics places to learn. 
Rather than having me speed through conditionals and loops, jump into the sololearn app and drill on these fundamentals. Too fast for new coders, too slow for c++ people.

## Exercises to do before next class

1. Assessment progression - Killer Robot Exercise
   * The exercise: [week2_exercise_killer_robot.html](week2_exercise_killer_robot.html)
   * You need to use an Enum in this exercise, so have a look at [this enums tute](https://youtu.be/ETy3x4XeK9E?t=58). Skip first minute.

2. UML stuff
