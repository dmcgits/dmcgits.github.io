
// shoot an automatic weapon till ammo gone

I have: automatic weapon, amount of ammunition
I know: firing rate as a delay between bullets, reload delay, full ammo amount


while left mouse held down:
    
    while I have bullets remaining:
        
        shoot one bullet
        wait for bullet delay

    end while
    
    start reload animation
    wait reload delay
    set ammunition to full ammo amount

end while

// game loop
// rendering a series of frames

while (player hasn't quit):
    check for input (kb and mouse, or console pad)
    simulate the game
    draw graphics on screen
loop while




