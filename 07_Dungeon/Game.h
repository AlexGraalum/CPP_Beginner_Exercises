#pragma once
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#include "Player.h"
#include "Treasure.h"
#include "Traps.h"
#include "Dungeon.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_SPC 32

//#define DEBUG

class Game {
private:
     Player* player;
     Treasure* treasure;
     Traps* traps;
     Dungeon* dungeon;

     bool endState;
public:
     Game(int, int, int);
     ~Game();

     void Tick();
     void GetKeyInput(int);
     bool WinOrLose();

     void SetEndState(bool);
     bool GetEndState();

#ifdef DEBUG
     void PrintDebug();
#endif
};
#endif