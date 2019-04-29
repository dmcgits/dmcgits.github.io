# Week 10 - Finding things, Reusing things, shooting things


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Week 10 - Finding things, Reusing things, shooting things](#week-10-finding-things-reusing-things-shooting-things)
	* [Todo before next lecture](#todo-before-next-lecture)
	* [Resources](#resources)
	* [Laying out our game](#laying-out-our-game)
		* [Things we may need in our game](#things-we-may-need-in-our-game)
		* [Finding those things](#finding-those-things)
			* [Inspector variables](#inspector-variables)
			* [Creating things](#creating-things)
			* [Events](#events)
			* [Find By Name](#find-by-name)
			* [Find By Tag](#find-by-tag)
			* [Find By Type](#find-by-type)
			* [Singleton](#singleton)
	* [Talking to and commanding things](#talking-to-and-commanding-things)
		* [SendMessage](#sendmessage)
		* [`BroadcastMessage`](#broadcastmessage)
		* [Events](#events-1)
		* [GetComponent and call functions](#getcomponent-and-call-functions)
	* [Prefabs](#prefabs)
	* [Expanding the things we might need](#expanding-the-things-we-might-need)
		* [Drawover](#drawover)
		* [Attributes of our classes](#attributes-of-our-classes)

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

If you have a reference to a gameObject you can ask for a function to be called on any monobehaviour it has. This is useful if multiple components on one object with the same function, say `Update()` or `ApplyTeamColour(TeamColours.GREEN))`, or you want to make things Damageable with component, so they can `TakeDamage()`. 

This is handy for building things up in a modular way using components.

> <//https://docs.unity3d.com/ScriptReference/GameObject.SendMessage.html>

```cs
// More info in the unity docs
using UnityEngine;

public class Tester : MonoBehaviour
{
  public GameObject structure;

    void Start()
    {
        // Some structures are damageable, if they have a 
        // Damageable component. Try to do damage:
        structure.SendMessage("TakeDamage", 20);
    }
}
```
Here are components you'll find on the structure.
```cs
public class Damageable : Monobehaviour
{
  private int _health;

    // A public function that can 
    public void TakeDamage(float damage)
    {
      Debug.Log("Ow. Seriously, " + damage + " damage?");
      _health -= damage;
      // You can call sendmessage on other gameObjects or the current one.
      // If there's a component on this unit/structure that can change the visuals on damage, call it.
      gameObject.SendMessage(ShowDamage()); 
    }

    public int Health
    {
      get { return _health; }
      private set
      {
          // Prevent health going below 0.
          // If (value >= 0) _health = value, else health = 0 
         _health = (value >= 0) ? value : 0;
      } 
    }

}

public class DamagedArtController : Monobehaviour
{
  public void ShowDamage()
  {
    // swap the sprite, jump to an animation frame,
    // start particle smoke etc
    Debug.Log("showing damage");
  }
}
```
### `BroadcastMessage`

Similar deal to `SendMessage`, but it applies it to all components on the current object _and any child objects_ - anything in the scene heirarchy that this object is parent to. Note this function is local to the `Component/MonoBehaviour`, we don't need to use the `gameObject`.

> <https://docs.unity3d.com/ScriptReference/Component.BroadcastMessage.html>

```cs
using UnityEngine;

public class Tower : MonoBehaviour
{
    void Start()
    {
        // Make sure nothing is firing or tracking till round starts
        BroadCastMessage("SetStatus", GameUnitStatus.READY_INACTIVE)
        // Listen for the level/round to start
        GameController.OnRoundStart += OnRoundStartHandler;
    }

    void OnRoundStartHandler()
    {
      // Any turrets/zappers components on this object or it's children start tracking and firing
      BroadCastMessage("SetStatus", GameUnitStatus.ACTIVE)
    }
}
```

### Events

As we've already already used, and seen in the example above (BroadcastMessage).

### GetComponent and call functions

As we did with `SpriteRenderer.Sprite`. We can call these on current gameObject or on ones we have a reference to.

```cs
  void ExplodeAThing(GameObject thing)
  {
    thing.GetComponent<Explodeable>().Explode(); 
    // IRL we'd check the result of GetComponent before calling Explode
  }
```

## Prefabs

Create->prefab
Drag a thing from the scene heirarchy onto it.
The thing in the scene is now an instance of the new prefab
Drag another from assets/prefabs to the stage to see it

![Create Prefab](assets/week10/prefab_create.png)
![Prefab made used](assets/week10/prefab_made_used.png)

## Expanding the things we might need

In missile command there are  good few objects, and we need to figure out their properties. Luckily this isn't a code exercise, it's just imagination and things we know about games.

### Drawover

A quick doodle over the game screen can help us figure out the code, instead of having to visualise everything in our head.

// Here lies a drawing

### Attributes of our classes

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



