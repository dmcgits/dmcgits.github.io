---
html:
  embed_local_images: false
  offline: false
export_on_save:
  html: true
---
# Week 9: Modeling Characters


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 9: Modeling Characters](#week-9-modeling-characters)
  - [Character modeling!](#character-modeling)
    - [Biting off what you can chew](#biting-off-what-you-can-chew)
  - [Assessment 3](#assessment-3)
    - [Deliveries by week](#deliveries-by-week)
    - [Week 11 Wednesday](#week-11-wednesday)
    - [End of week 12](#end-of-week-12)
  - [Why style reference?](#why-style-reference)
    - [2D and 3D side by side](#2d-and-3d-side-by-side)
  - [Choose your concept and style ref](#choose-your-concept-and-style-ref)
    - [On choosing a concept](#on-choosing-a-concept)
  - [Model with me](#model-with-me)
  - [// FILE LINK](#file-link)
    - [Priority 1: Folder organisation](#priority-1-folder-organisation)
    - [Pureref refresher](#pureref-refresher)
    - [Maya project setup refresher](#maya-project-setup-refresher)
  - [Modeling a basic character for texturing](#modeling-a-basic-character-for-texturing)
    - [Style reference](#style-reference)
  - [Texturing and UVs](#texturing-and-uvs)
    - [Textured characters: like vinyl wrapping](#textured-characters-like-vinyl-wrapping)
  - [UV with me (Time permitting)](#uv-with-me-time-permitting)
    - [Good and Bad UVs](#good-and-bad-uvs)
  - [IMAGES // Unfold and Layout settings](#images--unfold-and-layout-settings)
  - [Next week character uv and paint.](#next-week-character-uv-and-paint)
  - [Resources](#resources)
    - [Uv tutorials](#uv-tutorials)
    - [Krita painting app](#krita-painting-app)
    - [Kelvin Tan teaches 3D Coat](#kelvin-tan-teaches-3d-coat)

<!-- /code_chunk_output -->

## Character modeling!

![](assets/week9/character_mira_model_eelgod.jpg)
_Mira by [EelGod on Deviantart](https://www.deviantart.com/eelgod/art/Mira-Model-570220497)_

It's a deep subject
It includes:
* Prop and hard-surface modeling skills
  - They have props on them, they wear armor/tech
* Knowledge of anatomy, and mechanics of movement 
* Understanding of facial expressions and how to support them
* Great subtlety: the brain dedicates a lot of neurons to recognising human faces and forms. Tiny differences stand out.

![](assets/week9/rabbit_wires.jpg)


>**Anyone\* can learn**, it's just practise + study:
>- Anyone who is super invested
>- It requires a disgusting amount of hours put in
>- That's before and during a career, at work and at home

### Biting off what you can chew

We're learning a bunch at once: 
1. how to model a character from concept + style reference 
2. How to uv unwrap.
2a. How to uv unwrap a character, which is specialized
3. How to use 3D coat and photoshop in texturing
4. How to paint stylized characters for games
  
**That's more topics than we have weeks.**

The answer: we'll choose and model simpler, stylised characters with low polygon counts.

![](assets/week9/pinterest_character_concepts.png)

Once you get started texturing, it's up to you (and how much time remains) how far you take it.

![](assets/week9/rabbit_paint.gif)

## Assessment 3

Modeling and diffuse texturing a character.

[Assessment 3 page on blackboard](https://laureate-au.blackboard.com/webapps/blackboard/content/listContentEditable.jsp?content_id=_8008777_1&course_id=_75841_1)

> Diffuse texture: the colour layer for a character. As opposed to: normal map, specular map, metalness map etc.

### Deliveries by week

I'll be tracking discussion post updates each week, and this will feed into your marks on discussion participation and use of in-class techniques (30% of assessment marks)

We'll be posting in [the Assessment 3 forum
![](assets/week9/forum_a3.png)](https://laureate-au.blackboard.com/webapps/discussionboard/do/forum?action=list_threads&course_id=_75841_1&nav=discussion_board_entry&conf_id=_113215_1&forum_id=_771952_1)

#### Week 10 Wednesday

Due **Weds 20/11**, the day _before_ class day. Update discussion post with:
* A screenshot of pureRef displaying your :
  - 2D Concept image
  - 3D modeling/texturing style reference
* Discussion of what attracts you to the character concept and why you chose the style reference
* Screenshots of your 3D model in Maya showing its topology and form.

### Week 11 Wednesday

Due **Weds 27/11**, the day _before_ class day. Update discussion post with:
* Links to two other students' threads where you've commented on their model topology from week one
* Two Maya screenshot of your UV unwrapped character
  * In Maya's UVS workspace: perspective panel, uv editor.
  * With _image->dim_ enabled in uv settings so wires are clear
  * All character pieces selected so all uv wires are shown.
  * One shot with checkerboard turned on to show even coverage
  * Another shot with stretch/distortion hilighting enabled 
* A screenshot of your character in 3D Coat with baked ambient occlusion and first pass flat colours.

### End of week 12

Your final character model with texture applied.
More info incoming.

By 11:55pm week 12, **8 December 2019.**

## Why style reference?

Because you don't have a 3D style yet!

Because 3d outcomes can be veeery different from 2D. Also, every 3d art decision can go as many ways as a 3d decision, so styles are complex and can't be made up along the way.

Because when you work on a game you 3D model/texture to a style, just like 2D artists/character designers work to a style guide.

### 2D and 3D side by side

Here are some examples of what people have done with 2d concepts in 3d. (Several are more high poly 3D but the lesson is the same)

![](assets/week9/cat_mage_ovo_2dv3d.png)

![](assets/week9/girl_diboine_2dv3d.png)
![](assets/week9/bird_chu_2dv3d.png)
![](assets/week9/piper_axolotl_2dv3d.png)
![](assets/week9/catell_ruz_2dv3d.png)
![](assets/week9/lizard_mage_2dv3d.png)

## Choose your concept and style ref 

You'll need a pinterest account.

1. Choose a concept from [the character concept board](https://www.pinterest.com.au/dmacdraws/acr103/a3-character-concepts/) 
2. Choose 3D style reference from [the style reference board](https://www.pinterest.com.au/dmacdraws/acr103/a3-3d-style-reference/)

![](assets/week9/pinterest_3d_style_reference.png)

### On choosing a concept

We won't be using our own concepts for this.

Here's a discussion between the Flipped Normals guys (industry pro character modelers and teachers) about why modeling from your own concepts is a bad idea for early learning and making portfolio pieces:
[![](https://i.ytimg.com/vi/42pALQQefDk/maxresdefault.jpg?sqp=-oaymwEZCNACELwBSFXyq4qpAwsIARUAAIhCGAFwAQ==&rs=AOn4CLDoxuOQhZWlNYLhPYTwyr5clYyuLQ)](https://www.youtube.com/watch?v=42pALQQefDk&t=722s)
_The meant to say: don't (or rarely) use your own concept art for 3D modeling when learning_

## Model with me

Grab this download:
## // FILE LINK
PureRef portable, .pur file with images already in.

### Priority 1: Folder organisation

If you go in without a strategy, files and folders for even a single application like Maya or Unity get messy fast. 

> "Mess is the enemy of productivity." - every professional ever.

Let's start by making a folder structure. Here's an example I might use if I was modeling this Janice Chue concept:


```cpp
- acr103
  - assess
    - a3_crownBird
      - 3dc__cbird      // 3D coat working files
      - maya__cbird     // maya project in here for modeling
      - pshop__cbird    // photoshop texturing etc
      - ref__cbird      // pureref and plain image reference
```
      
### Pureref refresher

Right drag to move app
left drag to move image
ctrl-alt-left drag to resize image
c-left-drag to crop an image
ctrl-shif-c to uncromp


### Maya project setup refresher

Set up folder

## Modeling a basic character for texturing

* Identifying what needs geometry, what can be painted in.
* Minimum geometry for maximum value
* Poly count HUD
* Importance of hard vs soft normals

### Style reference

Style reference is critical
* You don't have one yet
* There are maaaany ways to translate 2D to 3D
* It's often not covered in the concept, and never 100% covered
* You will usually model to a style guide for a game
  
![](assets/week9/lizard_mage_2dv3d.png)


## Texturing and UVs

Textures are 2D images wrapped around 3D objects. Think of a cereal box: if you open the ends and cut down one long edge of the box, it can all be layed out flat.

To see the cereal box taken to fun places, check out papercraft toys:

![](assets/week9/papercraft_dracula.jpg)
[![](assets/week9/dracula_unfolded.jpg)](assets/week9/papercraft_dracula.pdf)
_Click unfolded Dracula to download a pdf pattern_

![](assets/week9/papercraft_sweet_monster_made.jpg)
[![](assets/week9/papercraft_sweet_monster_unfolded.jpg)](assets/week9/papercraft_tougui_sweet_monster.pdf)
_Click unfolded monster to download a pdf pattern_

![](assets/week9/papercraft_lootbox.jpg)
_No PDF: just download this picture to make a lootbox_


### Textured characters: like vinyl wrapping

![dva textures](assets/week9/dva_textures.jpg)
_Various layers of pbr texturing applied to DVa as images_

## UV with me (Time permitting)

Let's uv the guy we modelled. 

### Good and Bad UVs

**Objects have a default uv layout** when Maya creates them. Usually they become badly **distorted** as you model.

Think of when you try to wrap a christmas present. Wrapping paper has no stretch to it, so it wants to crunch up in some places and threatens to tear in others. If it was stretchy and sticky, you could get it to follow the surface, but it would stretch and compress the reindeer on the wrapping.

![](assets/week9/uv_stretch_ball.jpg)


When we uv unwrap we kinda have that sticky, stretchy material. The challenge is to find ways to reduce that without stretching the image too much. 

![](assets/week9/uvs_tile_bad_extruded.png)
_One side looks blank, the other is striped and full of errors_

#### Create new starting UVs:
  
  - Go into Maya's UV workspace
  ![](assets/week9/maya_uvEditing_workspace.png)
  - In the perspective view, tumble and look the model from above at 45 degrees, like in the image below
  - UV Tookit -> Create -> Camera-based
  ![](assets/week9/create_uvs_camera.png)
  
The new UVS are distorted in 2D to resemble what the camera saw. They're all joined together like the mesh too. We need to cut it like papercraft.

#### Cutting and unfolding
  - In edge mode, select (and shift select) edges to cut
  ![](assets/week9/select_edges_to_cut.png)
  - UV Toolkit -> Cut and Sew -> Cut
  
These next steps were all done by hand previously (and often still are):
  - Select all edges
  - Uv Toolkit -> Unfold -> Unfold
  - Uv Toolkit -> Arrange and Layout -> Auto Orient
  - Uv Toolkit -> Arrange and Layout -> Layout
    - We'll try to roll with default here
  ![](assets/week9/uvs_unfold_orient_layout.png)
  _Unfolded, oriented, then laid out. Colours altered in photoshop._

Unfold and Layout have plenty of settings. Lets have a look at good settings to start with.

## IMAGES // Unfold and Layout settings 

- [Download Krita portable for Uni workstation](https://sourceforge.net/projects/portableapps/files/Krita%20Portable/)

## Next week character uv and paint.

We'll talk more on character unwrapping as you get your models prepped for 3D Coat. Being so rounded, figures provide a lot of stretchy challenge.

Compare the last two bearbricks on this sheet: iron patriot is carefully designed to avoid any stretching, pattern bear.. is less so.

![](assets/week9/bearbrick_turnaround_painted.png)

## Resources 

### Uv tutorials

I haven't watched yet:

[![](assets/week9/tute_uv_rabbit.png)
_Bunny unwrap tute made in 2018_](https://www.youtube.com/watch?v=VHUJ-kte1n8)

### Krita painting app
If you don't have photoshop at home, Krita is a great free alternative. 
* For your own machine you can download the full installer, 
* On a uni workstation you'll need the portable (runs without install) version:
  - [Download Krita portable for Uni workstation](https://sourceforge.net/projects/portableapps/files/Krita%20Portable/)

### Kelvin Tan teaches 3D Coat

I first learned how to texture in 3D coat from Kelvin's sci fi gun tute. He's a (former?) Blizzard artist who worked on WoW. Along the way he drops knowledge on lighting, design, readability and more.

[His tutes on Gumroad](https://gumroad.com/turpedo#uYYtu) are paid ($10 US for the gun tute) so I can only suggest that it's very, very worth your money. And more.

[![](assets/week9/scifi_gun_Kelvin_Tan.jpg)](https://gumroad.com/turpedo#uYYtu)
