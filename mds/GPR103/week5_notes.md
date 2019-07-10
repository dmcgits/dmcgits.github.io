---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# Week 5

Assessment 1 summarise, assessment 2. Git, singletons and gamemanager. Observers and events if time.

## Assessment 1

* Due **end of this Sunday**
* Reminder of **part 1 clear brief**: [Link](a1_exercise1_brief.html)
* Deliver by 7zipping (or other compression) the **folder your unity project lives in**. It contains /Assets, /Library, /Packages etc. Don't worry about making a build.
* Your project must be **made in Unity 2018.2.x** 
  - This includes 2018.2.2f1 like on the uni machines, and more recent updates to that release like 2018.2.21f1. 
  - Does not include 2018.3.x releases or 2019.x. 
  - If your project is made in the wrong Unity release: install the correct one and import the project, fix any issues before submitting.
* Questions?

## Assessment 2

* Brief: [link](https://laureate-au.blackboard.com/bbcswebdav/pid-7523976-dt-content-rid-11808949_1/xid-11808949_1)
* Due end of Week 8 (end of sunday, Aug 4)

### Examples from past students

### My example

## Git
  
What is git?

> Git is a distributed version-control* system for **tracking changes in source code** during software development. It is designed for **coordinating work among programmers**, but it can be used to track changes in any set of files. Its goals include speed, data integrity, and [teams working on shared files without problems].

* Version control is the term for Git and systems like it, including mercurial, svn, (defunct) visual source safe and others.

### Git has a change history
It saves and records versions of your file so you can retreive them.
  * If you mess up your code or somehow completely overwrite it, you can retrieve it.
  * In the past you would have had to constantly duplicate your main.c file as main.c.bak1, main.c.bak2 etc. Or duplicate your project folder as backups. MyProject_old_old comes to mind.

### Git merges changes!
Without version control:
  * If you worked on something with multiple people, or work on different pcs, you'd have to copy the project to a usb/email the project/place it on a server. 
  * Other person does some work on it and returns the project, telling you what files they edited (as best they recall) and you copy them back over.
  * If they edited a file you also edited, oh hell: you need to look at the differences, mix your changes with theirs and check if the project compiles/works.
# Screen shot wikipedia git

### It does loads of other things

* Branching a repository (the name for where all the code lives) so you can work on a copy of the whole project, later merging the new bits back to the master copy.
* Tagging certain points in history as releases so you can get back whole old versions
* much git knowledge is shared and challenged on stack overflow
  
# Screenshots stack overflow

## Git and Clients

Git is a type of server/service software, and that server software is accessed/controlled from the command line. Fortunately there are lots of GUIS to help visualise and automate interactions with the server.

### Server

Git is software on a server or on your PC. 
* Github might have your offsite master repository
  - You clone it to your machine
  - commit changes to it all day
  - pull down changes by others during the day perhaps, merging them with your local changes
  - then push all your changes up to the server to be merged with everone elses.
* It keeps information in your project folder. 
* It is command-line operated, so it's all text commands typed in.

# Screenshot of git cli

### Clients

Sourcetree by atlassian (uni machines supported)
Gitkraken (free cross platform for basic edition?)

### Github use

* creating account
* making a repo
  - initialise with readme, gitignore
* cloning to your machine.

# Git Screenshots
  
### Moving your unity project into your github repo
* transferring a unity project into the folder you cloned repo into
* adding files
* committing
* pushing
* 
# sourcetree screens
  

