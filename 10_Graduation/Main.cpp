//Includes
#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>
#include <string>

#include <io.h>
#include <fcntl.h>

#include <chrono>
#include <thread>

#include "BunnyList.h"
#include "Logger.h"
//#include "Grid.h"

//Defines
#define START_BUN 5
#define TURN_TIME_MS 2000
#define CASCADE_MUL 20.0
#define WIDTH 80
#define HEIGHT 80

//Prototypes
void InitSettings();

//Functions
int main(int argc, char** argv) {
     InitSettings();

     //char** grid = new char* [80];
     //for (int i = 0; i < 80; i++) {
     //     grid[i] = new char[80];
     //}
     //for (int y = 0; y < 80; y++) {
     //     for (int x = 0; x < 80; x++) {
     //          grid[x][y] = '*';
     //     }
     //}
     //
     //for (int y = 0; y < 80; y++) {
     //     for (int x = 0; x < 80; x++) {
     //          std::cout << grid[x][y];
     //          if (x < 79) std::cout << " ";
     //     }
     //     std::cout << std::endl;
     //}

     int year = 0;
     bool cull = false;
     std::string header;
     
     srand(time(NULL));
     Logger* logger = new Logger();
     logger->SetSpeedMul(3.0);

     BunnyList* bunnies = new BunnyList(START_BUN, logger);

     //Grid* grid = new Grid(WIDTH, HEIGHT, logger, bunnies);
     
     logger->AddToLog("");
     do{
          if (_kbhit()) {
               int c = _getch();
               if (c == 'k' || c == 'K')
                    cull = true;
          }
     
          auto start_time = std::chrono::high_resolution_clock::now();
     
          if (cull) {
               bunnies->CullBunnies();
          }
          else {
               if (year > 0) bunnies->AgeBunnies();
               if (bunnies->TurnBunnies())
                    logger->AddToLog("");
               if (bunnies->BreedBunnies())
                    logger->AddToLog("");
          }
     
          header = std::string("--Year: ").append(std::to_string(year)).append(" || Population: ");
          header.append(std::to_string(bunnies->GetPopulation())).append("--\n");
          logger->AddToLogFront(header);
          bunnies->PrintBunnies();
     
          auto total_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time).count();
     
          int time_limit = int(TURN_TIME_MS / logger->GetSpeedMul());
          if (total_time < time_limit)
               std::this_thread::sleep_for(std::chrono::milliseconds(time_limit - total_time));
     
          logger->LogOut();
          if ((logger->GetSpeedMul() < CASCADE_MUL) && bunnies->IsDeathCascade()) logger->SetSpeedMul(CASCADE_MUL);
     
          cull = false;
          year++;
     } while (bunnies->BunniesExist());
     
     logger->AddToLogFront(std::string("--Year: ").append(std::to_string(year)).append("--"));
     logger->AddToLog("The bunny population has been decemated.");
     logger->LogOut();
     
     delete bunnies;
     delete logger;

     return 0;
}

void InitSettings() {
     //_setmode(_fileno(stdout), _O_U16TEXT);
     CONSOLE_FONT_INFOEX cfi;
     HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
     cfi.cbSize = sizeof(cfi);
     cfi.dwFontSize.X = 0;
     cfi.dwFontSize.Y = 16;
     SetCurrentConsoleFontEx(handle, FALSE, &cfi);
     system("mode con COLS=700");
     ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
     SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}