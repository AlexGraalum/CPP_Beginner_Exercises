#include "Dungeon.h"

////Initialize Dungeon
//Store dungeon size
Dungeon::Dungeon(int width, int height) {
     size = new int[2];
     size[0] = width;
     size[1] = height;
}

////Clear Dungeon
//Delete size
Dungeon::~Dungeon() {
     delete size;
}

////Print Dungeon
//Print border around dungeon
//Print contents of dungeon
void Dungeon::PrintDungeon(std::vector<Entity*> entities) {
     system("CLS");
     std::wcout << TL;
     for (int i = 0; i < size[0]; i++) std::wcout << H;
     std::wcout << TR << std::endl;

     wchar_t tile;
     for (int y = 0; y < size[1]; y++) {
          std::wcout << V;
          for (int x = 0; x < size[0]; x++) {
               tile = FLOOR;
               for (int i = 0; i < entities.size(); i++) {
                    if (entities[i]->GetPosition()[0] == x && entities[i]->GetPosition()[1] == y) {
                         tile = entities[i]->GetSymbol();
                    }
               }
               std::wcout << tile;
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