#include "Dungeon.h"

////Initialize Dungeon
//Create a new 2D array of wchar_t
//Populate 2D array with FLOOR, TREASURE, or TRAP
//Store dungeon size
Dungeon::Dungeon(int width, int height, int* treasurePos, Traps* traps) {
     dungeon = new wchar_t*[height];
     
     int** t = traps->GetTraps();

     for (int y = 0; y < height; y++) {
          dungeon[y] = new wchar_t[width];
     }

     for (int y = 0; y < height; y++) {
          for (int x = 0; x < width; x++) {
               dungeon[x][y] = FLOOR;

               if (x == treasurePos[0] && y == treasurePos[1]) dungeon[x][y] = TREASURE;
               for (int i = 0; i < traps->GetTrapCount(); i++) {
                    if (x == t[i][0] && y == t[i][1]) dungeon[x][y] = TRAP;
               }
          }
     }

     size = new int[2];
     size[0] = width;
     size[1] = height;
}

////Clear Dungeon
//Delete each row
//Delete dungeon
//Delete size
Dungeon::~Dungeon() {
     for (int y = 0; y < this->size[1]; y++) {
          delete dungeon[y];
     }
     delete dungeon;
     delete size;
}

////Print Dungeon
//Print Contents of dungeon
//Print border around dungeon
//Print Player at player position
void Dungeon::PrintDungeon(int* playerPos) {
     std::wcout << TL;
     for (int i = 0; i < size[0]; i++) std::wcout << H;
     std::wcout << TR << std::endl;

     for (int y = 0; y < size[1]; y++) {
          std::wcout << V;
          for (int x = 0; x < size[0]; x++) {
               if (x == playerPos[0] && y == playerPos[1]){
                  std::wcout << PLAYER;
               }
               else {
                  std::wcout << dungeon[x][y];
               }
          }
          std::wcout << V << std::endl;
     }

     std::wcout << BL;
     for (int i = 0; i < size[0]; i++) std::wcout << H;
     std::wcout << BR << std::endl;
}

////Get Size
//Get dungeon size
int* Dungeon::GetSize() {
     return this->size;
}