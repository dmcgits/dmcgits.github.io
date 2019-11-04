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
- [// Make Video](#make-video)
    - [Project resolution](#project-resolution)
  - [// Make video](#make-video)
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
In _Edit->Project Settings_ head to _Player Settings_ and _Resolution_
I already set it to _Windowed_. Change resolution to something common like **1280x720** or **1920x
1080**. Mine used a weird vertical resolution because of the concept.
Open the "Game" window/tab in Unity if you don't already have it open, and make sure it's set to the target resolution rather than "free aspec ratio".

## // Make video

## Using Unity materials
PBR like Arnold.
Assigning to objects in a prefab
Different materials on objects in a single exported fbx
Using gloss and matte, metallic and not to create contrast.
Demonstrate in class

## Necessary Lighting info
Gloss only works once the reflect map (from the hdr environment) is baked
Speed vs Quality: useful lightmap settings values.
Make video, screenshot settings with fields hilighted

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

