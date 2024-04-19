//Includes
#include <io.h>
#include <fcntl.h>
#include <windows.h>

#include "Game.h"

//Define
#define WIDTH 10
#define HEIGHT 10
#define TRAPCOUNT 16
#define ENEMYCOUNT 4

//Prototypes
void initSettings();

//Functions
int main(int argc, char** argv) {
     initSettings();

     Game* game = new Game(WIDTH, HEIGHT, TRAPCOUNT, ENEMYCOUNT);
     do{
        game->Tick();
     }while(!game->GetEndState());
     
     delete game;
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