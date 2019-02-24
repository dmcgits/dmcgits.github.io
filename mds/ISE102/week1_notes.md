# ISE102 Week 1

## Part 1 - Studying Software Engineering

Learning about programming through _C++_.

> * What is programming? Structured problem solving.
> * Where did _C++_ come from, and what is it used for?
> * A little high school maths and organised thinking. If you understand computer hardware it won't hurt.

---

## Who are we?

**Me:** Danny McGillick. Computer Science @ UTS, Web dev, Creative technologist in advertising (flash/actionscript, unity), 2D and 3D artist for Torus, Halfbrick, Blowfish studios. Keyboard enthusiast, bits maker.

https://cargocollective.com/dmac/ - advertising
http://www.artstation.com/dmacdraws/ - game art

**You:** The next makers with long futures.

---

## C++ in a nutshell

* Made on top of _C_ in the 80s. 
* C written for computer scientists to compile cross platform.
* Big-time game engines are written in _C++_, _C_.
* Fast, low level.
* No game making tools by default.
* There is free code out there in "libraries" that can help us when it comes to drawing graphics.

```c++
// c++ main function
int main()
{
    cout << "Battle Royale Game." << endl;
}
```

---

## How can we succeed learning c++ in this class?

Hour splits

### Blackboard

### Resources/notes

## Assessments

### Assessment 1


## Handling situations

Programming is usually defined around computers and compiling and so on. But really, that's the implementation. We'll get to that, but we'll have a much easier time if we've thought first about what programming really is: 

> Programming is just a) defining situations and b) responding to them with actions.

Here's a simple program:

```
start program I_SPILLED_COFFEE

    If I got some on my shirt:
        
        If I'm in public:
            Wipe it a bit with a serviette.

            If it's a new shirt:
                Find restroom
                
                While I can still see coffee:
                    Rinse it with a bit of water
                    Pat with a paper towel
                
                Dry it a bit with hand dryer
            
        
        Otherwise, if I'm not in public:
            Take off shirt
            Spray with stain remover
            Put in washing machine
            Put on another shirt
    
end program I_SPILLED_COFFEE
```

We can all understand a program written like this. It's a situation, based on some information we received from our eyes and maybe wet our hand. Then we check a few things, and based on those we acted. In one case we did something over and over till it worked.

Writing a program like this is writing in **psuedocode**. Psuedo as in "kinda". It's kinda code, but not specific. Why did I write that instead of some _C++_? Well, here are programming languages that can _github_ can hilight for you:
 [https://github.com/github/linguist/blob/master/vendor/README.md](https://github.com/github/linguist/blob/master/vendor/README.md)

An awful lot of these are very different too, and all for their own historic reasons. But:

> Code is us telling the computer how to handle situations. It's written for computers to understand, so there are lots of bits that work our brains hard when we read it. 

The sensible thing to do first is to think about the problem we want solved, in a way which is easy for us to think about.

**Whitespace** really helps us understand things, that's most of what we need.

---

## Problem solving tools

```
    If I got some on my shirt:    <-- First check
    
        If I'm in public:         <-- Second check
        Wipe it a bit with a serviette.     <-- action
```

We check something, and based on the result, we act. This is called a **conditional**. Our check evaluates to **true or false**: true, I do have coffee on my shirt. true, I am in public. I better perform an action, hand me that serviette.

```
    While I can still see coffee:
        Rinse it with a bit of water
        Pat with a paper towel
```
Sometimes one action isn't enough. It's a repeated process of checking, acting, checking again. While something is true, keep doing this action. This is a **loop**.

```
start program I_SPILLED_COFFEE
...
end program I_SPILLED_COFFEE
```
A **situation** occurred. Our response is a **program**. Is there a better way to describe what the brain is full of? A whole bunch of responses to things we experience. I'm hungry! I'm tired! I want to browse the web! A car is coming at me!

We have a **program** to handle the situation **I spilled my coffee**. It has:
* **Information** (the state of our shirt and coffee, our location)
* **Conditionals** (checking those states and deciding on a path)
* **Actions** (Things that we do in response to the check results)
* **Loops** (A combination of a check and some things to do, repeated)
* **A Beginning And End**
