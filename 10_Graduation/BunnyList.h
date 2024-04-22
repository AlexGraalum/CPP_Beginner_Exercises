#ifndef BUNNY_LIST_H
#define BUNNY_LIST_H

#include "Bunny.h"

struct Node {
     Bunny* bunny;
     Node* next;
};

class BunnyList {
private:
     Node* head;
     int pop;
public:
     BunnyList(int);
     ~BunnyList();

     void AddBunny(Bunny*);
     void KillBunny(Node**, Bunny*);

     void PrintBunnies();
     void AgeBunnies();
     void BreedBunnies();
     void TurnBunnies();
     void CullBunnies();

     bool BunniesExist();

     int GetPopulation() { return this->pop; }
};

#endif