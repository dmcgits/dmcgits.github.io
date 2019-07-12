
START MovingAtCellsPerSecond,
        NotifyChangingCells,
            TrackLastWholeCell

We have: 
    a 10x10 grid
    
    a snail with:
        a speed in cells per second
        a float position, a float last position
        a last whole cell

forever:
    multiply cells per second by fraction of a second elapsed (say 5 * 0.01)
    add that distance to position
    
    if round(position) is different from round(lastposition)
        print we've changed cells to cell round(position)
        store round(lastposition) as last whole cell
        
    clear screen, draw background and draw snail at round(position)
    print position, cell and last whole cell to screen.
    regardless, store replace last position with position
loop

END MovingAtCellsPerSecond etc



