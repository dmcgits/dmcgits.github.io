---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: true
export_on_save:
  html: true
---

# Week 7 ISE102

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

1. [Week 7 ISE102](#week-7-ise102)
   1. [Covered this week](#covered-this-week)
   2. [Assigning values to variables of different types](#assigning-values-to-variables-of-different-types)
   3. [Overflow/wrapping](#overflowwrapping)
   4. [Compiler stuff!](#compiler-stuff)
   5. [Resources](#resources)

<!-- /code_chunk_output -->


## Covered this week

* How code becomes programs
  - Compiling, linking

* chars and strings

* using the debugger to look at variable values in memory. This helps us see what happens to values when we assign them to various types.

* Creating values for different data types
  - Refresher: `int, long int, short int.`
  - Differences in size (bytes, words, half words, double words.
  - More refresher: `float, double`.    
  - string, wstring, char, wchar, int, long int, unsigned long int

* Exam, briefly.

## Assigning values to variables of different types

When you assign a value to a variable, you write that value down with punctuation in a way c++ recognises.

A value written in code like `"Gary"`, `22.556f` or `435` is called a **literal**. As in `435` isn't a variable, it is literally four hundred and thirty five. 
  
  > **Very important to understand:**
  > When you write that value, C++ doesn't guess assume it's of the same data type as the variable you're assigning to. It goes strictly off the way you write it!

![](assets/week7/literals.png)
It basically creates a nameless variable to hold it.. then does the assignment. 

### Integer assignment

Integer literals are pretty simple. You write a number with nothing around it. However, we will find that what we assign it to makes a difference! 

### Exercise: Enter this code

![](assets/week7/debugging_literals.png)

Fortunately we dont have to use `cout` for every single variable to know what's stored in it.
> We can see what's in our assigned variables in _Visual Studio's_ debug mode by looking in the _Locals_ window.
> 
![](assets/week7/debug_locals.png)

#### Knowing what your variable can hold

This is super important if you don't want to lose or corrupt your data. You can't stick an elephant in a cat carrier without losing a lot of elephant.. in spaghetti form.

What's wrong with using `int` for `avengersEndGameBoxOffice_fail`? It 'only' handles numbers between `−2,147,483,648` and `2,147,483,647`
  - the default `int` type is shorthand for a `signed long int`
  - `long` means a **32 bit** `int`. `signed` means it has to include negative numbers in those 32 bits, halving the range of positive numbers
  - An `unsigned int` can go up to 4,294,967,295
  - Look at the table to see what a `long long unsigned int` can hold.

![](assets/week7/data_types_a.png)
![](assets/week7/cpu_ryzen.jpg)
![](assets/week7/ram_plain.jpg)

#### Ooops, float to int.
It's also bad to assign a float literal to an int if you don't intend it.

If you assign `0.41f` to `int age`, you'll get 0.
  - It will be created for a moment as a nameless `float`, then assigned to the int
  - its value is copied, everything after the `.` is chopped and the result stored in `age`.
  - Finally, our nameless, accurate, temporary float vanishes.

### Floats and doubles

**The `float` data type** stores numbers with a decimal point including scientific notation:
* 11.5 
* 1.2*10<sup>-20</sup>
* 0.00000002.

A `float` is stored in 32 bits of memory, where a `double` has 64 bits. 

>Be careful not to add an `f` when assigning to a `double`. `0.38423223423423423f` tells c++ you're specifying a `float`, and any precision it can't store will be lost. Then that chopped value is stored in your double.

![](assets/week4/floats_doubles_constants.png)

**More info:** https://www.learncpp.com/cpp-tutorial/floating-point-numbers/

 #### Is there a short float? 
 No, not built in, but there are specifications for them and libraries for using them.
 They're becoming very useful in machine learning, along with 8 bit floats.

 ### Chars and strings

`char` is a data type that holds a single character. It's really an 8 bit integer used to look up an entry in a standard ascii table.  _(ps: this is an over simplification)_

![](assets/week7/ascii-table.png)

#### The ugly reality behind strings

Strings are just arrays of characters with a `\0` at the end. The good news is _C++_ hides it from us with the `string` data type. C programmers had to deal with that `char` array drama directly.

 ![](assets/week7/string_type_under_hood.jpg)

### Declaring strings vs chars

```cpp
char letterF = 'f';
string letterF = "f";
string myStory = "Once, I was born. Eventually today came. Tomorrow I'll probably still be alive.";

// What would be the difference between these two in memory?
```

## Overflow/wrapping

See week 2 powerpoint.

## Compiler stuff!
We're making programs from c++ code. Obviously there is a big difference between a text file and a running program, so.. wth is visual studio doing to turn some text into that exe file?

Stages:
  1. our c++ files in an editor (can be anything)
  2. go into a compiler (many c++ compilers exist)
  3. obj/o files pop out   - why useful? Only compile what has changed
  4. linker joins them together with compiled libraries. Only those that change.
  5. Executable file pops out - operating system loads this into memory and begins executing instructions.

## Resources


### book chapters
* [chap 1 variables io](book_1/chap1_cpp_games.pdf)
* [chap 2 conditionals game loop ](book_1/chap2_cpp_games.pdf)
* [chap 3 strings arrays loops](book_1/chap3_cpp_games.pdf)

### Week 2
* [week 2 powerpoint 1 variables, expressions, operators](https://laureate-au.blackboard.com/bbcswebdav/xid-8618158_1)
* [week 2 powerpoint 2 conditionals, relational/logical operators, enums](https://laureate-au.blackboard.com/bbcswebdav/xid-8618160_1)
<!-- * [week 2 my notes](week2_notes.html)
* [week 2 code](week2_code.html) -->

### Week 3
* [week 3 powerpoint 1 arrays](https://laureate-au.blackboard.com/bbcswebdav/xid-8625465_1)
* [week 3 powerpoint 2 loops](https://laureate-au.blackboard.com/bbcswebdav/xid-8625460_1)
<!-- * [week 3 my notes](week3_notes.html) 
* [week 3 code](week3_code.html)

### Week 4
* [week 4 code](week4_code.html) -->