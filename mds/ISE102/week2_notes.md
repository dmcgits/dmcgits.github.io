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


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=2 orderedList=false} -->

<!-- code_chunk_output -->

- [ISE102 Week 1](#ise102-week-1)
  - [Fixing the guessing game](#fixing-the-guessing-game)
    - [Checking With If](#checking-with-if)
    - [Adding Randomness](#adding-randomness)

<!-- /code_chunk_output -->


## Fixing the guessing game 

Last week we made a **guessing game**. It insulted players to hide its **missing functionality**.

![flow guess insult](assets/week2/flow_guess_insult.png)


Here are your computer's new instructions: how it can host a super fun guessing game:
1. Pick a number between 5 and 10, remember it.
1. tell me to guess it.
1. let me input a number, and you remember it.
1. If i’m wrong tell me i’m wrong, but u take the blame computer
2. If i’m right give me a thousand moneys

### Checking With If

The real game would *check if the player guessed the secret number**, then react: 
  - Is the `playerGuess` the same as `secretNumber`?
  - Say something if it's true, otherwise say something else.



To check if something is true, click on an arrow in your flowchart and select the red if diamond.

<img src="assets/week2/flow_adding_if.png" width="650">



We need an `operator`, a piece of punctuation that means is equal to.

<img src="assets/week2/flow_guess_num_if.png" width="650">

___

### Adding Randomness

Avoid having the same game each time. Let's **generate a random number in the range 0-5 inclusive** (including 0 and 5).

___

#### _Random numbers in Flowgorithm_

Flowgorithm has **built-in functions** we can write into an expression. 
>  - Functions are sorta like smart variables: when you call them they can return a value
>  - That value can change basd on circumstances
>  - They do it by running some code of their own instead of just reading memory.

If you enter `Random(6)` as an expression, it will be replaced with a **number between `0` and `5`**. That's `0` to `whatever - 1`.

<img src="assets/week2/flow_random.png" width=300>

> More info: More Flowgorithm Built-In Functions
> <http://flowgorithm.org/documentation/intrinsic-functions.htm>
> <img src="assets/week2/flowgorithm_built_in_functions.png" width="450" />

___

#### _Random numbers in C++_

```cpp {.line-number}
#include <iostream>
#include <time.h>     // Including the C++ time library gives us the time(x) function

using namespace std;

int main()
{
  int secretNumber = 0;       // Declaring an integer variable to hold the secret number

  srand(time(0));             // Seed the C++ random number generator with current time.
  secretNumber = rand() % 6;  // Any number divided by 6 has a remainder from 0-5. 

  cout << "The secret Number between 0 and 5 is: ";
  cout << secretNumber;
  cout << endl;           // Asking console to go to the next line.

  return (0);
}
```

**Why `srand()`?**

> **Computers aren't random.** They're super organised. They need a random starting point for making random-seeming numbers. `time(0)` gives us the **time elapsed, in seconds, since 1970**. That's pretty random.

**Why `rand() % 6`?**

> `rand()` is a built in **C++ function**. When the line of code runs, it's replaced with a psuedorandom (kinda random) number **between 0 and 32,767**

* `a % b` is `a modulus b`. It means "divide `a` by `b` and give **just the remainder**"
* `11 / 6` is `1`, leaving a remainder `5`. So `11 % 6` is `5`"
* `12 / 6

> More info: rand
> <https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/>

___
