//Includes
#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>
#include <string>

//#include <chrono>
//#include <thread>

#include "BunnyList.h"
#include "Logger.h"

//Defines
#define START_BUN 5
#define TURN_TIME_MS 2000
#define CASCADE_MUL 10.0

//Functions
int main(int argc, char** argv) {
     int year = 0;
     std::string header;

     srand(time(NULL));
     Logger* logger = new Logger();
     BunnyList* bunnies = new BunnyList(START_BUN, logger);

     logger->AddToLog("");
     do{
          auto start_time = std::chrono::high_resolution_clock::now();
          if (year > 0) bunnies->AgeBunnies();
          if (bunnies->TurnBunnies())
               logger->AddToLog("");
          if (bunnies->BreedBunnies())
               logger->AddToLog("");

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

          year++;
     } while (bunnies->BunniesExist());

     logger->AddToLogFront(std::string("--Year: ").append(std::to_string(year)).append("--"));
     logger->AddToLog("The bunny population has been decemated.");
     logger->LogOut();

     delete bunnies;
     delete logger;

     return 0;
}