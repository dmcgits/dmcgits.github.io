# Week 9

Recap A2.

Look at A3. Our goal is to get rid of the blank page and get things OUT of our head and onto paper/documents/hacknplan/github. Give yourself a base.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Week 9](#week-9)
	* [Your todos for next week](#your-todos-for-next-week)
	* [Assessment 2](#assessment-2)
	* [Assessment 3](#assessment-3)
		* [Gameplay](#gameplay)
		* [Set up Hacknplan](#set-up-hacknplan)
		* [Git project](#git-project)
		* [Unity Project](#unity-project)
	* [Systems and Psuedocode](#systems-and-psuedocode)
		* [Notes/Thoughts doc?](#notesthoughts-doc)

<!-- /code_chunk_output -->


## Your todos for next week

* Set up your hacknplan, message me a screenshot on blackboard.
* Watch finding objects video
* Watch prefabs video

## Assessment 2

My code. Questions, suggestions.

## Assessment 3

pdf: <https://laureate-au.blackboard.com/bbcswebdav/pid-7197509-dt-content-rid-11808950_1/xid-11808950_1>

Missile command using what we've learnt and proper project management.

### Gameplay

<https://en.wikipedia.org/wiki/Missile_Command#Gameplay>

A few design points:
* One trackball, 3 buttons
* 3 batteries have 10 missiles each, each controlled by one button.
* central battery is fastest
* If you're out of missiles before the attack stops, you must watch helplessly.

### Set up Hacknplan

Think of cards as cohesive chunks of work, and as problems that need cracking. Early ones are pretty easy, setting up

* Set up git
* Set up a working folder for the assessment, make aunity project.
* Example structure: 
>  - missileCommand
>    - unity
>    - psd
>    - resources

I add a project code to the end of the folders - super useful when they show up in your quick links or recent folders.

![folders](assets/week9/project_folders.png)

### Git project

Set it up, then clone the project into your `missileCommand/unity`

![gitkraken new clone](assets/week9/gitkraken_new_clone.png)

### Unity Project

Create a unity 2d project in another folder, say unityProject or unityTemp

![unity git folders](assets/week9/folders_unity_git.png)

* Now you can move the contents of the unityProject folder over to the unity folder you checked out from git and delete the empty folder.
* Changes appear in gitkraken
* Stage all the files, commit, push.

## Systems and Psuedocode

Before figuring out classes needed, write down all the systems you can think of in this game

* level setup and oversight: level manager. runs the model, starts stops game.
* game world model: contains entities and updates them, notifies listeners.
* Enemy attack spawner - wave
  * incoming missiles
  * planes
* player missile firing
* scoring system
* hud 
* gameplay physics: 
  * enemy missiles colliding with explosions, cities
  * planes being destroyed

Try writing basic pseudocode, just to get your brain going, starting with simplest form of game.


### Notes/Thoughts doc?