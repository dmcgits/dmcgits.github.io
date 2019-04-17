# Week8: Sprites, saving state

Atlasses, loading and swapping sprites, loading and saving to JSON.


<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

* [Week8: Sprites, saving state](#week8-sprites-saving-state)
	* [Sprites](#sprites)
		* [Quick history](#quick-history)
		* [Now](#now)
		* [Atlasses, sprite sheets](#atlasses-sprite-sheets)
		* [Unity atlas creator](#unity-atlas-creator)
	* [New example git repo](#new-example-git-repo)
	* [Loading from a sprite atlas](#loading-from-a-sprite-atlas)
		* [The code:](#the-code)
	* [Load/Save](#loadsave)
		* [What? (config/state)](#what-configstate)
		* [Keeping your stuff ready to save](#keeping-your-stuff-ready-to-save)
		* [Parser/JSON](#parserjson)
		* [Using Json.net in unity](#using-jsonnet-in-unity)
	* [Writing/Reading files.](#writingreading-files)
	* [Resources](#resources)
	* [Todo](#todo)

<!-- /code_chunk_output -->


## Sprites

What are they? How to use?

![bomberman](assets/week7/sheet_bomberman.png)
_Bomberman Super Nintendo sprites_


![sonic](assets/week7/sheet_sonic.png)
_Sonic by Neweegee!_

___

### Quick history
Sprites are just 2D drawings. 
* Screens were low resolution, so sprites were too. 
* Memory was precious, power was limited, so very few frames and a limited palette 
* 1, 4, 8, 16 colours, 1 taken for transparency
* Things often in powers of 2 due to binary and registers/memory. Anything that leaned on what a computer was best at gained performance.

![bubble bobble](assets/week7/bubble_bobble.png)

Sprites grew larger and more complex as 2D hardware improved and memory grew. 

![Sprite complexity 1](assets/week7/bb_sprites_1.png)
![Sprite complexity 2](assets/week7/fgc_sprite_res_1.png)
![Sprite complexity 2](assets/week7/fgc_sprite_res_2.jpg)

___

### Now

Sprites aren't really drawn to the screen pixel by pixel, 1:1 as they used to be. The hardware 

___

### Atlasses, sprite sheets

Keeping draw calls, memory usage, file size down. 

### Unity atlas creator

They're created like materials and sprites, then you populate them:

1. In project window right click->create->sprite atlas 
2. In the atlas under _Objects For Packing_ you can add folders, sprites, 2D textures. **I added my folder and it auto packs my sprites as I add images**
3. Set _Filter Mode_ to _Point_ if you are using pixelated art and might scale.

![atlas charabits](assets/week7/atlas_charabits.png)

___

## New example git repo

I've made a simplified example. Grab this project that uses the sprite swapper from git. You can download it into a folder called _week8_code_ (for example) using this command, or just use GitKraken/SourceTree.

`git clone https://github.com/dmcgits/gpr_week8.git week8_code`

![save switch](assets/week8/sprite_save_switch.jpg)

---

## Loading from a sprite atlas

There are two easy steps to loading from a sprite atlas. First here's our Graphics folder, note the file names and the packed atlas preview.

![atlas folder preview](assets/week8/atlas_folder_preview.png)

Here's the inspector for our character game object, with its **sprite renderer** and slot for a sprite **atlas**.

![sprite inspector](assets/week8/inspector_sprite.png)

### The code:

>The code, then, just needs to change the sprite in the renderer, and do so with a sprite pulled from the atlas by file name.

In this simple example I've put it in `SwappySprite`, a component on the character. In your customiser you'd put it on the model.

```cs
[SerializeField]    // Make a slot for our sprite atlas in the inspector
private SpriteAtlas _atlas;  // Make sure you drag it over from the project

private SpriteRenderer _renderer; // keep a reference to our sprite renderer

private void Awake()
{
  _renderer = gameObject.GetComponent<SpriteRenderer>(); // get reference to renderer
}

 private void ChangeSprite()
    {
        // We can assign directly to the renderer's sprite, and
        // the atlas can give us any packed sprite by file name.
        _renderer.sprite = _atlas.GetSprite("spr_zelda");
    }
```

## Load/Save

Before we ask how to save, we need to know what we're saving.

### What? (config/state)

> When we save a game or character we want to go back to where we were. Same ammo, same position on map, monsters in same places etc. 
 
If it's a customiser, we want our character to load, and the interface to be in the right state. If you're a troll warlock you shouldn't see a list of human outfits for example.

To do that, we need to **save the _state_ or _config_ of our game**. If you're using a model this is easy because your state is really just what the variables in your model currently hold.

### Keeping your stuff ready to save

> Whether you use a model/game manager/whatever it's easiest to save that config if you already have it in an object or a struct.

Here's an example struct for our sprite swapper. Structs are basically objects/classes minus the functions (except constructor).

```cs
struct SpriteConfig
    {
        public List<string> names;	// file names of our sprites
        public int index;			// index of displayed sprite

		// simple constructor
        public SpriteConfig(List<string> spriteNames, int spriteIndex)
        {
            names = spriteNames;
            index = spriteIndex;
        }
    }


private void Awake()
{
		// Make a list of filenames
		var names = new List<string>() { "spr_zelda", "spr_link", "spr_zelda_roar", "spr_link_hide" };

        _config = new SpriteConfig(names, 0); // create+init an instance of our SpriteConfig struct
}

```

### Parser/JSON

If we're using an object to store all our state, it would be great if we had a text format that easily held object information. 

> JSON, or Javascript Object Notation, is that text format. 
> 	* It is a very widely used standard
> 	* There are writers and parsers for most languages
> 	* Unity has a crap convertor but the proper c# .net one is free the asset store

Here's some json. It looks a lot like the set notation we use to define a list or a dictionary. You can see a sub object car, which is maybe a dictionary of cars, or an object with 3 variables. You can clear that up on import by specifying the type to convert to.

```json
myObj = {
  "name":"John",
  "age":30,
  "cars": {
    "car1":"Ford",
    "car2":"BMW",
    "car3":"Fiat"
  }
 }
```

The Json .net asset on the store: <https://www.assetstore.unity3d.com/en/#!/content/11347>

![Json.net](assets/week8/json_dot_net_asset.jpg)

### Using Json.net in unity

Converting an object from something in memory to a string you can store in a file is known as _serializing_. It's just a thing you'll remember. Serialize, deserialize. A string is a _series_ of characters.

```cs
using Newtonsoft.Json;
..
string toJson()
{
	// Serialize the SpriteConfig stored in our variable _config
	string configJson = JsonConvert.SerializeObject(_config); 

	return configJson
}

SpriteConfig fromJson()
{
	// If we don't tell deserialize what type of objects to make, it might make 
	// conversions (list? array? object?) we don't want.
	object config = JsonConvert.DeserializeObject(loadedJson);

	// But we can also pass it in the type we want it to produce using
	// our old friends the angle brackets
	SpriteConfig loadedConfig = JsonConvert.DeserializeObject<SpriteConfig>(loadedJson);

	return loadedConfig;
}
```

## Writing/Reading files.

Veeeerry tricky.

```cs
using System.IO;

string _savePath = Path.Combine(Application.persistentDataPath, "swappy_sprite_config.json");

File.WriteAllText(_savePath, configJson); // Save file

```

```cs
if (File.Exists(_savePath)) // Don't try to load a file that isn't there
{
	string loadedJson = File.ReadAllText(_savePath);
}
```

Not really.

## Resources

## Todo