#pragma once
#ifndef TREASURE_H
#define TREASURE_H

#include <stdlib.h>

class Treasure {
private:
     int* position;
public:
     Treasure();
     ~Treasure();

     void PlaceTreasure(int, int, int*);

     void SetPosition(int, int);
     int* GetPosition();
};
#endif