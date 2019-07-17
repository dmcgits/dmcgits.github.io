### The self propelled vehicle is the real system

The engine, the wheels, the chemicals, these are the system. 

> 1. We feed it inputs through the controls
> 2. The system changes
> 3. The sensors perceive these changes and tell us.
> **1 and 3 are the interface. We are the user. What's left is the system.**


## System, Controls, Readouts applied

Our customiser maps well to this setup

### System: The model/simulation

Picturing our program this way, we need a system. We're not making a physical thing, we're making a simulation or model of it. 

> When scientists make a copy of a system to test, like a bacteria or a molecule or global weather system they make a "model" of the system and run a simulation.
 
* _word_ is simulating a **document being edited**.
* _warcraft 3_ is simulating a **great conflict in a (square area) of a distant land**
* _windows_ is simulating a **desktop** where you're doing jobs, and beneath that it's simulating **one computer with many processors (whether you have them or not)** from a bunch of separately sourced constructions of silicon, exotic metals, plastic etc.

A simulation is always in some "state": the result of inputs to the model, and its resulting condition.

### Controls

> The **controls (steering wheel, pedal) are our buttons, text fields etc** that want to change the system. They request changes to the name, gender eyes, hair or shirt. 

Instead of levers, wires and shafts we use can just throw out events. The model listens for them.

```cs
// for example
class GenderButton
...
public static event Action<String> onGenderChanged = delegate {};
```

### The Readouts

>The car readouts (engine light, speedometer, beeping seatbelt warning) are, for us, sprites of our character changes. Pictures of eyes, hair or shirt. Text labels showing name, skill points etc.

Instead of sensors connected by wires, we can listen for for changes in the model. The model announces them as events. 