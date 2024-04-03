# DUNGEON CRAWL

Requires:

- Variables, Data Types, Numerical Operators

- Basic Input/Output

- Logic (If Statements, Switch Statements)

- Arrays

---

- [ ] Make a program that outputs a simple grid based gameboard to the screen using either numbers or characters.\
i.e\
\
. . . . . . . . . .\
. G . . . . . . . .\
. . . . . . T . . .\
. . . . . . . . . .\
. . . . T . . . . .\
. . . . . . T . . .\
. . . . . . . . . X\
\
or\
\
0 0 0 0 0 0 0 0 0 0\
0 5 0 0 6 0 0 0 0 0\
0 0 0 0 0 0 7 0 0 0\
0 0 0 0 0 0 0 0 0 0\
0 0 0 7 0 0 0 0 0 0\
0 0 0 0 0 0 7 0 0 0\
0 0 0 0 0 0 0 0 0 4\
\
Allow the user (Marked G or 5 in the examples) to move either up, down, left, or right each turn.\
If the player steps on a trap (Marked T or 7, they lose.\
If they make it to the treasure (Marked X or 4), they win.

- [ ] **X X** Add enemies that move randomly in any direction oncer per turn.\
(enemies, just like traps, cause the player to lose the game)

*HINT*: Don't let the player move off the gameboard! Your program will crash if they move off the top, bottom, left, or right of the board! (The same holds true for enemies)