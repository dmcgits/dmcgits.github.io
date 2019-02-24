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

Writing a program like this is writing in **psuedocode**. Psuedo as in "kinda". It's kinda code, but not specific. 

### Why not just write it in c++?

Well, here are programming languages that can _github_ can hilight for you:
 [https://github.com/github/linguist/blob/master/vendor/README.md](https://github.com/github/linguist/blob/master/vendor/README.md)

.. and a lot of them are very different. Which one is the way to teach problem solving? Trick question.

> Code is us telling the computer how we want it to handle situations. It's designed for computers to understand, and our brain works hard when we read and write it. Abstract problem solving is really hard too - why do both at the same time?

We don't need to start coding right away. We can solve some of the problem first, and then tell the computer when we're done.

### Whitespace

Why did I tab out a lot? **Whitespace** really helps us understand things, more than just adding more characters.

![whitespace](assets/week1/whitespace_matters.png)

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

### This is the key to coding.

> _Coding is problem solving_. This means dissecting the problem and creatively solving it. The syntax is just a way of communicating that solution to the computer, and you'll use multiple languages/syntaxes through your career.

---

## Doing it for real

Our situation is waking up, our problem is: how should I face the world? Solution? I'm going to greet it. Our _psuedocode_:

```
start program I_WAKE_UP
    
    Say hello to the world.

end program I_WAKE_UP
```

Our _c++_ code for that solution:

```c++
#include <iostream>
using namespace std;

int main() {

    cout << "Hello world!" << endl;
}
```

Even something this brief is less clear in code, so make your life easy.

---

### Blocks {} and ending a line of code ;

The _C++_ compiler mostly doesn't think about whitespace like us. Some languages do, but not _C++_. It would actually be happy with this:

```c++
#include <iostream>
using namespace std; int main() { cout << "Hello world!" << endl; }
```

..but we would be very sad. Thankfully, it's pretty easy to translate our thinking.

```c++
// We use the curly braces { } to define a block of code that should be grouped together. This includes all the code inside the main() function.

int main() {
    // all your code here
}
```
---

### What is `using namespace`

```c++
using namespace std;
```

This lets us use code written by other people without having to put a path before it. `cout`, `endl` are in the _c++_ standard library, so..

```c++
    // without "using namespace std" our hello world action would look like this:

    std::cout << "Hello world!" << std::endl;   // gross
```

### C++ Comments

> There is only so much you can work out from reading someone else's code. Even in written English, sometimes an author sometimes adds footnotes. Code, being more cryptic, needs more.

Especially if the coder made mistakes. That's why we use comments.

```c++
    #include <iostream>
    #include <string>
    
    // Anything written on one line after a double slash is ignored by the compiler
    
    /* 
    Anything written between these two slash and star symbols
    will be a comment over two lines. We can comment out whole blocks of code this way during testing
    */

    using namespace std;

    int main()
    {    
        // Here's a variable to store the user's first name 
        String firstName = "";

        // cout will output information to the user
        cout << "Enter your first name: ";

        /* cin will wait for the user to type a word and press enter, then
            assign the result to a variable after the >> symbol. */
        cin >> firstname;

        cout << "Hello " << firstName << endl;

    }

```

