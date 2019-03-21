
start_function changeColourOnHit
    info: cube, paintball

    // api call: check for collision.
    if paintball has hit cube :
        // material colour change, getting colour from a material
        change cube colour to paintball colour
        // move paintball way off screen, deactivate paintball, or destroy/delete paintball
        // instantation particle explosion
        make paintball disappear

end function

make a component (extend monobehaviour) on the cube

shoot the ball at the cube

matchObjectColours(objectA, objectB);