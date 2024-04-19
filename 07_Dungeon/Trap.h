#pragma once
#ifndef TRAP_H
#define TRAP_H

#include "Entity.h"

class Trap : public Entity {
public:
     Trap(wchar_t c) : Entity(c) {}
};
#endif