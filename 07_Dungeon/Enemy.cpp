#include "Enemy.h"

void Enemy::MoveEntity(int dirX, int dirY) {
     SetPosition((GetPosition())[0] += dirX, (GetPosition())[1] += dirY);
}