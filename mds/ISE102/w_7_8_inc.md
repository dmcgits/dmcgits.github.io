Week 7 and 8 exam stuff

QUESTIONS TO REWORD/CHANGE
19 - 'a' vs a (char enclosing. it asks for the character though, NOT the char).
This could be covered as how to write literals: floats, doubles, ints, wstrings, chars.
The lowercase representation of the char literal 'A' in C++ is

Things to cover from questions

Compiler stuff!
We're making programs from c++ code. Obviously there is a big difference between a text file and a running program, so.. what is visual studio doing to spit out that exe file?
Describe this:
  c files
  compiler
  obj/o files    - why useful? Only compile what has changed
  linker    - link in the already compiled with the newly compiled.
  executable. - operating system loads this into memory and begins executing instructions.

Now go into the folders of a solution and show where these really are.

chars
  - note they have to have single quotes, vs strings with doubles
chars can come up as we cover un-covered or unusual data types.
Talk about char, string. 8 bit, list of 8 bit. char = 256 options. 
Talk abouc wchar, wstring. 16 bit, list of 16 bit.  wchar = 64K options.

chars vs strings - char is one thing. 
string is several chars with a \0 at the tail.

using int vs long int, float vs double. single precision float, double precision. 
Outline again what value wrapping is, with the gaming examples from week 2 powerpoint.

C++ can be written in multiple environments. I've already shown them in cpp.sh, maybe use it for an example or two and make the point explicitly.


Assignment and conversion:
What happens when you assign an int or char to a bool?
What if you assign the result of a test to an integer??
(week2 code has some goodies on assignment and conversion)

## Week 8 exam stuff
Teach the types of loops along with arrays and vectors. This will tie studying for the exam to studying collections, much needed for snake.
Arrays are in the exam (what value is index blah in the following array).
Teach if vs case, and dive into the weird things that break will do.

Cover enums again as they relate to a case statement.
Get people to change enum values and see what happens to other entries in the enum
if I change the first to four, what does the second do?
If I change the 5th to 12, what does the sixth do?
What if I make the 3rd one = 0?

The unary operators and assignment+increment operators come up. Along the road some will learn there's no +-. 
+=, +-, ++ and -- 

++x vs x++.

y = x++ is equivalent to:
y = x;
x = x + 1;

y = ++x is equivalent to:
x = x + 1;
y = x;




## Week 9
 first class of snake, that can be objects. We'll only use an h file at first: our point instead of a struct can be class point2D.