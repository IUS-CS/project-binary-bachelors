#Architecture

This document describes the general setup and architecture that our game The Legend of Zordo uses. 

#Development Programs
Our project is being developed using SDL2, SDL2 Image, and we are writing our code with vim text editor.

#Engines and Components
The game will run using its various game engines. These engines are similar to multiple programs running in conjunction with one another. These engines make up the key aspects and principals of our game. Each engine runs using .h, .cpp, and component.h files.  The primary engines we will use are...

Graphics Engine - This is for drawing the various sprites to the screen and mapping sprites to elements that use them.

Input Engine - This is used to accept user input from a keyboard and translate that into game commands that do various things from moving our character to using items.

Map Engine - To draw the backgrounds and initializing the objects we will later use for collision.

Movement Engine - Used to generate movement of various elements across the rooms from our player characters to enemies. This engine will change an objects position and update the program according to the movement.

Health Engine - The health engine will be used for determining the health of our player and enemies. This will also include instructions for health reaching 0 and dying, as well as invincibility frames right after the initial hit.

Collision Detection Engine - This is used to determine the active size of an object from players to enemies to objects. This can be implemented to not allow a player to walk through an object, and create the size an enemy can be attacked, or attack you.

Enemy AI Engine - This engine is used for developing the artificial intelligence the enemies will use when interacting with the player and environment, such as chasing the player or moving around obstacles.


Aside from our engines we also include speciality components such as...

Sprite Component - This Component is used to retrieve particular sprites based on the game object and their status, i,e. movement directions, and attack animations, death animation/state.

Location Component - Used to determine where an object is in relation to the map and the screen, updated frequently.
