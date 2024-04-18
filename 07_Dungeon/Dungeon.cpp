//Includes
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <io.h>
#include <fcntl.h>
#include <cwchar>
#include <windows.h>

//Defines
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_SPC 32

#define H L'\x2550'
#define V L'\x2551'
#define TL L'\x2554'
#define TR L'\x2557'
#define BL L'\x255A'
#define BR L'\x255D'

#define FLOOR L'\x2592'
#define PLAYER L'\x263A'
#define TREASURE L'\x2663'
#define TRAP L'\x203C'

#define width 10
#define height 10
#define trapCount 4

//Globals
wchar_t** dungeon;
int* player;
int* treasure;
int** traps;

//Prototypes
void initSettings();

int* initPlayer();
void clearPlayer();

int* initTreasure();
void clearTreasure();

int** initTraps();
void placeTraps();
void clearTraps();

wchar_t** initDungeon();
void clearDungeon();

void getKeyInput(int c);
bool noCollision(int x, int y, int i);
void printDungeon();
void movePlayer(int dirX, int dirY);

bool winOrLose();

//Functions
int main(int argc, char** argv) {
     srand(time(NULL));
     
     initSettings();

     player = initPlayer();
     treasure = initTreasure();
     traps = initTraps();
     placeTraps();
     dungeon = initDungeon();

     while (1) {
          system("CLS");

          printDungeon();
          if (winOrLose()) break;

          int c = _getch();
          if (c == KEY_ESC) break;
          getKeyInput(c);
     }

     clearTraps();
     clearTreasure();
     clearDungeon();
     
     return 0;
}

////Initialize Settings
//Change stdout for UTF-16 support
//Change console font size
void initSettings() {
     _setmode(_fileno(stdout), _O_U16TEXT);
     CONSOLE_FONT_INFOEX cfi;
     cfi.cbSize = sizeof(cfi);
     cfi.dwFontSize.X = 0;
     cfi.dwFontSize.Y = 24;
     SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

////Initialize Player
//Create new player position
//Randomly place the player
int* initPlayer() {
     int* player = new int[2];

     player[0] = rand() % width;
     player[1] = rand() % height;

     return player;
}

////Clear Player
//Delete the player
void clearPlayer() {
     delete player;
}

////Initialize Treasure
//Create new treasure position
//Randomly place treasure
//Ensure treasure does not colllide
int* initTreasure() {
     int* treasurePos = new int[2];
     int x = 0, y = 0;

     do {
          x = rand() % width;
          y = rand() % height;
     } while (x == player[0] && y == player[1]);

     treasurePos[0] = x;
     treasurePos[1] = y;

     return treasurePos;
}

////Clear Treasure
//Delete the treasure
void clearTreasure() {
     delete treasure;
}

////Initialize Traps
//Create a new array of trap positions
int** initTraps() {
     int** traps = new int* [trapCount];

     for (int i = 0; i < trapCount; i++) {
          traps[i] = new int[2];
     }

     return traps;
}

////Place Traps
//Randomly place traps
//Ensure traps do not collide
void placeTraps() {
     for (int i = 0; i < trapCount; i++) {
          int x, y;
          do {
               x = rand() % width;
               y = rand() % height;

          } while (!noCollision(x, y, i));

          traps[i][0] = x;
          traps[i][1] = y;
     }
}

////Clear Traps
//Delete each trap
//Delete array of traps
void clearTraps() {
     for (int i = 0; i < trapCount; i++) {
          delete traps[i];
     }
     delete traps;
}

////Initialize Dungeon
//Create new 2D array of unicode characters
//Place Floor, Trap, and Treasure characters
wchar_t** initDungeon() {
     wchar_t** dungeon = new wchar_t* [height];

     for (int y = 0; y < height; y++) {
          dungeon[y] = new wchar_t[width];
     }

     for (int y = 0; y < height; y++) {
          for (int x = 0; x < width; x++) {
               dungeon[x][y] = FLOOR;

               if (treasure[0] == x && treasure[1] == y) dungeon[x][y] = TREASURE;

               for (int i = 0; i < trapCount; i++) {
                    if (traps[i][0] == x && traps[i][1] == y) dungeon[x][y] = TRAP;
               }
          }
     }

     return dungeon;
}

////Clear Dungeon
//Delete the dungeon
void clearDungeon() {
     for (int y = 0; y < height; y++) {
          delete dungeon[y];
     }
     delete dungeon;
}

////No Collision
//Check if the current position intersects with player
//Check if the current position intersects with treasure
//Check if the current position intersects with a trap
bool noCollision(int x, int y, int i) {
     if ((x == player[0]) && (y == player[1])) return false;
     if ((x == treasure[0]) && (y == treasure[1])) return false;

     if (i > 0) {
          for (int j = 0; j < i; j++) {
               if ((x == traps[j][0]) && (y == traps[j][1])) return false;
          }
     }
     return true;
}

////Get User Input
//Use _getch for key values
//Check for arrow key code to avoid double input
void getKeyInput(int c) {
     if (c == 224) {
          c = _getch();
          switch (c) {
          case KEY_UP:
               movePlayer(0, -1);
               break;
          case KEY_DOWN:
               movePlayer(0, 1);
               break;
          case KEY_LEFT:
               movePlayer(-1, 0);
               break;
          case KEY_RIGHT:
               movePlayer(1, 0);
               break;
          default:
               break;
          }
     }
}

////Print Dungeon
//Print contents of dungeon
//Print border around dungeon
//Print player at player position
void printDungeon() {
     std::wcout << TL;
     for (int i = 0; i < width; i++) std::wcout << H;
     std::wcout << TR << std::endl;

     for (int y = 0; y < height; y++) {
          std::wcout << V;
          for (int x = 0; x < width; x++) {

               if (player[0] == x && player[1] == y) {
                    std::wcout << PLAYER;
               }
               else {
                    std::wcout << dungeon[x][y];
               }
          }
          std::wcout << V << std::endl;
     }
     std::wcout << BL;
     for (int i = 0; i < width; i++) std::wcout << H;
     std::wcout << BR << std::endl;
}

////Move Player
//Move the player position
//Constrain player position within dungeon bounds
void movePlayer(int dirX, int dirY) {
     if ((dirX < 0) && (player[0] > 0)) player[0] += dirX;
     if ((dirX > 0) && (player[0] < (width - 1))) player[0] += dirX;
     if ((dirY < 0) && (player[1] > 0)) player[1] += dirY;
     if ((dirY > 0) && (player[1] < (height - 1))) player[1] += dirY;
}

////Win Or Lose
//Check if the player intersects a trap or the treasure
bool winOrLose() {
     if (player[0] == treasure[0] && player[1] == treasure[1]) {
          std::wcout << "You found the treasure!\nGood Job!!\n\n";
          return true;
     }
     for (int i = 0; i < trapCount; i++) {
          if (player[0] == traps[i][0] && player[1] == traps[i][1]) {
               std::wcout << "A trap got you!\nThat's not good...\n\n";
               return true;
          }
     }
     return false;
}