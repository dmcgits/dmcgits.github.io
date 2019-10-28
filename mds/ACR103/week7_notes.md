# Week 7: Lighting and texturing

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
