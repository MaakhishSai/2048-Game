# 2048-Game

A simple implementation of the popular 2048 game in C++.

## Overview

This project is a console-based version of the 2048 game. The goal is to combine tiles with the same number to create larger numbers, ideally reaching the 2048 tile.

## Features

- 4x4 game board.
- Randomly generates new 2's at different positions.
- Supports movement in four directions: up, down, left, and right.
- Combines tiles and updates score.
- Tracks the number of moves and current score.
- Simple text-based user interface.

## Installation

1. Clone the repository:

   bash
   git clone https://github.com/MaakhishSai/2048-Game.git

2. Navigate to the project directory:
     cd 2048-Game
   
4. Compile the source code using a C++ compiler, such as g++:
    g++ -o 2048-Game 2048.cpp

5. Run the executable:
    ./2048-Game


#Usage
  When you run the game, you will see the game board printed on the console. The game       accepts the following commands:

. n: Start a new game
. u: Move tiles up
. d: Move tiles down
. l: Move tiles left
. r: Move tiles right
. e: Exit the game and display the total moves and score

# How to Play
 --> Use the command keys (u, d, l, r) to move the tiles in the desired direction.
  When two tiles with the same number collide, they merge into a single tile with their combined value.
 --> A new tile (with a value of 2) is added to the board after each move.
  The game continues until there are no valid moves left or you decide to exit.
  The goal is to create a tile with the number 2048.
