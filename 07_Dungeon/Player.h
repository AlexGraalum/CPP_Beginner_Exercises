#pragma once
#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
     int* position;
public:
     Player();
     ~Player();

     void SetPosition(int, int);
     int* GetPosition();

     void MovePlayer(int, int);
};
#endif