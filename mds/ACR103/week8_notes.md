---
html:
  embed_local_images: false
  offline: false
export_on_save:
  html: true
---

# Week 8: Finalising Assessment 2

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=2 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 8: Finalising Assessment 2](#week-8-finalising-assessment-2)
  - [This week](#this-week)
  - [How to deliver the assessment](#how-to-deliver-the-assessment)
  - [Using Unity materials](#using-unity-materials)
  - [Necessary Lighting info](#necessary-lighting-info)
  - [Basic UV unwrap](#basic-uv-unwrap)
  - [Basic texturing](#basic-texturing)
  - [Further learning](#further-learning)

<!-- /code_chunk_output -->

## This week
How to deliver the assessment
Setting the project to windowed and choosing a resolution
Using unity materials
Basic uv unwrapping and texturing of floor tile


## How to deliver the assessment

1. You **DO NOT** need to supply a build of your level.
2. I **DO** want your Unity project folder zipped up and named like so, but with your own name:
  **ACR103_Lastname_Firstname_Level**
3. You'll notice it has the name of the project I gave you, because I gave it to you to use as your base. **DO** import and build your level pieces in the project and scene I provided.

![](assets/week8/unity_project_folder_contents.png)
_Common contents of a Unity project folder_

I step up one folder, right click the Unity project folder and right click it -> _Send To_ -> _Compressed folder_ or _z7ip_ -> _add to ACR103_McGillick_Level.zip_

![](assets/week8/project_zipped.png)
_The zip file made from my project folder._

### Project resolution

You want me to see what you saw in the game view.

* kIn _Edit->Project Settings_ head to _Player Settings_ and _Resolution_
* I already set it to _Windowed_. Change resolution to something common like **1280x720** or **1920x1080**. _(Mine used a weird vertical resolution because of the concept)_
* Open the "Game" window/tab in Unity if you don't already have it open, and make sure it's set to "Standalone" rather than "Free aspect ratio".

![](assets/week8/player_resolution_settings_game_standalone.png)

## Using Unity materials

The Unity materials work similarly to Arnold. They're based on the same 'physically based rendering' concept.
  - <https://docs.unity3d.com/Manual/shader-StandardShader.html>
  - Albedo gives you basic colour control
  - Metallic goes from 0 (plastic/wood/cloth etc) to 1
  - Smoothness goes from 0 (completely matte) to 1 (sharp reflections)
  - Emission allows an object to emit light. HDR colours can go above 1 (the maximum for normal colour), to create bright light sources.
  ![Material  Parameters](assets/week8/unity_material_parameters.png)

### A word on how we'll apply materials

We're going to be applying multiple materials to get different colours and surfaces. In a game we'd be using fewer materials and painting texture maps to control colour and surface on different parts of our models.

![dva textures](assets/week8/dva_textures.jpg)

We'll do that in assessment 3. For now we'll touch on the idea.

### Using gloss and matte, metallic and not to create contrast.

Dark and light, contrasting colours, contrasting gloss and metalness.

// screenshot of well textured object would be welcome

### Assigning to objects in a prefab

Covered in this video last week:

<iframe width="720" height="480" src="https://www.youtube.com/embed/UeC2UtKhnk4" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

### Multiple materials for one fbx
Some assets need multiple materials, despite being exported as a single component to fbx:
* A wall with a window
* A table with cloth/metal components
* If you leave them as separate objects they will still be separate inside the fbx, and can have their own materials

### // live demo

## Necessary Lighting info

* Gloss only works once the reflect map (from the hdr environment) is baked, giving the material something to reflect.
* Speed vs Quality: useful lightmap settings values.

### // Live Demo  of lighting
(coming soon:screenshot settings with fields hilighted)



