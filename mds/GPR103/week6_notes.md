# GPR106 Week 6 notes

Sharing, decoupling and triggering in Unity. No, this is not relationship advice. We're talking **events**, **delegates** and **messages**.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [GPR106 Week 6 notes](#gpr106-week-6-notes)
	* [Decoupling: what](#decoupling-what)
		* [Decoupling, why](#decoupling-why)
		* [A simpler example](#a-simpler-example)
	* [Events](#events)
		* [Generics aka what is \<that\>?](#generics-aka-what-is-that)
	* [To do / exercises](#to-do-exercises)
	* [Resources](#resources)

<!-- /code_chunk_output -->

___

## Decoupling: what

Decoupling is a way of **keeping things in your game from knowing too much directly about other things** in the game. At the very least, **not having references to eachother and calling functions** on eachother.

> Reasonable question: So avoiding doing all the stuff you just taught us and made assessment 1 about?

![sarek_precisely](/assets/week6/sarek_precisely.png)

___

### Decoupling, why

What scenario leads programmers to jump from talking about _functions_ and _inheritance_ to discussing **decoupling**? Just when we gained control of our objects and could call functions and using properties.. why are we trying not to?

![swarm](/assets/week6/swarm.png)

In the long term, this. In the short term, even our next assignment will quickly become a quagmire if we don't decouple.

### A simpler example 

![scenario_1](/assets/week6/scenario_1.png)

Here I've just made a project to move a few things up and down, when they are unlocked. 
* Even on this teeny thing, look at the heirarchy on the left there.
* How much do you like repeating the same action on 20 things. 

> What decoupling does is 
> 1. **Add a little friction at the start** of our project to **avoid massive friction later ** when changing or adding anything.
> 2. Lets us dream big and make mental games!

## Events

* Door to door knocking is slow
* Getting people to your house is hard and complicated
* Clever people instead broadcast indiscriminately on  _Twitter_

![scenario 1](/assets/week6/scenario_1.png)

___

### Generics aka what is \<that\>?

Rather than start with a theoretical description, be relieved that you've already used generics and it wasn't that hard.

> * Here in _c#_ you've used `List<Tower>`, maybe `Dictionary<Weapon>`.
> * In _c++_ some of you used `vector<string>` 

The **generic** bit means:
* Someone was able to write the `List` class not knowing what type of object you'd store in it. They did that by **putting** `<T>` **for type** wherever you would put your object type.

![list ](/assets/week6/list_generic.png)

Notice when I hover over "List" in VS I see `List<T>` and `T is string`

## To do / exercises

Do these things if you want to get good.

1. Write down assessment 2 in your own words
2. Make cards for A2 on your hacknPlan board.

## Resources

Helpful things

*