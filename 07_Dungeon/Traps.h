#pragma once
#ifndef TRAPS_H
#define TRAPS_H

#include <iostream>
#include <stdlib.h>

#include "Player.h"
#include "Treasure.h"

class Traps {
private:
     int** traps;
     int trapCount;

     bool CollisionCheck(int, int, int, int*, int*);
public:
     Traps(int);
     ~Traps();

     void PlaceTraps(int, int, int*, int*);

     void SetTrapPosition(int, int, int);
     int* GetTrapPosition(int);

     int** GetTraps();
     int GetTrapCount();
};
#endif