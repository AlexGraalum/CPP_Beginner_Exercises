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

     void SetPosition(int, int);
     int* GetPosition();

     void SetSymbol(wchar_t);
     wchar_t GetSymbol();
};
#endif