#pragma once
#ifndef BUNNY_LIST_H
#define BUNNY_LIST_H

#include "Bunny.h"
#include "Logger.h"
#include <vector>

#define POPULATION_LIMIT 1000
//#define DEBUG

struct Node {
     Bunny* bunny;
     Node* next;
     ~Node() {
          delete bunny;
     }
};

class BunnyList {
private:
     Node* head;
     int pop;
     size_t nameBuffer;

     Logger* logger;

     void CullBunnies();
public:
     BunnyList(int, Logger*);
     ~BunnyList();

     void AddBunny(Bunny*);
     void KillBunny(Node**, Bunny*);

     void PrintBunnies();
     void AgeBunnies();
     bool BreedBunnies();
     bool TurnBunnies();

     bool BunniesExist();
     bool IsDeathCascade();

     int GetPopulation() { return this->pop; }
};

#endif