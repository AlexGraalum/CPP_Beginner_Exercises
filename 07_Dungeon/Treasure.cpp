#include "Treasure.h"

////Initialize Treasure
//Create new treasure position
Treasure::Treasure() {
     this->position = new int[2];
     this->position[0] = 0;
     this->position[1] = 0;
}

////Clear Treasure
//Delete the treasure position
Treasure::~Treasure() {
     delete this->position;
}

////Place Treasure
//Place treasure in a random position
void Treasure::PlaceTreasure(int width, int height, int* playerPos) {
     int x, y;
     do {
          x = rand() % width;
          y = rand() % height;
     } while (x == playerPos[0] && y == playerPos[1]);
     this->SetPosition(x, y);
}

////Set Position (Helper function)
//Set the treasure position
void Treasure::SetPosition(int x, int y) {
     this->position[0] = x;
     this->position[1] = y;
}

////Get Position (Helper Function)
//Get the treasure position
int* Treasure::GetPosition() {
     return this->position;
}