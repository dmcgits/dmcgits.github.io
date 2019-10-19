---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: true
export_on_save:
  html: true
---

# Week 6 ISE102


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=2 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 6 ISE102](#week-6-ise102)
  - [Covering today](#covering-today)
  - [Checking your coding conventions](#checking-your-coding-conventions)
  - [Delivering Assessment 1 Files](#delivering-assessment-1-files)
  - [Adding Colour](#adding-colour)
  - [Working on your assessment](#working-on-your-assessment)

<!-- /code_chunk_output -->

## Covering today

* Coding conventions and advice.
  - expanding on if statement usage
* Delivering assessment 1.
* Pretty colours using termcolor. Using colour to communicate.
* Using ascii art make a clearer, more engaging interface.
* Feedback and help with assessment.

## Checking your coding conventions

In every team or project we use coding conventions so we humans can read the code a little better. It helps your debugging and my marking.

**Using naming conventions correctly is worth marks**, and they're easy marks so go through and check!

Naming conventions
  - case
  - function, bool, constant naming
  
Code:
  - use {} in any multi-line ifs, espectially with else! Clarity.
  - Not required, but constants/variables can read better with tabbing
    - tabbing for the comments helps too. Table style.

### Naming conventions

#### Constants

```cpp
///////// Constants /////////////////////////////
// Numbers that won't change.
// Use ALL_UPPER_CASE with underscores between words

const int MAX_HEALTH                    = 100;
const int JUPITER_MOONS_KNOWN           = 79;       // look it up.
const float HEADSHOT_DAMAGE_MULTIPLY    = 2.5f;
const string DEFAULT_INVITE_TEXT        = "You have been invited to rumble.";

```

#### Variables

```cpp
/////// Regular Variables /////////////////////////////
// Storing data in memory. Read and write.
// Use camelCaseNaming.

int score = 0;
string myTag = "";
string myRealName = "";

// Use a name for booleans that would answer a question, and includes the question.
// Is it hot? Yes, it is true that the tea is hot.
// Has the player quit? Yes, the player has quit.
bool playerHasQuit = false;
bool allPlayersReady = false;  // are can be skipped here without hurting understanding.
bool teaIsHot = true;
bool prefers 

// An adjective using -able or -ible is good for describing an object's capabilities
bool destructable = true;
bool upgradable = false;

// Often, though, people use these adjectives as nouns for categories of things. A gun or armour or vehicle could be known as an "upgradable".
// prefixing with "is" can make it less ambiguous, though a little harder to read.
bool isDestructable = true;
bool isUpgradable = false;
```

#### Clarity beats brevity

Before we had autocomplete (intellisense) short variable names prevailed because they were easier to type. This made sharing code difficult, because variables were ambiguous.

  * Longer and clearer is better than brief and ambiguous
  * Within limits.. Too wordy and it becomes hard to understand
  * We're hunting for a goldilocks zone.

``` cpp
// Each of these are names that might be used for the difference between the 
// time now (delta) and the time the last frame was drawn to the screen. 

float dt                          =0.0f;  // Ambiguous for new engine/physics programmers
float deltaTime                   =0.0f;  // Better.. but what times are compared?
float timeBetweenFrames           =0.0f;  
float timeElapsedSinceLastFrame   =0.0f;  // Clearest, but a taxing read.

// INTERESTING NOTE:
// Google names variables like lower case constants. Long names are a bit easier to read.
float time_elapsed_since_last_frame   = 0.0f;
```
**Autocomplete**

* Hit tab or ctrl+space to accept an intellisense suggestion.
* Use up and down arrows to choose from multiple.
* No intellisense? Re-activate with ctrl+space

![](assets/week6/autocomplete.gif)

#### Code blocks with curly braces

These guys **`{}`** are curly braces. They're used in `if`, `while`, `do.. while`, functions and other places to show that a series of code statements belong together.

We'll prefer curly braces on their own lines: they are easier to line up visually. 

> Be aware some companies/projects take the opposite approach. Conventions aren't universal; you'll have to adapt to style of the team you're on, so don't get too precious/attached.

![](assets/week6/code_block_conventions.png)


<!--
```cpp
// Are the code blocks easier to see with braces on newlines? (yes)
float damagePerSecond() 
{
  int buffedDamage = damagePerAttack;
  
  if (damageBuff > 0.0f)
  {
    buffedDamage *= damageBuff;
  }

  return (_buffedDamage * _attacksPerSecond);
}

// Or mushed onto the end of a line? (noooo)
float damagePerSecond() {
  int buffedDamage = damagePerAttack;
  
  if (damageBuff > 0.0f) {
    buffedDamage *= damageBuff;
  }

  return (_buffedDamage * _attacksPerSecond);
}

```
-->
#### Functions

Here are some naming conventions for functions:

```cpp
////// Functions //////////////////////////////////////
// Use camelCaseNaming like regular variables.
// 
float damagePerSecond() 
{
	// Notice how you can immediately tell I'm using my private variables
	// to calculate a return value. The leading _ tells us.
	return (_damagePerAttack * _attacksPerSecond);
}

// function arguments: the same naming convention as public variables
// local function variables: also the same convention as public variables.
float damagePerSecond(int shotType) 
{
  int damage = _damagePerAttack * _attacksPerSecond;

  if (shotType == HEAD_SHOT) 
  {
    damage *= HEADSHOT_DAMAGE_MULTIPLIER;
  }

	return (damage);
}

// How it would look inside a Hero class cpp file with scoping.
float Hero::damagePerSecond() 
{
	// Notice how you can immediately tell I'm using my private variables
	// to calculate a return value. The leading _ tells us.
	return (_damagePerAttack * _attacksPerSecond);
}

```
Whitespace, Comments

## Delivering Assessment 1 Files

How to zip and submit your project:
  - Locating solution
  - Duplicate it
  - Delete all debug, .vs, x86, x64 folders
  - ONLY rename the solution folder if needed. Nothing else.
  - Zip up the solution
  - Naming it

Adding colour!

## Adding Colour

Right click your project in Visual Studio's _Solution Explorer_. 
Right click [termcolor.hpp](assets/week5/termcolor.hpp) and save it to your project folder.

## Working on your assessment

Tap tap tap.
