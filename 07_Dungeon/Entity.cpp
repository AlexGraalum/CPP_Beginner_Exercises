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

bool Entity::CheckCollision(Entity* entity) {
     if (entity->GetPosition()[0] == this->position[0] &&
          entity->GetPosition()[1] == this->position[1]) return true;
     return false;
}
bool Entity::CheckCollision(int x, int y) {
     if (x == this->position[0] && y == this->position[1]) return true;
     return false;
}

////Set Position (Helper Function)
//Set the entity position
void Entity::SetPosition(int x, int y) {
     this->position[0] = x;
     this->position[1] = y;
}

////Get Position (Helper Function)
//Get the entity position
int* Entity::GetPosition() {
     return this->position;
}

////Set Symbol (Helper Function)
//Set the entity symbol
void Entity::SetSymbol(wchar_t symbol) {
     *(this->symbol) = symbol;
}

////Get Symbol (Helper Function)
//Get the entity symbol
wchar_t Entity::GetSymbol() {
     return *(this->symbol);
}