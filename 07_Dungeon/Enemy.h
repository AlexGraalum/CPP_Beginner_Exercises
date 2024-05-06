#pragma once
#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy: public Entity {
public:
     Enemy(wchar_t c) : Entity(c) {}
};
#endif