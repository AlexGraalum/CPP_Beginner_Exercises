#include "Entity.h"

////Initialize Entity
//Create new entity position
Entity::Entity(wchar_t symbol) {
     this->position = new int[2];
     this->position[0] = 0;
     this->position[1] = 0;

     this->symbol = new wchar_t(symbol);
}

///Clear Entity
//Delete the entity position
Entity::~Entity() {
     delete this->position;
     delete this->symbol;
}

void Entity::MoveEntity(int dirX, int dirY) {
     SetPosition((GetPosition())[0] += dirX, (GetPosition())[1] += dirY);
}

bool Entity::CheckCollision(Entity* entity) {
     if ((entity->GetPosition()[0] == this->position[0]) &&
          (entity->GetPosition()[1] == this->position[1])) return true;
     return false;
}
bool Entity::CheckCollision(int x, int y) {
     if ((x == this->position[0]) && (y == this->position[1])) return true;
     return false;
}