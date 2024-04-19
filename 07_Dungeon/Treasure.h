#pragma once
#ifndef TREASURE_H
#define TREASURE_H

#include "Entity.h"

class Treasure: public Entity {
public:
     Treasure(wchar_t c) : Entity(c) {}
};
#endif