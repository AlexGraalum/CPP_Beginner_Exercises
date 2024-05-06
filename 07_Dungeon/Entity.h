#pragma once
#ifndef ENTITY_H
#define ENTITY_H

class Entity {
private:
     int* position;
     wchar_t* symbol;
public:
     Entity(wchar_t);
     ~Entity();

     virtual void MoveEntity(int, int);

     bool CheckCollision(Entity*);
     bool CheckCollision(int, int);

     void SetPosition(int x, int y) {
          this->position[0] = x;
          this->position[1] = y;
     }
     int* GetPosition() { return this->position; }

     void SetSymbol(wchar_t symbol) { *(this->symbol) = symbol; }
     wchar_t GetSymbol() { return *(this->symbol); }
};
#endif