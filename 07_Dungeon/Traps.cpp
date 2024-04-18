#include "Traps.h"

////Initialize Traps
//Create a new array of trap positions
//Store trap count
Traps::Traps(int trapCount) {
     traps = new int*[trapCount];
     for (int i = 0; i < trapCount; i++) {
          traps[i] = new int[2];
     }

     this->trapCount = trapCount;
}

////Clear Traps
//Delete each trap
//Delete array of traps
Traps::~Traps() {
     for (int i = 0; i < this->trapCount; i++) {
          delete traps[i];
     }
     delete traps;
}

////Collision Check
//Check if the current position intersects with player
//Check if the current position intersects with treasure
//Check if the current position intersects with a trap
bool Traps::CollisionCheck(int x, int y, int i, int* playerPos, int* treasurePos) {
     if (x == playerPos[0] && y == playerPos[1]) return true;
     if (x == treasurePos[0] && y == treasurePos[1]) return true;

     if (i > 0) {
          for (int j = 0; j < i; j++) {
               if (x == traps[j][0] && y == traps[j][1]) return true;
          }
     }
     return false;
}

////Place Traps
//Randomly place traps
//Ensure traps do not collide
void Traps::PlaceTraps(int width, int height, int* playerPos, int* treasurePos) {
     for (int i = 0; i < trapCount; i++) {
          int x, y;
          do {
               x = rand() % width;
               y = rand() % height;  
               //std::wcout << "Attempting to place trap " << i << " at POS [" << x << ", " << "]\n";
          } while (CollisionCheck(x, y, i, playerPos, treasurePos));
          this->SetTrapPosition(x, y, i);
     }
}

////Set Trap Position (Helper Function)
//Set position of specific trap
void Traps::SetTrapPosition(int x, int y, int i) {
     this->traps[i][0] = x;
     this->traps[i][1] = y;
}

////Get Trap Position (Helper Function)
//Get position of specific trap
int* Traps::GetTrapPosition(int i) {
     return this->traps[i];
}

////Get Traps (Helper Function)
//Get the 2D array of traps
int** Traps::GetTraps() {
     return this->traps;
}

////Get Trap Count (Helper Function)
//Get the trap count
int Traps::GetTrapCount() {
     return this->trapCount;
}