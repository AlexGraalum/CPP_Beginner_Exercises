# GRADUATION

Requires:

- Variables, Data Types, Numerical Operators

- Basic Input/Output

- Logic (If Statements, Switch Statements)

- Loops (For, While, Do-While)

- Arrays

- Pseudo Random Number Generation

- Strings & String Functions

- Functions

- Structures/Classes

- Enumerated Data

- File Input/Output

- Pointers

- Sorting

- Linked Lists

- Advanced Classes

---

- [ ] Write a program that creates a linked list of bunny objects.


Each bunny object must have

- Sex: Male or Female (50/50 at creation)

- Color: White, Brown, Black, Spotted

- Age: 0-10 (years)

- Name: Randomly chosen at creation from a list of bunny names

- Radioactive Mutant Vampire Bunny: True/False (2% chance at creation)


At program initialization, 5 bunnies must be created and given random colors.


Each turn afterward:

- The bunnies age 1 year

- For each male age 2 or older, and each female age 2 or older, a new bunny is created\
(New bunnies should have the same color as their mother)

- If a bunny becomes older than 10, it dies.

- Radioactive Mutant Vampire Bunnies turn exactly one regular bunny.

- The program should print a list of all the bunnies in the colony with all details, sorted by age.

- The program should also print all events of the turn\
i.e.\
"Baby Thumper was born!\
Bunny Fufu was born!\
Radioactive Mutant Vampire Bunny Darth Maul was born!\
Bunny Julius Caesar died!"

Rules:

- The program should write all screen output to a file

- Radioactive Mutant Vampire Bunnies cannot breed

- Radioactive Mutant Vampire bunnies live to the age of 50

- If the population exceeds 1000 a food shortage must occur, randomly killing half of the population

- When all bunnies have died, the program ends


- [ ] **X** Modify the program to run in real time, each turn lasting 2 seconds and 1 second pause between annoncements

- [ ] **X X** Allow the user to press the 'K' key to initiate a mass rabbit cull, randomly killing half the population

- [ ] **X X X X** Modify the program to place the rabbits in an 80x80 grid. Have the rabbits randomly move one space per turn\
Mark juvenile males as m and adult males as M\
Mark juvenile females as f and adult females as F\
Mark Radioactive Mutant Vampire Bunnies as X\
Modify the program so that Radioactive Mutant Vampire Bunnies can only convert bunnies that end on an adjacent space\
Modify the program so that new bunnies are born in an empty adjacent space next to the mother (no empty space means no bunny is born)


- [ ] **X X X X X** Modify the program so that it saves each turn to a file and can play back all turns at accelerated speed.