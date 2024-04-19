#pragma once
#ifndef DUNGEON_H
#define DUNGEON_H

#include "Entity.h"

#include <iostream>
#include <vector>

#define H L'\x2550'
#define V L'\x2551'
#define TL L'\x2554'
#define TR L'\x2557'
#define BL L'\x255A'
#define BR L'\x255D'

#define FLOOR L'\x2592'
//#define PLAYER L'\x263A'
//#define TREASURE L'\x2663'
//#define TRAP L'\x203C'

class Dungeon {
private:
     wchar_t** dungeon;
     int* size;
public:
     Dungeon(int, int, std::vector<Entity*>*);
     ~Dungeon();

     void PrintDungeon(Entity*);

     int* GetSize();
};
#endif