Week 10: Working with a basemesh
=================================

We want to start **very low rez** and drag things around. But this requires a fair bit more ZBrush know-how than just drawing, because you're going to exercise.. **control!** The muck-in-there-with-a-brush approach feels faster to start, but you **end up blocked** as detail grows or you need to change proportions. 

![sobo1](assets/week10/sobo_beaver.jpg)
![sobo2](assets/week10/sobo_fempro.jpg)
_ Scott Briscoe and Joao Sousa, created under Shane Olson_

**Staying low poly as long as you can** gives you a much stronger sculpt because it's hard to mess up great shapes and proportions, and **near impossible to save a bad base with detail.** It's blockouts ZBrush style.

![bo3](assets/week10/bo_stevejames.jpg)
_Steve James from his [2D-to-3D videos](http://www.cgmeetup.net/home/3d-to-2d-with-steve-james/)_

![pg0](assets/week10/zb_pg_and_density.jpg)

_Low poly is relative.. Zbrush low poly is pretty high_

What's a good base mesh look like?
----------------------------------

Those heads above, done for Shane's class, are built up from new primitives, but that's the point of that class and it's longer than ours. To save time, and like a lot of industry artists, we'll start with a flexible base mesh.

![brice](assets/week10/base_brice.jpg)

_Brice St Martin's base is pretty great_

Transforming
------------

`w`,`e` and `r` enter transform mode, just like in Maya. If you're in new ZBrush you'll see a Gizmo. In old ZBrush, you'll meet Transpose Line. `q` goes back to drawing.

![Xform](assets/week10/transform.jpg)

How do we scale a whole group of objects? if 2018, we have gizmo. If 4r7 we'll be using transpose master and transpose line. Yikes! Only because it's very unusual. In some obvious ways it's weaker than a gizmo, and in some surprising ways stronger.


Masking and automasking
-----------------------

How do we grow a chin or move an eye socket only?  We use masks, which are much like Marquee/Lasso selections in photoshop. It protects areas from change. Just like photoshop there are loads of manual tools for making selections and plenty of conversions/algorithms to create them.

> * tools->masking subpalette
> * ctrl+draw to mask.  
> * ctrl+alt+draw to unmask. 
> * crl+tap empty to invert
> * Rect,lasso,circle, algorithms and so on can control masks
> * soften/sharpen with ctrl tap surface, ctrl+alt+tap

![RickMask](assets/week10/mask_rickman1.jpg)

### Auto masking:
In the Brush menu you can turn on a few different auto masking modes. This is where ZBrush automatically limits what you can change, depending on where you start sculpting.
 > * topological means only polys sharing topology will move
 > * back face lets you sculpt on skinny things like blades
 > * polygroup auto mask is amazing!

Visibility
-----------

> * tools-visibility subpalette
> * ctrl+shift+draw area to remain visible (default is a rectangle)
> * ctrl-alt-shift-draw to remove from visible
> * ctrl-shift-click drag outside to invert
> * ctrl-shift-tap outside to remove (problematic: it's the inverse of the way mask works, makes it very hard to remember well)
> * All available in buttons like masking
> * Rect,lasso,circle, algorithms and so on can control visibility.

Polygroups
----------
> * tools-polygroups subpalette
> * ways to create
> * ctrl-shift click to a polygroup to hide others
> * ctrl-click transform mode to mask all other pgs

![polygroups pipe](assets/week10/pg_pipe.jpg)

![pic1](assets/week10/pg_mask.jpg)

_In transform mode, ctrl-click a polygroup to mask everything else_

![pic2](assets/week10/pg_visibility.jpg)

_ctrl-shift click a polygroup to hide other pgs_

------------------------

Reference And Proportions
-------------------------

Like Maya, Zbrush has multiple ways to use reference. ZBrush's are zanier: trickier to use, but with more variety.

![Check proportions](assets/week10/props.jpg)

_Using tool transparency and reference images_

![ZBrush See Through](assets/week10/seethrough.jpg)
_A slider turns zbrush see through. Yep._
