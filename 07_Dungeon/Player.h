#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player: public Entity {
public:
     Player(wchar_t c) : Entity(c) {}
};
#endif