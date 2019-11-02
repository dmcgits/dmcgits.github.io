---
html:
  embed_local_images: false
  offline: false
export_on_save:
  html: true
---

# Week 7: Maya To Unity

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 7: Maya To Unity](#week-7-maya-to-unity)
  - [Next steps: assessment 2 week 7](#next-steps-assessment-2-week-7)
    - [Your final delivery](#your-final-delivery)
    - [What to do this week](#what-to-do-this-week)
    - [How do I do all that?](#how-do-i-do-all-that)
  - [Short getting started videos](#short-getting-started-videos)
    - [Prepping for export](#prepping-for-export)
    - [The Unity Project](#the-unity-project)
    - [Exporting to Unity](#exporting-to-unity)
  - [Making Modules](#making-modules)
    - [Prefabs](#prefabs)
  - [Expanded Videos](#expanded-videos)
    - [Stairs](#stairs)
  - [Realtime vs offline rendering](#realtime-vs-offline-rendering)

<!-- /code_chunk_output -->


## Next steps: assessment 2 week 7
The first deliverable was all about Maya and presenting on the class forums. 

> **Now we move to our assets to a the Unity game engine**, and use them to demonstrate how they can be combined to make a level. Just like you would for a real game.

### Your final delivery 
It'll be an area of a game level using the tileable, reusable pieces you made in Maya. It doesn't have to be a complete level. The goals are listed below

> You will **deliver your Unity project, zipped**, so I can explore how you've created your level area. - I'll show you how to zip and deliver it next week, and it will be in the week 8 notes.

- **Concept:** your level should show how you could build some of the area visible in the concept art you worked fromyou worked from, but also extend a bit beyond it using those same elements.
- **Modularity:** extend on that concept area to show that your modular pieces are flexible enough create a variety of levels.
- **Lighting:** I'm providing a scene that bakes in some hdr image likghting, use it to lay out your level. If you've already started in your own project, you can copy over your mesh, material and prefab folders to the new project. Message me if you're unsure.
- **Materials:** will be made and applied in Unity, and lighting will be baked in.

![](assets/week7/wip_unity_level_omega_level_stairs.png)
_Work In Progress: my level pieces assembled in Unity with some baked light (game view)_

### What to do this week

* **Grab my updated Unity project** and lit Unity scene from the notes.  You'll need it to avoid learning the Unity lighting system in a week.
  - [ACR103_Lastname_Firstname_Level_RENAME.zip](https://www.dropbox.com/s/zwh16jj6i2qhpim/ACR103_Lastname_Firstname_Level_RENAME.zip?dl=1) 
* Unzip it and rename the folder inside so it has your Lastname and Firstname. You should be renaming a folder that contains the Assets, Library etc folders.
* Add it to Unity.
* Export all your pieces to Unity from Maya. (videos in week 7 notes)
* Drag out those mesh pieces into the Heirarchy panel, then create prefabs for the modules you need.
Examples:
  - Floor piece,
  - tileable wall piece with floor piece,
  - tileable windowed wall piece with floor piece,
  - Two wall pieces with corner piece and floor piece.
Guidance:
  - Look at the examples of assets (from the unity store) in the week 8 notes
       https://dmcgits.github.io/mds/ACR103/week5_notes.html#assessment-2-environment-modelling
* Build out your expanded concept area as described in the assessment 2 section above.

### How do I do all that?

* There are **videos below** offering lots of help. 
  - You'll need to **google and read documentation/examples** to expand on what I've taught. 
  - You can also send me questions

## Short getting started videos

The videos in the sections below are unchanged from class. 

### Prepping for export

Each piece needs to arrive in Unity ready to use: 
* It has a reasonable name
* It appears at the origin if zeroed out
* If it's one 1m grid unit in Maya, it matches that in Unity

<iframe width="720" height="480" src="https://www.youtube.com/embed/Gzi4g21NnM8" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

**To add:**
// Insert short video on adding to and removing from display layers
// Grouping to organise
// How much prefabbing/modularity req'd
// More on Materials

### The Unity Project

1. Grab my (updated) [lit unity scene here](https://www.dropbox.com/s/zwh16jj6i2qhpim/ACR103_Lastname_Firstname_Level_RENAME.zip?dl=1)
2. Unzip it and rename the folder inside so it has your Lastname and Firstname. Erase the "RENAME" bit. You should be renaming a folder that contains the Assets, Library etc folders.

### Exporting to Unity

Next we'll import your level pieces into it.

<iframe width="720" height="480" src="https://www.youtube.com/embed/N0rx9-CBhBw" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

#### File export settings

![](assets/week7/fbx__export_settings.png)

#### File import settings

![](assets/week7/fbx__import_settings_model.png)
![](assets/week7/fbx__import_settings_material.png)

## Making Modules
<iframe width="720" height="480" src="https://www.youtube.com/embed/52moIwsKpIc" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

### Prefabs
<iframe width="720" height="480" src="https://www.youtube.com/embed/UeC2UtKhnk4" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## Expanded Videos

I've recorded some new, more in depth videos since class.  

### Stairs

These first few deal with adding the stairs to the Unity scene.
- Grab [ACR103_Lastname_Firstname_Level_RENAME.zip](https://www.dropbox.com/s/zwh16jj6i2qhpim/ACR103_Lastname_Firstname_Level_RENAME.zip?dl=1) if you haven't already.
- **Sift through the content** and see if it answers (or provokes) any questions 
- Use it as the base for your assessment. **import your own meshes** and delete mine.

![](assets/week7/unity_scene_wip_stairs.png)

#### The scene, the task, the plan:
<iframe width="720" height="480" src="https://www.youtube.com/embed/X1XSW7XNOu4" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

#### Tweaking, prepping, crashing, pushing through:
<iframe width="720" height="480" src="https://www.youtube.com/embed/6YUW9998U80" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

#### Exporting, crashing,
<iframe width="720" height="480" src="https://www.youtube.com/embed/93SVx4B9htc" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## Realtime vs offline rendering

3D rendering isn't defined by a single piece of software or target use/audience. It's the many ways that data definining 3D scenes/objects (in text or binary files) can be converted into viewable images.

**Arnold:** Offline renderer supported by Maya and other 3D programs.

![](assets/week7/arnold_scene.png)

**Unity:** A game engine and editing environment that uses a realtime renderer to create many frames per second.


> **Offline rendering** is the generation of images from a 3D scene to be used either statically or assembled into a video sequence. It can take seconds, minutes or hours to generate a single image.

![](assets/week7/groot_arnold.png)


> **Realtime rendering** is the very fast generation of images from a 3D scene to display games (or other experiences) at up to hundreds* of frames per second

![](assets/week7/fps_3_torb_hallo.jpg)
_60 frames per second enables exciting experiences like 'dwarf glowers at camera' and 'zombie council worker encounter'_

![](assets/week7/survival_1_scum.jpg)

_* A realtime game engine could in theory generate thousands of frames per second, but our monitors wouldn't make use of them._ 