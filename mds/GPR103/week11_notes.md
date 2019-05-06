# Week 11 - Time, text, collisions

Very powerful tools this week.


## Todo

* Get your UI up and running
* Finalise, as much as you can, hacknplan tasks
  - You'll notice the burndown doesn't progress if you're still adding new tasks at the rate you're finishing others
* Game should be basically done by next class.

## Resources


Timers:
  - Blog tute: [Build a reusable timer](https://medium.com/@jaredehalpern/build-a-reusable-timer-in-unity-to-control-explosions-and-other-fun-stuff-too-1689210b733)
  - Docs: [StartCoroutine](https://docs.unity3d.com/2017.4/Documentation/ScriptReference/MonoBehaviour.StartCoroutine.html)
  - Docs: [Waiting for game seconds](https://docs.unity3d.com/2017.4/Documentation/ScriptReference/WaitForSeconds.html)
  - Docs: [Waiting for real world seconds](https://docs.unity3d.com/2017.4/Documentation/ScriptReference/WaitForSecondsRealtime.html)

## Doing things over time

We've all played games where time is critical. Time to finish a level, time per lap, time to get out of a space station before it blows.

Timings affect us in lots of other scenarios. Cooldown times, facility/vehicle upgrade and repair times, rounds fired per second.

### Things that need timing

Potential things that need timing

> - From press play 
> - From level finish (last missile destroyed) till next level, showing results
> - From game over till game over graphics appear, play out and show play again or return to home screen

How do we specify a series of times, say:
 1. 0s
 2. 1.3s, 
 3. 3.1s

### Ways to time

#### Invoke

Invoke will call a function after a given delay. Question to investigate: does the program halt and wait?

From [Stack Overflow](https://stackoverflow.com/questions/30056471/how-make-the-script-wait-sleep-in-a-simple-way-in-unity)
```cs
void Start()
{
    Invoke("feedDog", 5);
    Debug.Log("Will feed dog after 5 seconds");
}

void feedDog()
{
    Debug.Log("Now feeding Dog");
}
```

#### Update and time.deltaTime.

Basically counting time as update executes over and over. Then after a certain time, doing something. 
* This is okay for the same thing happening at intervals.
* A sequence of things happening with various timings gets trickier/messier. Maybe a combo of a list and a function?

From [Stack Overflow](https://stackoverflow.com/questions/30056471/how-make-the-script-wait-sleep-in-a-simple-way-in-unity)
```cs
float timer = 0;
bool timerReached = false;

// Modified from stackoverflow a little
void Update()
{
  if (!timerReached)
    timer += Time.deltaTime;
    if (timer > 5)
    {
      Debug.Log("Done waiting");
      feedDog();

      //Set to false so that We don't run this again
      timerReached = true;
    }
  }
}

void feedDog()
{
    Debug.Log("Now feeding Dog");
}
```

#### Coroutines

What if we could pause a function and come back to it after a given interval. That way our timed things could all be encapsulated in one function, and we could do stuff while it's paused. A coroutine is a function, but it's also a similar to a process that can be stopped and started, returning control to our main execution.

From [Stack Overflow](https://stackoverflow.com/questions/30056471/how-make-the-script-wait-sleep-in-a-simple-way-in-unity)
```cpp

```


### Time with a coroutine

```cs

private List<float> _times;

void Start() {
  TriggerAWave();
}

// Regular old routine kicking off a special routine, one that can stop and start.
void TriggerAWave()
{
  List<float> times = new List<float>() { 0.0f, 4.0f, 2.5f, 6.0f };
  Debug.Log("We'll call the wave releaser");
  StartCoroutine(ReleaseWaves(times));
  Debug.Log("While it does its wave thing we keep going.");
}

private IEnumerator ReleaseWaves(List<float> waitTimes)
{
  Debug.Log("ReleaseWaves here, starting.");
  foreach (float waitTime in waitTimes)
  {
    yield return new WaitForSeconds(waitTime);
    Debug.Log("Waited for " + waitTime + " seconds");
  }
  Debug.Log("Releasewaves done, signing off");
}

```


### Releasing waves - spawning

Spawn some prefabs

Waves like alien batteries


## Other Things



##Scoring

using textmeshpro to generate and use an atlas from the ready/start player 2 font.

Firing at targets. Maybe at the start of a wave all 3 volleys of missiles are aimed and prepped? If the city is destroyed before they arrive/fire so be it.

## Colliding things
Our missiles grow, so must their collider. Check for a hit. We meed to know what hit what, to assess damage.
