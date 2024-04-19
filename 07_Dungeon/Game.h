#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "Entity.h"
#include "Player.h"
#include "Treasure.h"
#include "Trap.h"
#include "Enemy.h"
#include "Dungeon.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_SPC 32

#define PLAYER L'\x263A'
#define TREASURE L'\x2663'
#define TRAP L'\x203C'
#define ENEMY L'\x263B'

class Game {
private:
     std::vector<Entity*>* entities;

     Dungeon* dungeon;

     bool endState;
public:
     Game(int, int, int, int);
     ~Game();

     void PlaceEntities(int, int);

     void Tick();
     bool WinOrLose();
     void GetKeyInput(int);
     void MoveEnemies();

     void SetEndState(bool);
     bool GetEndState();
};
#endif