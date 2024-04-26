//Includes
#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>
#include <string>

#include <chrono>
#include <thread>

#include "BunnyList.h"
#include "Logger.h"

//Defines
#define START_BUN 5

//Functions
int main(int argc, char** argv) {
     srand(time(NULL));

     int year = 0;
     Logger* logger = new Logger("testFile.txt");
     std::string header;
     BunnyList* bunnies = new BunnyList(START_BUN, logger);
     logger->AddToLog("");
     
     do{
          if (bunnies->TurnBunnies())
               logger->AddToLog("");
          if (bunnies->BreedBunnies())
               logger->AddToLog("");

          header = std::string("--Year: ").append(std::to_string(year)).append(" || Population: ");
          header.append(std::to_string(bunnies->GetPopulation())).append("--\n");
          logger->AddToLogFront(header);

          bunnies->PrintBunnies();
          logger->LogOut();

          _getch();
          system("CLS");

          bunnies->AgeBunnies();
          year++;

          //logger->LogOut();
     } while (bunnies->BunniesExist());

     logger->AddToLogFront(std::string("--Year: ").append(std::to_string(year)).append(" || Population: ").append(std::to_string(bunnies->GetPopulation())));
     logger->AddToLog("The bunny population has been decemated.");
     logger->LogOut();

     delete bunnies;
     delete logger;

     return 0;
}