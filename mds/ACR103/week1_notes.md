---
html:
  embed_local_images: false
  embed_svg: true
  offline: false
  toc: undefined
export_on_save:
  html: true
---
# ACR103 Week 1


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [ACR103 Week 1](#acr103-week-1)
  - [Hello!](#hello)
  - [This week](#this-week)
    - [Resources](#resources)
  - [What is Maya?](#what-is-maya)
  - [Our first model](#our-first-model)
    - [Make a table top](#make-a-table-top)
    - [Transforming objects in Maya](#transforming-objects-in-maya)
      - [Duplicate an object](#duplicate-an-object)
      - [Mirror objects](#mirror-objects)
  - [Make a Barrell](#make-a-barrell)
    - [Create cylinder.](#create-cylinder)
    - [Editing edges with scale to create barrel belly.](#editing-edges-with-scale-to-create-barrel-belly)
    - [Creating rings with insert edge loop](#creating-rings-with-insert-edge-loop)
    - [Extruding rings](#extruding-rings)
    - [Adding top and base indent](#adding-top-and-base-indent)
      - [Go deeper: barrel modelling](#go-deeper-barrel-modelling)

<!-- /code_chunk_output -->


## Hello!

**Me:** Danny McGillick. Computer Science @ UTS, Web dev, Creative technologist in advertising (flash/actionscript, unity), 2D and 3D artist for Torus, Halfbrick, Blowfish studios. Keyboard enthusiast, bits maker.

https://cargocollective.com/dmac/ - Flash/Unity 
http://www.artstation.com/dmacdraws/ - game art

**You:** The next makers with long futures.

## This week

* Get into modelling in Maya 2019!
* Won't into the course too much
* Links to resources to study at home
![barrel concept](assets/week1/barrel_simple_solo.jpg)
_We'll model a similar barrel to this, designed by Alvaro Vera_

### Resources

Easy to find up here

* Interface basics YT: https://youtu.be/dbjAnutq1vQ
* Modelling basics YT: 
* Extrude (2019 help?)
* Slice
* Connect
* Other simple objects to model, with pictures
* Pureref portable zip
* Link to interface cheat sheet

## What is Maya?

Quick tour.
* Open
* Open a model
  - pic of dagger or chest -
* tumble, pan, zoom.
* Space bar, views
* Workspaces and resetting the worspace if you can't find something.
  
> **Go deeper:** 
>  [Maya Interface Tour on YT](https://www.youtube.com/watch?v=okaC2_NxPYQ&list=PLD8E5717592CF5C26&index=10)

___

## Our first model

Let's model a very basic table, something like this:

![simple coffee 1](assets/week1/coffee_table_simple_01.jpg)

### Make a table top 
First, we'll make it from primitives. We'll make several boxes, then move and resize them until they look like a table top and legs.

> Primitives are basic 3D prisms. Cube, pyramid, cylinder.


![create cube](assets/week1/table_create_cube.png)
_**Create primitives from the toolbar or menus (Create->Polygon Primitives**_





### Transforming objects in Maya
Move and scale the table top.

**QWER:**
* **Q:** Select an object with the cursor
* **W:** Display object moving handles
  - [Moving objects lesson YT](https://www.youtube.com/watch?v=1n89UOtMI_Y&list=PLD8E5717592CF5C26&index=7)
* **E:** Display object rotation handles
  - [Rotate Objects lesson YT](https://www.youtube.com/watch?v=BvsN5GzxoHo&list=PLD8E5717592CF5C26&index=8)
* **R:** Display object scaling handles (expand, shrink)
  - [Saling objects lesson YT](https://www.youtube.com/watch?v=Kmuf2M9Nvp0&list=PLD8E5717592CF5C26&index=9)

![cube default](assets/week1/table_move_cube.png)
_**The default cube appears in the floor. Move and Scale tools can help**_

![four view](assets/week1/table_four_views.png)
_**Tap the spacebar while hovering over the 3d view. Multiple views help when modifying a shape**_

#### Duplicate an object

1) Select the top, hit ctrl-d to duplicate the box. 
2) Now you can move and scale it to make a leg.
   
![dupe](assets/week1/table_duplicate.png)

#### Mirror objects
Create remaining legs in the right position.

Mirror settings 1.
* copy
* x axis (left right)
* don't combine

![Duplication](assets/week1/table_mirror_options.png)

Mirror settings 2.
* copy
* z axis (front back)e
* don't combine


![Table done](assets/week1/table_simple_done.png)

> **Go deeper**
> * Add thin top stretchers 
> * Add thick bottom stretchers
> * Make a table using edge loops and extrude (after barrell)
  
---

## Make a Barrell

![barrel solo](assets/week1/barrel_simple_solo.jpg)

### Create cylinder.

Need loops/edges around body.

### Editing edges with scale to create barrel belly.
  - edge mode. Try scaling.
  ![edge mode](assets/week1/barrel_maya_edge_select.png)

  - undo
  - enable z symmetry
  - scale.
  ![planar scale](assets/week1/barrel_maya_scale_belly.png)

### Creating rings with insert edge loop

  - turn on y (up down) symmetry
  - click Toolkit - Tools - Multi-Cut
  - hover over a vertical edge in upper barrel, hold ctrl.
  - click to cut. Enter to complete tool.
  ![cut](assets/week1/barrel_maya_multi-cut.png)
  
### Extruding rings

![face loop](assets/week1/barrel_maya_loop_faces.png)

1. Enter face mode
2. Select face loop. Click first face, shift-double-click adjacent. 
3. Extrude.

### Adding top and base indent

1. Select top of barrel. 
2. Inset with extrude tool.
3. Now extrude inwards.
![top](assets/week1/barrel_maya_top.png)
![basic](assets/week1/barrel_maya_done.png)

#### Go deeper: barrel modelling

Try adding more!
- Tilted lid
- Round or Square plug
- Ring made from another cylinder primitive.
- Toonify by making edges less regular/symmetrical

![toon](assets/week1/barrel_maya_toon.png)

![barrels](assets/week1/barrels_simple.jpg)