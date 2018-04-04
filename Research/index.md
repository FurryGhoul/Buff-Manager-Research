# Ninja's Path

## Introduction
This is a 2D Platformer game created with the only purpose of learning how to create a game as a team.

## The Team<img src="https://drive.google.com/uc?id=1SUI-_vtJnh1_dBpWQIYwFUOo-o0mzvlI" width="225" align="left">


**Marc Garcia Uceda(left)**: He is responsible for the pathfinding, map drawing, entity system, the base structure for the GUI and the differential time of the game.


**Josep Pi Serra(right)**: He is responsible for the sprite sheets, the animations of the game, the user experience, the level design, keep the track of the goals, the web creation and applying the code provided by Marc and making some changes/ask for advice to Marc for changing it.

Both were active in the process of creating the GUI for the game.


## Core systems of the game.
Some of the goals we want to accomplish for the main core subsystems are:
- Printing a map using c++ and XML provided code provided by the program Tiled.
- Learning how a timer works and how it could help with the refresh rate of our game.
- How we could cap the fps of the game.
- Create a UML with the entities system to be able to make a class system that we can use in the game to create enemies.
- Study the different kind of pathfinding that we have available and implement the A* in our game.
- Create a GUI class system with the help of a UML scheme.
- Save and load implementation.
- Create a drawing function which lets you detect the colliders from the Tiled and print them together.
- Create Slowmotion.
- Creating behaviours in the enemies using the pathfinding code.

## Links
- Repository: [Link](https://github.com/MaxitoSama/GDJM)
- Release: [Link](https://github.com/MaxitoSama/GDJM/releases/tag/2.0)

## Gameplay Video

<iframe width="560" height="315" src="https://www.youtube.com/embed/r2-_XUOcurg" frameborder="0" gesture="media" allow="encrypted-media" allowfullscreen></iframe>

## Instructions to play
Your goal is to reach the end of the map by going all the way to the right.

For gameplay:
 - Left  			= "D"
 - Right 			= "A"
 - Slide 			= "S + A/D"
 - Jump  			= "Space"
 - Sprint			= "A/D + Left Shift"
 - Music Volume Up 		= "+"
 - Music Volume Down 		= "-"
 - Save  			= "F5"
 - Load				 = "F6"
 - Pause    = "P"
 - Select GUI buttons = "Shift"
 - Execute selected button = "Enter"

For Testing:
 - First Scene     		= "F1"
 - Start of Scene 		= "F2"
 - See Colliders 		= "F3"
 - Show Colliders GUI & Enemies Pathfinding			= "F8"
 - Save				= "F5"
 - Load				= "F6"
 - God Mode			= "F10"

We tried to implement slow motion in the game, but we ran out of time and so we couldn't adapt it to our mechanics.
You can test it pressing Q.

## License.
Licence: [Link](https://github.com/MaxitoSama/GDJM/blob/master/LICENSE.txt)

Tile Map: [Link](http://www.gameart2d.com/free-platformer-game-tileset.html)

Main Character:	[Link](http://www.gameart2d.com/ninja-adventure---free-sprites.html)

Background Music: [Link](https://www.youtube.com/watch?v=KCoqdCjzFV8)
