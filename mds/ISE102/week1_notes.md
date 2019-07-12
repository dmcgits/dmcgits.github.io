---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# ISE102 Week 1


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ ISE102 Week 1
](#ise102-week-1)
  - [ Part 1: Studying Software Engineering
](#part-1-studying-software-engineering)
    - [ Who are we?
](#who-are-we)
    - [ C++ in a nutshell
](#c-in-a-nutshell)
  - [ How can we succeed learning c++ in this class?
](#how-can-we-succeed-learning-c-in-this-class)
    - [ Hour splits and thriving in 2D Games Programming
](#hour-splits-and-thriving-in-2d-games-programming)
    - [ Blackboard is your friend
](#blackboard-is-your-friend)
    - [ Recommended texts
](#recommended-texts)
    - [ My notes are your friends
](#my-notes-are-your-friends)
    - [ Assessments
](#assessments)
      - [ Assessment 1
](#assessment-1)
      - [ Assessment 2
](#assessment-2)
      - [ Assessment 3
](#assessment-3)
  - [ Part 2: Programmings is handling situations
](#part-2-programmings-is-handling-situations)
    - [ Why not just write it in c++?
](#why-not-just-write-it-in-c)
    - [ Whitespace
](#whitespace)
  - [ Problem solving tools
](#problem-solving-tools)
    - [ This is the key to coding.
](#this-is-the-key-to-coding)
  - [ From pseudocode to source code
](#from-pseudocode-to-source-code)
    - [ Hello world
](#hello-world)
      - [ Let's code that!
](#lets-code-that)
    - [ Let's understand that!
](#lets-understand-that)
      - [ Blocks {} and ending a line of code ;
](#blocks-and-ending-a-line-of-code)
      - [ What is `using namespace`
](#what-is-using-namespace)
      - [ C++ Comments
](#c-comments)
    - [ Compiling and running your game
](#compiling-and-running-your-game)
      - [ 1. Source code
](#1-source-code)
      - [ 2. Compiler
](#2-compiler)
      - [ 3. Object code
](#3-object-code)
      - [ 4. Linker
](#4-linker)
      - [ 5. Executable File
](#5-executable-file)
      - [ 6. Loader
](#6-loader)
  - [ Part 3: Exercises
](#part-3-exercises)
      - [ 1. Basic input/output documentation
](#1-basic-inputoutput-documentation)
      - [ 2. Sololearn quiz
](#2-sololearn-quiz)
      - [ 3. Optional: review textbook chapter 1
](#3-optional-review-textbook-chapter-1)
  - [ Appendix 1: Install Visual Studio Community
](#appendix-1-install-visual-studio-community)

<!-- /code_chunk_output -->


## Part 1: Studying Software Engineering

Learning about programming through _C++_.

> * What is programming? Structured problem solving.
> * Where did _C++_ come from, and what is it used for?
> * A little high school maths and organised thinking. If you understand computer hardware it won't hurt.

---

### Who are we?

**Me:** Danny McGillick. Computer Science @ UTS, Web dev, Creative technologist in advertising (flash/actionscript, unity), 2D and 3D artist for Torus, Halfbrick, Blowfish studios. Keyboard enthusiast, bits maker.

https://cargocollective.com/dmac/ - Flash/Unity 
http://www.artstation.com/dmacdraws/ - game art

**You:** The next makers with long futures.

---

### C++ in a nutshell

* Made on top of _C_ in the 80s. 
* C written for computer scientists to compile cross platform.
* Big-time game engines, operating systems, your windows apps are written in _C++_, _C_. Planes and satellites and freight ships. Maybe power stations and bridges too.
* Fast, low level aka "close to the metal"
* No game making tools by default.
* There is free code out there in "libraries" that can help us when it comes to drawing graphics.
* It's what's called an Object Oriented language. C was procedural.

```c++
// c++ main function
int main()
{
    cout << "Battle Royale Game." << endl;
}
```

![Bjarne](assets/week1/bjarne.jpg)
_Bjarne Stroustrup: legend_

---

## How can we succeed learning c++ in this class?

How are MDS subjects designed, and what do I need to do to get the most from them?

### Hour splits and thriving in 2D Games Programming

> **30%** class hours.
> **70%** studying, programming, gaining experience. 

The benefit of these courses comes from putting in work between classes. What we learn in class won't stick if you don't work and experiment at home.

### Blackboard is your friend

Find assignment briefs, due dates, slides, programming tutes/samples and much more. The screenshots are from GPR103 but the structure is cross-subject.

> Digging through Blackboard material is the second key to coming out ahead in these subjects, just below coding at home.

![Subject overview](assets/week1/subject_overview.png)
_Grab the subject outline and subject planner_

![Module intro](assets/week1/module_overview.jpg)
_Every subject has modules in the left menu. Click one for important info_

![Module learning resources](assets/week1/module_resources.jpg)
_The blue button, top of screen, takes you to more info and resources. Don't skip the learning resources_

### Recommended texts

_Beginning C++ Through Game Programming_ is available free when you're logged in to black board. Go to <https://ebookcentral-proquest-com.ezproxy.laureate.net.au/lib/think/detail.action?docID=3136727> and download chapters as free pdfs.

### My notes are your friends

The original course notes are in powerpoint, and available from the module pages in Blackboard. I write up new ones (like the one you're reading) for most lessons and post them on Git. The url pattern is:

https://dmcgits.github.io/mds/ISE102/week1_notes.html

> If I post an announcement before class I will often post an html notes link.

### Assessments

3 Assessments. It'll require a solid effort at all 3 to pass. 

#### Assessment 1

Text based slot machine. **Due end week 6**

#### Assessment 2

Exam covering material from mostly first 2 modules (first 4 weeks). **Due end of week 7**

#### Assessment 3

Snake game with ascii graphics. **Due end of week 12**

![Snake](assets/week1/snake.png)
_Yes that snake game_

___

## Part 2: Programmings is handling situations

![Handle business](assets/week1/handle_business.jpg)

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

The problem solving tools above are common across programming languages.

> _Coding is, first, problem solving_. This means dissecting the problem and creatively solving it. The syntax is just a way of communicating that solution to the computer, and you'll use multiple languages/syntaxes through your career.

---

## From pseudocode to source code

Like all languages, a programming language has
> Vocabulary -> Keywords
> Grammar -> Syntax
> A file with syntax and keywords in it contains.. source code! 

Keywords are words that have a special meaning to the compiler, like `int` and `using`. Wikipedia defines syntax for us:
> the syntax of a computer language is the set of rules that defines the combinations of symbols that [make a working program]

Good news is, once you've learned a language it's not nearly as hard to switch as the spoken ones:

> There are only 73 special or reserved words in C++
>There are on average 20,000 words a native English speaker uses.

---

### Hello world

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

#### Let's code that!

![new project](assets/week1/new_project.png)

![new empty project](assets/week1/new_empty_cpp_project.png)

![new item](assets/week1/new_item.png)

![new cpp](assets/week1/new_cpp_hello.png)

![console stay open](assets/week1/console_stay_open.png)
_This setting will keep the console from closing when your program ends_

I recommend pausing your antivirus. For example, I turn off avast shields for 1 hour. Otherwise it'll intercept your new code.

Even something this brief is less clear in code, so make your life easy.

---

### Let's understand that!

What was the syntax? What were the keywords? You can play with the code along with me, or watch and do it later.

#### Blocks {} and ending a line of code ;

The _C++_ compiler mostly doesn't think about whitespace like us. Some languages do, but not _C++_. It would actually be happy with this:

```c++
#include <iostream>
using namespace std; int main() { cout << "Hello world!" << endl; }
```

..but we would be very sad. Thankfully, the _c++_ syntax for blocks and lines of code is pretty easy 

```c++
// We use the curly braces { } to define a block of code that should be grouped together. This includes all the code inside the main() function.

int main() {
    // all your code here
}
```
So use tabs, enter and space to make your code clear, and always remember `;` to end your lines.
```c++
    // When c++ finds a semi colon, that's a finished line of code.
    int ageOfBarry = 47;

    cout << "Barry's age is" << ageOfBarry << endl;
```

---

#### What is `using namespace`

```c++
using namespace std;
```

This lets us use code written by other people without having to put a path before it. `cout`, `endl` are in the _c++_ standard library, so..

```c++
    // without "using namespace std" we'd get a compile erour /// .. unless we do this:

    std::cout << "Hello world!" << std::endl;   // gross

    // The prefix std is the name of the library, and the
    // double colon :: is the syntax for accessing a library
    // function or variable.
```

#### C++ Comments

> There is only so much you can work out from reading someone else's code. Intent and thinking can be lost in translation.

Especially if the coder made mistakes. That's why we use comments. Think of them like footnotes in a book, or the margin comments in a textbook. Except even more important.

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
___

### Compiling and running your game

![Compiler flow](assets/week1/compiling_flow.jpg)

#### 1. Source code
Instructions for a computer to handle given situations and perform certain tasks. The source code will be written in the syntax and grammar of a particular programming language; in our case, the language is c++. 
  
#### 2. Compiler
A compiler reads your source code and usually converts it into machine code. This will be the specific instructions for a target computer and operating system, say windows x86 intel.
  
#### 3. Object code
The machine code output by the compiler, often with a .o extension. Your c++ compiler will also have on hand object code for the libraries it includes

#### 4. Linker
The linker takes your object code and looks for references to other code. This can be your own from multiple c files, or references to standard/downloaded libraries. It then inserts the referred-to machine code into your own and creates a single .exe file. There are other types that can be created, like dynamic libraries, but we'll discuss those later.

#### 5. Executable File
This is your finished product. It's ready to be double clicked, run from the command line, launched from Steam/Battle.net or any other way you begin loading it.

#### 6. Loader
The operating system executable that will load your executable into memory and begin execution. This is how it goes from instructions on an SSD/HDD to a running, interactive program.

>We'll be using _Microsoft Visual Studio 2017_, an Integrated Development Environment, to write, compile and debug all our code. 

---

## Part 3: Exercises

#### 1. Basic input/output documentation

Read through <http://www.cplusplus.com/doc/tutorial/basic_io/> and try the different variations provided in the _Standard output (cout)_ and _Standard input (cin)_ sections.


#### 2. Sololearn quiz

Attempting to recall this info in different contexts will help you retain it. Sololearn quizzes are great for low pressure review.

1. Install **Sololearn** for [android](https://play.google.com/store/apps/details?id=com.sololearn) or [ios](https://itunes.apple.com/us/app/sololearn-learn-to-code/id1210079064). 
2. Register
3. Go to the **learn** section and **select the C++ Tutorial** under programming languages. 
4. Select **Basic Concepts** and work through the **first 5 sections (up to and including comments)** to revise today's learnings
5. Continue through the **next 4 sections on variables and basic maths** to be ready for next week's topics.

![solo learn](assets/week1/sololearn_steps.png)

#### 3. Optional: review textbook chapter 1

Make sure you're logged in to blackboard and visit: <https://ebookcentral-proquest-com.ezproxy.laureate.net.au/lib/think/detail.action?docID=3136727>

___

## Appendix 1: Install Visual Studio Community

_Microsoft's longer, more detailed version of the following instructions is here: <https://docs.microsoft.com/en-us/cpp/build/vscpp-step-0-installation?view=vs-2017>_ 

If you already have Visual Studio: search for and run the Visual Studio Installer, select More > Modify (next to the launch button), then go to step 3. Otherwise,

1. Go to https://visualstudio.microsoft.com/vs/older-downloads/. Don't click "Download Visual Studio", instead scroll down and expand "2017" to download.
2. Run the installer. At a point it will ask you to select a _workload_.
3. Under _Workloads_ you'll see the _Windows_ section. Select _**Desktop development with C++**.
   ![workloads](assets/week1/visual_studio_workload_cpp.jpg)
4. At the bottom right set _install while downloading_ and click _modify_ or _install_ (whichever you have). 