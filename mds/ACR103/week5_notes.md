---
html:
  embed_local_images: false
  offline: false
export_on_save:
  html: true
---

# ACR103 Week 5


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=2 orderedList=false} -->

<!-- code_chunk_output -->

- [ACR103 Week 5](#acr103-week-5)
  - [Assessment 1 Received](#assessment-1-received)
  - [Weeks 5-8, modeling game environments](#weeks-5-8-modeling-game-environments)
  - [Assessment 2: Level Modeling](#assessment-2-level-modeling)
  - [How will we do it all?](#how-will-we-do-it-all)
  - [This week](#this-week)
  - [Next week (w6)](#next-week-w6)
  - [Styles and concepts](#styles-and-concepts)

<!-- /code_chunk_output -->

## Assessment 1 Received 

Thanks for assessment 1 submissions.
* A couple issues, i’ve messaged those people about correcting submission

## Weeks 5-8, modeling game environments

We'll learn about:
#### Modular modelling
  - Assembling usable level pieces from basic components
  - components like floors, walls, columns, doors
  - level pieces like repeating wall with floor, corner of room etc

**Modular (simple) in the real world:**

![bunnings shelving](assets/week5/BunningsShelving.jpg)
_Bunnings modular storage_

**Modular level construction:**

Examples by [Glenatron](https://polycount.com/discussion/158818/another-modular-dungeon-tileset):

**Components for making modules**
![](assets/week5/modular_dungeon_2.jpg)
![](assets/week5/modular_dungeon_3.jpg)

**Levels made from modules:**
![](assets/week5/modular_dungeon_1.jpg)
![](assets/week5/modular_dungeon_4.jpg)


| pieces      | makes
|---          |---
| wall        | basic component 
| floor       | basic component 
| wall+floor  | wall_floor module
| 2 walls + floor | wall_floor_corner module
| 5 x wall_floor  | one side of a corridor? | 

**NEEDS PICTURE** - Table here is fine but not alone

#### Texturing
  - uv unwrapping
  - Applying textures
  - Creating/editing textures
  - Using wacom tablets
  - 3d coat and painter

![](assets/week5/dagger_uv.png)
_Low poly dagger with hand painted texture (diffuse)_

![dagger maya](assets/week5/dagger_uv_grid.png)

**ATTACH MAYA PROJECT**

## Assessment 2: Level Modeling

(I'll provide a few concepts. You will be designing an environment based on the elements and style in them. You can modify the scene from say a level 1 dungeon to level 5 dungeon, or a lounge room to an attic bedroom). You can add elements that aren't there, but aim to match the style as if the game exists)
Designing and creating environment for game based on scope sheet from teacher

**Scope will include:**
1. Existing or theoretical world (ie strategy in world of paper blocks)
2. Creative expects: C.D., genre, texture quality/style, model quality/style.
3. Tech spec: poly count, texture specs, topology (quads or tris)

**10-15 modular assets! **

Lighting: export to Unity and bake in ambient occlusion.

DELIVERABLE: 
* Unity project
* Interactive level scene
I'll provide a unity project with the camera already set up.

## How will we do it all?

- Choose and modify/extend a concept
- Model and uv unwrap in Maya
- Test with a texture designed to help uv mapping
- Export to 3D Coat/Photoshop for texturing.
- Import components to Unity
- Make simple prefabs
- Snap pieces together
![](assets/week5/dagger_uv_grid.png)

## This week

### Styles
levels



More styles at end of notes

* Look through concepts/references
* Decide on level idea, style.
* Decide on modules you want, and how they'd break down into components

### Modules and components 

![](assets/week5/simple_town_modules.png)


### Choose your environment and style

Lots of styles and concepts at the end of these notes, many more on [my acr103 pinterest board](https://www.pinterest.com.au/dmacdraws/acr103/)
![](assets/week5/acr103_pinterest_levels.png)
Can match existing style as closely as possible, work directly from concepts in 2D.

### Rough design of your level
Sketch out an approximation of your idea (obviously more refining at home!)

### Figure out components you'll be making.
Getting started here. What do you see in the image? wall, flor, railing, stairs, column, sign?

### model and texture a wall and floor 

First, play in this scene to see what we'll be doing.

*ATTACH A MAYA SCENE WITH EXISTING MODULES FROM COMPONENTS, ALREADY SET UP WITH PIVOT POINTS AND GRID**

Make some modules by duplicating (ctrl-d) and moving components:
  - select translate tool (w)
  - enable grid snapping (hold down x)
  - click and drag the translate handle

**GIF OF DUPLICATE, DRAG, SNAP**

### Now, DIY

* Make a wall plane, a floor plane
* Make a column
* Move our pivot points using d (modify pivot)
* Place our objects

**GIF OF MOVE PIVOT**
Screen cap showing keypresses would be ultimate
  
## Next week (w6)

#### Assessment deliverable: present your designs in class
Work along as we uv unwrap a model, apply uv texture.
Pick simple component to model

## Styles and concepts

For these and more, continue to [my acr103 board on Pinterest](https://www.pinterest.com.au/dmacdraws/acr103/).

#### Blocky rooms and zones
![iso](assets/week5/iso_room_2_halcyon.jpg)
![iso](assets/week5/iso_room_3_imgur.jpg)
![](assets/week5/room_chunky_white.jpg)
![](assets/week5/nintendo_room.jpg)



### Snake Temple 
These shots are from [Bitgem's store](https://shop.bitgem3d.com/products/snake-temple-low-poly-3d-proto-series)
![](assets/week5/snake_1.jpg)
![](assets/week5/snake_2.jpg)
![](assets/week5/snake_3.jpg)

### Cartoony concepts

More Minxi Zhuang on Artstation

![](assets/week5/minxi_1.jpg)
![](assets/week5/minxi_2.jpg)

### Bangzheng Du concepts

Multi tier mayhem.
![](assets/week5/bangzheng_du_1.jpg)

### Baldi Konjin concepts

![](assets/week5/baldi-konijn-wipdungeonassets.jpg)


### Some simple, effective construction:

![temple](assets/week5/temple_1.jpg)
![temple](assets/week5/temple_2.jpg)
![temple](assets/week5/temple_3.jpg)
![temple](assets/week5/temple_4.jpg)

### Blocky shapes, relatively low fi textures

By cgart dot com, [on artstation](https://www.artstation.com/artwork/RzB5e) 

![](assets/week5/dofus_1.jpg)
![](assets/week5/dofus_2.jpg)
![](assets/week5/dofus_3.jpg)
![](assets/week5/dofus_4.jpg)
