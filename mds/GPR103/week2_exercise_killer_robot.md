---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Exercise: Killer Robot (Classes)
We're going to create a little simulation as an exercise in object oriented design.

## The structure
1. Create a class called `KillerRobot`. 
2. Give the class three private member variables, an integer for health, an integer for insanity, and a weapon. 
3. Add accessor methods (properties) for these member variables. 
4. Add a method to the class called, `IsDead`, which returns a Boolean. If the
instance’s health is less than or equal to zero this method will return `true`,
otherwise `false`.
5. Add a method to the class called `CheckLifesigns`, which outputs a
message to the console. 
   * If the health is greater than or equal to fifty,
output, “All subsystems nominal!”
   * if the health is less than fifty but greater
than twenty output “Artificial life signs draining!”
   * If the health is less than
or equal to twenty, but greater than zero, output, “Critical systems
implosion imminent!” 
   * If the health is zero or less, output a random string of
ones and zeros, eight characters in length.
6. Add a method to the class called `CheckInsanity` which outputs to the
console the instance’s current insanity value.
7. Add a method to the class called `RandomlyLoseHealth` which will
subtract a random amount of health (somewhere between 10 and 30) from
the instance. Every time an instance loses health, their insanity value should
increase by the amount of health lost.
8. Create an enumeration for weapons, called `EWeapon`, with the following
elements: `Laser-Gun`, `Rail-Gun`, `Quantum-Tunneller`, `Spectrum-Diffuser`, `RayResonator`, `Particle-Duality-Dissociator`, and `Plasma-Accelerator`.

## The program
1. The client (the main function) must create three instances of the
KillerRobot class.
   * name the instances, `Z800`, `Z1000`, and `ZX`. 
   * Have the client set up appropriate member data for each instance via the accessor methods. 
   * Give each object a health value between `80` and `100`, a weapon, and a random insanity value between `1` and `10`.
2. Call `CheckLifesigns` for each instance, followed by
`RandomlyLoseHealth, a`nd then finally call `CheckInsanity`. 
    * Continue to do this until each instance is dead (loop)
    * Note: when an instance is dead; no longer call the methods on the instance!

## Remember to:

* Separate interface from implementation.
* Declare a constructor and destructor.
* Initialising members to appropriate default values.