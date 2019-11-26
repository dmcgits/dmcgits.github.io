---
html:
  embed_local_images: false
  offline: true
export_on_save:
  html: true
---

# Week 11: Painting 2D Textures

<!-- @import "[TOC]" {cmd="toc" depthFrom=2 depthTo=3 orderedList=false} -->

<!-- code_chunk_output -->

- [Week 11: Painting 2D Textures](#week-11-painting-2d-textures)
  - [This week](#this-week)
    - [Tip on checking your proportions](#tip-on-checking-your-proportions)
  - [Open your imported model](#open-your-imported-model)
  - [Painting Textures](#painting-textures)
  - [Start with ambient occlusion.](#start-with-ambient-occlusion)
  - [Blocking in](#blocking-in)
    - [Major objects in colour](#major-objects-in-colour)
    - [Paint using pencil mode](#paint-using-pencil-mode)
    - [What's a middle tone?](#whats-a-middle-tone)
    - [Rough in the details](#rough-in-the-details)
  - [BIG TO SMALL](#big-to-small)
    - [More light and shadow](#more-light-and-shadow)
    - [Don't get caught up.](#dont-get-caught-up)
  - [Changes to the model](#changes-to-the-model)
    - [Reimporting a changed model](#reimporting-a-changed-model)
    - [Adding form to details.](#adding-form-to-details)
  - [Keep moving](#keep-moving)
    - [Zoom in and out](#zoom-in-and-out)
    - [Free yourself up](#free-yourself-up)
    - [Layers are faster until they're slower](#layers-are-faster-until-theyre-slower)
  - [Details: Edge control](#details-edge-control)
    - [Photoshop smoothing](#photoshop-smoothing)
  - [Face planes](#face-planes)
  - [Look at my model, recreate some stuff](#look-at-my-model-recreate-some-stuff)

<!-- /code_chunk_output -->

## This week

Q&A Uv unwrapping. Fixes

### Tip on checking your proportions

![](assets/week11/concept_check_proportions.png)

Screen shotting your model and laying the concept over it in photoshop is a great way to check you're in the right ballpark proportion wise. 
- 3D won't match stylised 2D perfectly, 
- Can check things like head to body ratio, placement of joints.

## Open your imported model
Last week's exercise was to unwrap and import your model to 3D coat.

## Painting Textures

* Overcoming the white model
  * So many brushes and infinite colours. Where to start?
  * Do I start painting in features? Do I start on the hair or the outfit?
  * Start quick and get the major info all in.
  
## Start with ambient occlusion.
So that you can see and think about the volumes, create some AO on new layers. One hemispherical, one spherical. Leave them on multiply.

## Blocking in

### Major objects in colour
Identify clothing, wood, skin etc before going forward. Work in a middle tone.

### Paint using pencil mode 
    * How to draw sharp/pencil mode in 3D coat
    * Jump to photoshop to demo, show pencil in ps
    * Great for selecting and hue shifting (0 tolerance/pixel wand)
    * Disappears when scaled down. (work at double size)

### What's a middle tone?
Light and shadow have to appear on the surface. What does the middle of that spectrum look like?

### Rough in the details
Paint a few of the smaller details as lines on another layer

## BIG TO SMALL

### More light and shadow
  
We can identify many of the properties of a material before we touch it.
  * How shiny/reflective is it?
  * How does it fold?
  
 ### Don't get caught up. 
  * Start big, think about light and shadow
    // Pictures: directional light on busts
  * Put those on layers that use blending so we can work under them
  * Hue shift! Light isn't white, shadow isn't black.
    * Shift the AO

  * I mostly use cel shading for first lighting, even if it requires some banding. 
  // PICTURES: CELL SHADING
  * If your character is nothing but soft gradients, use those. On layers.
 
// Pictures: aliased (jaggy/pixelated edges) vs anti aliased (smoothed/averaged edges)
// Pictures: select and fill on jaggy vs smoothed edges

## Changes to the model

Working with the model, you'll discover shortcomings of the model/uv unwrap you couldn't have anticipated. It's why we move fast, to make these discoveries while the work is still easily adaptable.

### Reimporting a changed model

You don't have to lose all your work just because you need to change the model/uv unwrap. There are options:
  - replace model in current scene
  - Export texture layers and import into new scene

### Adding form to details. 
How to go from flat to 3D.
  * Shadowed and lit planes

## Keep moving

### Zoom in and out
  * DON'T GET STUCK IN ONE AREA. Work big to small.
  * If you stay zoomed in you noodle around and forget big picture. Everyone.

### Free yourself up
  * create new layers and try stuff
  * It's digital. If you think you might reck it by trying something, duplicate the file. Save a copy of `dinoTexture.005.3b` as maybe `dinoTexture.005a.purpleEyes.3b` and go for it. If it looks bad, go back to .005.

### Layers are faster until they're slower  
  * Duplicate a couple of layers and flatten them, then you can smudge and colour pick easy again.

## Details: Edge control
  * When two planes/forms meet they do so in many ways. Sharp edge, soft edge, one side sharp, one smooth, etc.
  // PICTURE: various painted edges
  * This is critical to painting, maybe the second most important thing after lighting major forms.
  * We can do it with a few tones in pixel form if we want to stay adaptable

### Photoshop smoothing

This is complete magic. Sadly 3D coat, in my efforts so far, has never revealed a good blending/smudging brush.

> Shane Olsen, when asked how he made the Disney Infinity characters look so crisp when sculpting in ZBrush, said something along the lines of:
>  The best way to keep your forms super clean is to touch them as little as possible.

This is why the smooth brush is good. Humans are finicky, imperfect, organic things. To get a big soft transition, paint it harsh and then let the computer average/blur it out. 
- We don't try to draw perfect circles, we grab a compass (or ellipse tool) if we need that.
- Smoothing is the same.

It takes a lot of art experience and knowledge to know where and how much to do it, but the computer takes care of the inhumanly smooth averaging.

## Face planes
Changing textures is often the best way to get facial expressions on low poly characters.

## Look at my model, recreate some stuff



