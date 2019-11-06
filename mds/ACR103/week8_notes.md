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

1. [Week 8: Finalising Assessment 2](#week-8-finalising-assessment-2)
   1. [This week](#this-week)
   2. [How to deliver the assessment](#how-to-deliver-the-assessment)
2. [// Make Video](#-make-video)
3. [// Make video](#-make-video)
   1. [Using Unity materials](#using-unity-materials)
4. [// Make Video](#-make-video-1)
5. [// Make Video](#-make-video-2)
   1. [Necessary Lighting info](#necessary-lighting-info)
   2. [Basic UV unwrap](#basic-uv-unwrap)
   3. [Basic texturing](#basic-texturing)
   4. [Further learning](#further-learning)

<!-- /code_chunk_output -->

## This week
How to deliver the assessment
Setting the project to windowed and choosing a resolution
Using unity materials
Basic uv unwrapping and texturing of floor tile
3D Coat for those curious

## How to deliver the assessment

1. You **DO NOT** need to supply a build of your level.
2. I **DO** want your Unity project zipped up and named like so:
  **ACR103_Lastname_Firstname_Level**
3. You'll notice it has the name of the project I gave you, because I gave it to you to use as your base. **DO** import and build your level pieces in the project and scene I provided.
4. **DO** remember to put your actual Lastname and Firstname in there.

# // Make Video

### Project resolution

You want me to see what you saw in the game view.

* kIn _Edit->Project Settings_ head to _Player Settings_ and _Resolution_
* I already set it to _Windowed_. Change resolution to something common like **1280x720** or **1920x1080**. _(Mine used a weird vertical resolution because of the concept)_
* Open the "Game" window/tab in Unity if you don't already have it open, and make sure it's set to the target resolution rather than "free aspect ratio".

# // Make video

## Using Unity materials

The Unity materials work similarly to Arnold. They're based on the same 'physically based rendering' concept.
  - <https://docs.unity3d.com/Manual/shader-StandardShader.html>
  ![Material  Parameters](assets/week8/unity_material_parameters)
  - Albedo gives you basic colour control
  - Metallic goes from 0 (plastic/wood/cloth etc) to 1
  - Smoothness goes from 0 (completely matte) to 1 (sharp reflections)
  - Emission allows an object to emit light. HDR colours can go above 1 (the maximum for normal colour), to create bright light sources.

### A word on how we'll apply materials

We're going to be applying multiple materials to get different colours and surfaces. In a game we'd be using fewer materials and painting texture maps to control colour and surface on different parts of our models.

![dva textures](assets/week8/dva_textures.jpg)

We'll do that in assessment 3. For now we'll touch on the idea.

# // Make Video

### Using gloss and matte, metallic and not to create contrast.

Dark and light, contrasting colours, contrasting gloss and metalness.

### Assigning to objects in a prefab

Covered in this video last week:

<iframe width="720" height="480" src="https://www.youtube.com/embed/UeC2UtKhnk4" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

### Multiple materials for one fbx
Some assets need multiple materials, despite being exported as a single component to fbx:
* A wall with a window
* A table with cloth/metal components
* If you leave them as separate objects they will still be separate inside the fbx, and can have their own materials

# // Make Video


..If including videos i still need to live demo

## Necessary Lighting info

* Gloss only works once the reflect map (from the hdr environment) is baked
* Speed vs Quality: useful lightmap settings values.
* Make video, screenshot settings with fields hilighted

## Basic UV unwrap
Images of packaging and papercraft. Print some
Creating uvs
Cutting edges and unfolding
Auto unfold, auto orient, auto layout!
screenshot good settings hilighted
short video

## Basic texturing
Export uvs layout image
Import to photoshop/krita
Install Krita portable if you want to and don't have photoshop at home. (check krita 3D coat integration)
- [Download Krita portable for Uni workstation](https://sourceforge.net/projects/portableapps/files/Krita%20Portable/)

Create texture in ps/Krita and apply in Unity (we'll apply in Maya next assessment)
(Add very simple rivets and bevel hilights to tiles)
Edit textured meshes in 3D Coat
Export texture from 3D Coat, overwriting Unity texture
Class demo.

## Further learning
Apply texture to phong/lambert/Arnold mat in Maya.

