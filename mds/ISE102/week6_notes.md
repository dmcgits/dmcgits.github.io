---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Week 6: References and pointers 

Aliases, passing by value.

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 6: References and pointers](#Week-6-References-and-pointers)
  - [Things to do](#Things-to-do)
  - [Resources](#Resources)
  - [References and pointers](#References-and-pointers)
    - [Different and the same](#Different-and-the-same)
  - [References](#References)
    - [myscore_references.cpp](#myscore_referencescpp)
  - [Pointers](#Pointers)
    - [age_pointers.cpp](#age_pointerscpp)
  - [Sorting out the symbols](#Sorting-out-the-symbols)

<!-- /code_chunk_output -->

## Things to do

1. Type out the sample code above to understand memory addresses, references, pointers.
2. Dig into chapters 6 and 7 of the book, including the code examples. 
  - Understanding what references and pointers are will be critical to any career in C or C++.
  - The only way to really understand them is to use them.
  - Try creating a use for them and implement it in code. See if they work like you thought they did.

## Resources

Book chapters:
* 5: [Functions](book_1/cppgameprog_5_funcs_madlib.pdf)
* 6: [References](book_1/cppgameprog_6_refs_tictactoe.pdf)
* 7: [Pointers](book_1/cppgameprog_7_pointers_tic2.pdf)

___

## References and pointers
 They are types of variables used to pass _memory addresses_ around rather than data. 
   
   > Kinda like nicknames all lead back to single person, many references and pointers can get at to the same bit of memory and its contents.

On the technical side, we're really we're getting a look behind the curtain at the memory in which our data is stored.

> C++ famed low level status is in part due to it's ability to use pointers, because they are very powerful. With that power comes, as you might have guessed, complexity and danger.

### Different and the same

We've been passing things by value (copies). Kinda emailing a copy of your source code or word document to someone. They have their own copy they can do whatever with. But now you have two different copies to be aware of.

___

## References

> Passing things by reference is kinda like sharing an exercise book with someone. You can both sit down and write in it individually or at the same time, scribble over eachother's work.
 
That's the concept. In practise you're making a second variable name that is just an alias or nickname for another variable/function.

### myscore_references.cpp
```cpp
#include <iostream>
using namespace std;

void zeroAScore(int& score)
{
  score = 0;
}

int main() {

  int myScore = 1000;

  // You must initialise a reference because it is
  // like a constant in that you can't change which variable
  // it points to.
  int& dustinsScore = myScore;

  int& dbagsScore = dustinsScore;

  cout << "\t myScore is: " << myScore << "\n";
  cout << "\t dustinsScore is: " << dustinsScore << "\n\n";

  cout << "\t Adding 750 to dustinsScore.\n";
  dustinsScore += 750;
  cout << "\t myScore is: " << myScore << "\n";
  cout << "\t dustinsScore is: " << dustinsScore << "\n\n";

  cout << "\t ----- Trying to ZERO ALL SCORES via myScore -----\n\n";
  zeroAScore(myScore);

  cout << "\t myScore is: " << myScore << "\n";
  cout << "\t dustinsScore is: " << dustinsScore << "\n";
  cout << "\t dbagsScore is: " << dbagsScore << "\n\n";

}

```  

 References are nicknames: you can create a nickname for a function or variable. It will return the same data your variable would, ready to use.

 > You can put the & anywhere between int and name.

```cpp
 int big = 1000;
 // The following 3 lines are all equivalent.
 int& large =big;
 int & large = big;
 int &large = big; 
```
___

## Pointers

Pointers are the more technical, deeper version of references. In fact they're the mechanism behind references.

They do the same thing as references except you get the actual memory address. You can then "dereference" that address to get the object, or you can do math on the actual address to access objects. Arrays work a bit like that.

### age_pointers.cpp

```cpp
#include <iostream>
using namespace std;

int main() {

  int age = 5;
  int garysAge = 10;
  int* age_p = NULL;
  
  cout << "\t Age is: " << age << "\n";
  cout << "\t &Age is: " << &age << "\n\n";

  age_p = &age;
  cout << "\t age_p is:" << age_p << "\n";
  cout << "\t *age_p is: " << *age_p << "\n\n";
  // int* is the syntax to declare a pointer to an integer.
  // *pointerName_p anywhere in an expression is a "dereference", 
  // meaning give me the integer stored at the address, not the address itself.

  age_p = &garysAge;
  cout << "\t Changing age_p to point at garysAge" << "\n";
  cout << "\t age_p is:" << age_p << "\n";
  cout << "\t *age_p is: " << *age_p << "\n\n";

  // dereference the pointer to change it's contents
  cout << "\t Changing *age_p value (to 20), which should change garysAge value." << "\n";
  *age_p = 20;
  cout << "\t Gary's age is:" << garysAge << "\n\n";

}
```
___

## Sorting out the symbols

The * and & symbols have one meaning when they're in a declaration (int* blah) and another anywhere else. This diagram should help:

![star v amper](assets/week6/point_ref_doodle1.png)


