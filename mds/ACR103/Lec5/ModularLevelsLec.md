# Modular Level/Environment Design

## Game Levels
Game level: A place you explore in a game. There are usually points to start off, and an exit or goal.

<img src="https://ucfc3120fff70dd62184e54fd569.dl.dropboxusercontent.com/cd/0/inline/AS44s2jxsoWHH1Bt5NRaMDmGbRwi5U-QjhnSFRgckgIaL4RDiww4ZQIid4vt6RH1TR_hfDj0jBCVYNvrH6Rp4lZ-xrld5QsQaJr-wrMsMtFCiT3BDV1HQmF9AK8ikngq1djHka3oSr4t0VkrKUIZ-rQCRpZXYzGXIhtefz4ir6U9GOdJbtA2f4HNR9ZkIGyayQA/file" />  

_Guacamelee_

![Top Down](https://uc9eb4d846bd57bc01a3c715ffc8.dl.dropboxusercontent.com/cd/0/inline/AS6RCl1JFcazsS6Y2mLlk4I07nmbg662Dn_WLrJcRkX7qJAdfXzrFxt77ZMPtrdp1ckTg0ru27awtLJ55uBk08J7fI9hJ525GADNSVWOXkXYOn9LhMkcHQASSmESVc0FDK4kH-W-PL6aFTkJwBWJ9Iq0JEheyzb6Gg9s8_A4OlN7jyi_PGwtCnUh2oDOJc8Unyo/file)

_Level 8 by Lord Mithios on Deviantart_

## Things a level has
The list of things a level has could go on forever, or a level can have none of them. It's up to the designer and the game type. Here are some of the most common. 

> 1. Spawn points
> 2. Ground, barriers, sky or ceiling
> 3. Obstacles
> 4. Items. Pickups, hazards, info points.
> 5. Enemies
> 6. Bosses
> 7. Paths for you/Enemies
> 8. Secrets
> 9. Often an exit or goal.
> 10. Collidable things 

In a game these things could be defined by geometry, by imported xml/bsp files, by objects placed in an editor, completely in code, or any other method a team comes up with. We'll use Maya and Unity.

![Level Editing In Unity](https://uc88364ee5a764e177af773e09bb.dl.dropboxusercontent.com/cd/0/inline/AS5G4jxhMXt2pps-1V9sV6HP7EYGOGuDI3h8iGz4LlMi4kyfMACPEfZlftYtRRvYsPHZn34JGcWCE5-FpdQ6lTEpDvl9wXRInJ7ntK-WVISrs47OZu4t3xgPdO2BvcJRIEHUU546VVH-nYTUzXP_QTVNv6dTkmwWo6_1_4HKGE6mU5qaHK0n0C0FJ42vYeZYKBQ/file)
_Unity level editing_

![Tile based map editor](https://uc84a620dd383d7126179090374b.dl.dropboxusercontent.com/cd/0/inline/AS65Xe_MLOKE5FTSaL92qoqH9v1AjduVnvMGZn-Ap9x3fbvY-bHbeyTyDCNifW2uj0GD19O1uFugpNTdp9EBbvhfzakzCxIm5RNUhoiRY4zfT0SJyGBAcsXqjGqsEOMUj9bGfdMaS6JII8LVwK90ts0PMM06ZMMcCQ8zai4wxTBPwMuObExPF0pi8cD9aV7o5yU/file)
_Tile based map editing_

## Modular Construction
<img src="https://2ecffd01e1ab3e9383f0-07db7b9624bbdf022e3b5395236d5cf8.ssl.cf4.rackcdn.com/Bundle-1600x1600/d279610e-a0ef-4841-9d0b-05278881d936.jpg" width=250 description="Modular shelving" align="right" caption="modular"/>  

> Modular: Made up of compatible, standardized units for easy and flexible construction.     
  
Real world environments are big, varied, but also have a lot of repeating features. We need to reduce our concept art to pieces that can snap together seamlessly, or at least in a way that baked light, shaders or post effects can cover for (like ambient occlusion or grungy cavities.)  

Here are some of the central ideas:
> 1. Define the footprint of pieces
> 1. Only use non uniform pieces last resort
> 1. Pick a pivot and stick with it
> 1. Base kit for simple, square based layout
> 1. Inserts to make it organic, cover corners and seams, add interest.
> 1. Lighting brings atmosphere and more variance.
> 1. Obects!

  
<img src="https://uc41138fba2b6edbac76249e5e83.dl.dropboxusercontent.com/cd/0/inline/AS44wrea8qz4-2SHMtyj6yaaarLpOW8ap67kKV-qCTCNzyhesRgRKNhiTMo2jt5JO_2uAMUkdB5Cb9Gi_BNuYmwwNEXkCKSaobBG6OBEI5ZXSA7OXfVPmjr0sF9u1Juka1834cgyQq-Vpw6h8_DqXK0SY-5N2Bkv-lz3i1fvCE2Vbv2rL48kMhFoZbjoFRz1Gl0/file" description="Fallout4Bits" caption="modular"/>  

_Fallout 4 GDC_  
[Youtube Link](https://www.youtube.com/watch?v=QBAM27YbKZg&t=330s)


<img src="https://cdnb.artstation.com/p/assets/images/images/002/909/175/large/baldi-konijn-wipdungeonassets.jpg?1467144893" description="Modular shelving" caption="modular"/>  

_Modular dungeon pieces, Baldi Konijn:_   
[Arstation Link](https://www.artstation.com/artwork/3a0yo:)

## Technical Considerations
1. Levels are big, we can't use a lot of geometry on each piece. Exception: geometry instancing.
2. If we need to reimport a piece we want it, usually, to update wherever we use it. Unity uses prefabs for this.
3.  We need to not use a mountain of textures because our target has limited ram, our user limited file space. So we repeat a lot of the same texture. Different UV procedures.
4.  Lots of materials and objects = lots of drawcalls = low frame rate. Techniques like atlasing and batching can get around this, but we have to build accordingly.

INSERT ATLASING STUFF
INSERT BATCHING STUFF
INSERT PREFAB STUFF