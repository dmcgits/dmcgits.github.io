GPR103 week3

Talk about last homework

Quick revise?

### Inheritance

### Polymorphism

### Abstract

You can see then that a function we want to be in all children, like build(), might not have any need for code in the root Tower class. It's kind of a template to build all the towers off.

> We could make an empty function and put a comment asking all other coders to make sure to override it with their own code. But they might miss/ignore the comment.

What's better than asking? Forcing!

The `abstract` keyword lets us define a function with no content. It also fails to compile unless the function is overriden by any Class that inherits from it.

```cs

abstract example
```