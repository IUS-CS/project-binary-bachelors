Our unit testing procedure involves setting up a few digital scenarios to test if the base mechanics of our game are functioning properly. 
This is done without even needing to create a new window to initialize the game, but instead by using the base values of our game to test our various objects and their interactions.

TEST 1:
'Lonk moves to the right'
This test is checking if our right directional horizontal movement is functioning as intended.
We start by initializing our player object and a money object which is used as a reference as well as their locations within the game space.
Next we give assign the player type to the game object of Lonk and initialize Lonk within our movement engine.
Then we give him the walk-right input.
Finally, we check to see if both the money's locations has stayed the same, and only Lonk's horizontal coordinate has increased; thus indicating that the player object has moved right.


TEST 2:
'Lonk moves to the left'
This test is checking if our left directional horizontal movement is functioning as intended.
We start by initializing our player object and a money object which is used as a reference as well as their locations within the game space.
Next we give assign the player type to the game object of Lonk and initialize Lonk within our movement engine.
Then we give him the walk-left input.
Finally, we check to see if both the money's locations has stayed the same, and only Lonk's horizontal coordinate has decreased; thus indicating that the player object has moved left.


TEST 3:
'Lonk moves up'
This test is checking if our upwards vertical movement is functioning as intended.
We start by initializing our player object and a money object which is used as a reference as well as their locations within the game space.
Next we give assign the player type to the game object of Lonk and initialize Lonk within our movement engine.
Then we give him the walk-up input.
Finally, we check to see if both the money's locations has stayed the same, and only Lonk's vertical coordinate has increased, thus indicating that the player object has moved up.


TEST 4:
'Lonk moves down'
This test is checking if our downwards vertical movement is functioning as intended.
We start by initializing our player object and a money object which is used as a reference as well as their locations within the game space.
Next we give assign the player type to the game object of Lonk and initialize Lonk within our movement engine.
Then we give him the walk-down input.
Finally, we check to see if both the money's locations has stayed the same, and only Lonk's vertical coordinate has decreased, thus indicating that the player object has moved down.


TEST 5:
'Lonk loses a heart’
This test is checking if our heart, damage, and collision detection mechanics are functioning as intended.
We start by initializing both Lonk and an enemy game objects, then assigning Lonk as a player object and the enemy as an enemy object.
Then we create a sprite for both Lonk and the Enemy as our hit box drawing can only be drawn to sprites.
Next we initialize the hitbox components for both Lonk and our enemy, and check to ensure that both game objects are active.
After that we set their locations to be on top of one another.
Next we initialize our collision detection engine and our health engine, and run both engines (the collision detection, and health engine) on Lonk and the game objects
Finally, we check to see if Lonk's health decreases from the base value while he is touching an enemy.

