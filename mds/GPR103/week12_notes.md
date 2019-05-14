# Week 12 - Performance, debugging


## Resources

* Events with multiple arguments
  - [Microsoft docs for System.Action variants](https://docs.microsoft.com/en-us/dotnet/api/system.action-2?view=netframework-4.8)

* Unity 3D college on debugging:
  - https://www.youtube.com/watch?v=y3kqIlLzIig
* Unity Debugging video tute:
  - https://unity3d.com/learn/tutorials/topics/scripting/debugging-unity-games-visual-studio
* Unity official: optimization garbage collection
  - https://unity3d.com/learn/tutorials/topics/performance-optimization/optimizing-garbage-collection-unity-games

## Multi argument events!

Good news, the course notes were wrong about multiple arguments to Action<>/delegate events! Turns out there are multiple overrides of Action: Action<T>, Action<T1,T2> and so on up to 16.

[Microsoft docs for System.Action variants](https://docs.microsoft.com/en-us/dotnet/api/system.action-2?view=netframework-4.8)

Here's my inspector, setting two variables:

![PrevNext Item Inspector](assets/week12/prevNext_dropdowns_inspector.png)

Here's the code to pass them in an event

#### In PrevNextItemOnClick.cs

```cs
public class PrevNextItemOnClick : MonoBehaviour
{
  public static event Action<string, string> OnPrevNextRequested = delegate { };
   
  ...

  void OnMouseClick()
  {
    // Now we can call with two strings
    OnPrevNextRequested(_customItem.ToString(), _prevNext.ToString());
  }

}

#### In CustoModel.cs
```cs
// Giving our handler to PrevNextItemOnClick doesn't change,
// Just the signature of the handler

private void OnPrevNextHandler(string item, string prevOrNext)
  {
    Debug.Log("Model heard arrow say " + item + ", " + prevOrNext);
    charState[item] = (prevOrNext == "previous") ? decrementPosIntLooping(charState[item], counts[item]) : incrementPosIntLooping(charState[item], counts[item]);
    
    // Then throw a modelUpdate event that lets peeps look at the state
    OnCharacterChanged(charState);
  }
```

#### Quicky: how did you get the string dropdowns

I declared some enums, which we already know about. What you might not have discovered is the ToString() function you can call on them to get their defined name.

```cs
// ... includes

public enum PrevNext
{
  previous,
  next
};

public enum Customisable
{
  hat,
  face,
  body
}

public class PrevNextItemOnClick : MonoBehaviour
{
  // Declare a variable of enum's type, expose to editor with SerializeField
  [SerializeField]
  protected Customisable _customItem;

  [SerializeField]
  protected PrevNext _prevNext;
  
  //... later in class:
  
  void OnMouseClick()
  {
      OnPrevNextRequested(_customItem.ToString(), _prevNext.ToString());
  }

 ```

### Joining and splitting string arguments

I went with the first idea that came to mind for character customiser arrow clicks: typing `next` and `previous` into the inspector fields, then joining them in a string with a separator: `next_hat`. That was sent to the model, which split them apart.

```cs
private void OnPrevNextHandler(string itemPrevOrNext)
  {
    string item = itemPrevOrNext.Substring(0, itemPrevOrNext.IndexOf("_"));
    string prevOrNext = itemPrevOrNext.Substring(itemPrevOrNext.IndexOf("_") + 1);

    charState[item] = (prevOrNext == "previous") ? 
    
    // Go down or up, looping at extens
    decrementPosIntLooping(charState[item], counts[item]) : incrementPosIntLooping(charState[item], counts[item]);
    // Then throw a modelUpdate event that lets peeps look at the state
    OnCharacterChanged(charState);
  }
```

It was an easy workaround for me because I've chopped up strings in the past, but it has a few downsides:
* My version with text fields required looking up the right strings in the code.
* Joining and splitting strings is pretty low cpu but it's still pointlessly wasteful. 

Inspector screen shot

```cs

```

### Structs and objects?

Yep, you could just pass your own custom struct or object.

## Squashing bugs

The types of bugs in our code seem to be at least as numerous as the tools available to us. So far we've had a pretty limited set of techniques for finding them: logging to console, running the build often, working in small scale/isolation when trying something out.

Eventually though, you get 
* big games that are slow to build
* things that can be only run amid complexity
* restricted by the limits of the console

### Enter the debugger

A debugger is a shockingly powerful program that can look into the **memory used by** and **execution of your program** in real time. It can
* step over line by line, 
* *stop at breakpoints. 
* give you access to variable values as they're changed, including lists and objects, without console
* often include a few performance stats 

Some of you will have used a debugger in say visual studio for c++/c sharp, or elsewhere for python. You might think 

### Example walk through

* Hearing a click in Character Customiser
  - See that it's called without needing debug.log
  - Look through passed arguments, look through object!

**Attach Editor prefs unity**

**breakpoint picture**

**stopped at breakpoint**

**Inspecting variables**

### Where to break, how to step

### Now do it with your project

Try putting a break point at any of the following and exploring:
  * When you catch a click and generate a missile
  * When a missile collider hits an explosion collider
  * Is a missile hitting your city but you can't see what's hitting it? Look at the colliders of each.
  * Updating score field: Why's it empty? Why are you getting a crash trying to change it? See if your variable referring to the component is null. See if the string you're creating from your score number is empty. Work out why later.

### Forensic debugging!

So far we've usually tried to debug by coming up with a theory and then putting in Console.Log. That only helps us if our theories are on point.

Using the debugger lets us look much more quickly at loads of things, gather loads of evidence, and a surprise result in that evidence can lead you to a bug source you'd never considered.


## Responsiveness

Missile Command: As wave after wave of death dealing alien hardware is flung at the homes and businesses of everyday earthlings, **masses of resources are going into the creation of weapons and cleaning up in their aftermath.**

This describes life in the game, but also life for our game engine.

> We're instantiating human and alien missiles, trails and explosions for potentially hunderes of waves. Each one uses memory and processor time, and it takes time and effort for unity to recover resources when each is finished with.

### Limited resources

You might think about this much on quade core Windows machines with 16GB of RAM, but if you're outputting to other platforms this becomes critical
* Mobile phones/handhelds: Not much ram, not much processing power. Do not spend it all on disposable assets.
* Console: At the start of a generation these specs seem pretty nice, but can become very constraining as people come to expect more.
* VR users can be very sensitive to frame rate changes. If your game makes them sick, it doesn't matter how fun it is.

### Manual Memory Management

What we had. Malloc, dealloc.

### Garbage Collection

Let the garbage man decide what's unwanted and take it away.

Obvious upside:
Almost no manual memory management!

Dangers for the inexperienced: Garbage collection tends to take what would have been done manually, spread out over time, and lump it into passes. 
* Fine if they're not cleaning up too much. 
* Give them a lot to clean up and like anyone else, they need time and resources. And that causes stutters in your game's frame rate and response.  

![GC Peaks](assets/week12/garbage_collection_peaks.png)

## Looking at performance

Profiler!
Last week I gave you guys a function to move a missile over time, and it used time.elapsedTime to make sure things moved well regardless of how long frames took to render. 
Today we talked about how garbage collection can impact your game.

![profiler cpu frames](assets/week12/profiler_cpu_frametime.png)

How can we visualise it?

## Optimising

How can we manage problems like big garbage collection hits and constant resource creation

### Object pooling!

Concept of object pooling.

### implementation of object pooling?

Go with simple example. Link to old mate.