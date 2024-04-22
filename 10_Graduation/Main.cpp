//Includes
#include <iostream>
#include <conio.h>
#include <vector>
#include <time.h>

#include "BunnyList.h"

//Defines
#define START_BUN 5

//Functions
int main(int argc, char** argv) {
     srand(time(NULL));

     int year = 1;
     BunnyList* bunnies = new BunnyList(START_BUN);
     do{
          
          std::cout << "--Year: " << year << " || Population: " << bunnies->GetPopulation() << "--\n";
          bunnies->PrintBunnies();
          
          _getch();
          system("CLS");
          bunnies->AgeBunnies();
          bunnies->TurnBunnies();
          bunnies->BreedBunnies();
          if (bunnies->GetPopulation() > 1000) bunnies->CullBunnies();
          year++;
     } while (bunnies->BunniesExist());
     delete bunnies;

     return 0;
}