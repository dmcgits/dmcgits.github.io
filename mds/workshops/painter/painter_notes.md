# Workshop

## Intro


## Real time in graphics are hard to produce at 60 frames

## There are in game resolution meshes, and the meshes we really make

30K vs 12 million

** Look at our low poly axe. **
![axe wires](assets/axe_wires.png)

** Show the original in ZBrush **
Now this guy is the original axe. See all those little details? A big triangle doesn't have those.

## Game resolution info:

Very low poly might be 500 or fewer! **Tom talian's low poly, painted TF2 characters**. 
* One texture, 256x256.

![tf2 pyro](assets/tf2_low_pyro.jpg)

Quite high poly, we have **DVa from overwatch**. 
* 20,000 polys for her, 
* 22,000 for her mech base, 
* 15,000 for mech guns.
* 10 textures just for her body and hair, some asa large as 1024x2048

![dva textures](assets/dva_textures.jpg)


### There are polygons, and there are textures

People got really good at painting in the missing detail. 
But: no reaction to light! Turn them upside down and the light seems to come from the ground.

## What we really need is that detail so light can shine on all our nice detail

How do we get it back? Well, graphics cards are built to do what you just saw. Put nice textures on as many polygons as possible.

It has two sides, oen that moves the triangles and the other that draws the textures. Turns out it has some power left to burn, and clever people found a way to add textures that bring all the information back.. kinda! Close enough! And fast.

** Import the normal map, apply some metal **

### Apply a few materials

Oooo

** Apply some other materials, some basic wood, some basic cloth **

## Lighting

Well, it's all a bit black and white isn't it? Do we have to paint in moodlighting?

** Switch environment maps. Rotate them **

## Procedural power!

Okay that's all nice, but we still have a lot of painting to do. Allt he edges of the metal have no damage, the wood isn't shiney where you've touched it.

Well it turns out those smart people found other ways to use textures. Like to say where edge wear is likely, or where light can't reach. It takes a long time to bake these maps, but once they're made, painter can make textures out of them.  And we can bake out the maps that any game engine needs to run quick!

** Bring in the other maps and bam, smart materials**

## Finally, we're missing something, this doesn't look like a PS4 game

** Turn on some post effects: bloom, contrast, depth of field **

Hooray!

## take home

Take some screen shots!
Set up an export maybe that they can view on their own computers at home??  FBX, some maps already set for a free viewer?




