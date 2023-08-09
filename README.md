# breno_project
 Admission Project for Mindera
# Project for Mindera
## By: Breno Mancini

## Overview
The project is a first-person survival game set in a labyrinth surrounded by enemies that move when they are out of sight. They hide in the shadows, waiting to ambush the player. Players gain points for every second survived.

## Controls Instructions
- Use WASD to move in different directions.
- Use the mouse to control rotation and view.
- Press '1' to switch to character 1.
- Press '2' to switch to character 2.

## Data Structure
The entire structure is designed for quick adjustments without requiring code changes. They can be adjsuted on Data tables set under the folder "DATA".

## Tables
- Characters Table;
- Enemies Table;
- Configuration Table: Game's general settings, customizable for difficulty levels.

## Game Components
### Player
The player can move left, right, forward, and backward, and rotate the view in all directions. The player can choose from two character types.
- **Character 1:**
  - Blue color
  - Speed: 400
  - Field of View (FOV): 90

- **Character 2:**
  - Purple color
  - Speed: 1000
  - FOV: 60

### Enemies
Enemies stay still when in the player's field of view. Contact with the player defeats them and ends the game.
They can be easily created. A few examples:
- **Enemy Type 0:** Active from the game's start. Patrols to find the player.
  - Speed: 600 cm/s
- **Enemy Type 1:** Active from the game's start. Moves toward the player upon game start.
  - Speed: 800 cm/s
- **Enemy Type 2:** Active only when it spots the player. Remains stationary if not activated.
  - Speed: 1000 cm/s

## Mechanics
Detecting whether an enemy is within the player's field of view involves using mathematical logic to ensure versatility and avoid reliance on the engine's collision or traces. A dot product calculation determines if the player is looking in the direction of the enemy. If the sum of the angle difference between the player's field of view (which can vary in-game) and the player's viewing angle is less than 0 (perpendicular to the enemy), it ensures functionality across all axes without dependency on collision or traces.

Three situations arise:
1. The player isn't looking at the enemy.
2. The player is looking at the enemy.
3. The player looks toward the enemy but doesn't see it due to an obstruction.

Each situation is addressed using a behavior tree and enemy behavior.

### Enemy Behavior
- **Patrol:** Simple patrolling using a basic EQS (Environment Query System) to avoid collisions.
- **Out of Player's View:** Triggers a hunting behavior to seek out the player.
- **In Player's Field of View, but Not Seen:** Indicates an obstruction, likely a wall, in the way.
  - **Ambush Behavior:** Utilizing EQS, the enemy finds the best nearby hiding spot and waits for an ambush.
  - This can be turned off.
