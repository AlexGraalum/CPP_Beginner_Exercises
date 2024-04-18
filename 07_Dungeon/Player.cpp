#include "Player.h"

////Initialize Player
//Create new player position
Player::Player() {
     this->position = new int[2];
     this->position[0] = 0;
     this->position[1] = 0;
}

////Clear Player
//Delete the player position
Player::~Player() {
     delete this->position;
}

////Set Position (Helper function)
//Set the player position
void Player::SetPosition(int x, int y) {
     this->position[0] = x;
     this->position[1] = y;
}

////Get Position (Helper Function)
//Get the player position
int* Player::GetPosition() {
     return this->position;
}

////Move Player
//Adjust player position
void Player::MovePlayer(int dirX, int dirY) {
     SetPosition((GetPosition())[0] += dirX, (GetPosition())[1] += dirY);
}