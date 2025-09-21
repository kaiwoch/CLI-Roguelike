#include "Map.h"
#include "Coordinates.h"
#include "Inventory.h"
#include <time.h>
#pragma once

class Entity {
protected:
    int max_hp;
    int hp;
    int damage;
    Coordinates pos;
    int walkSpeed;
    char symbol;
    Inventory inventory;
public:
    Entity();
    virtual void MoveLeft(Map& map);
    virtual void MoveRight(Map& map);
    virtual void MoveUp(Map& map);
    virtual void MoveDown(Map& map);
    virtual void PrintInventory();
    virtual void RandomAI(Map& map);
    virtual void Attack(Entity* entity, int damage);
    Coordinates GetPosition();
    int GetHP();
    virtual void TakeDamage(int damage);
    char GetSymbol();
    void SetPosition(Coordinates position);
    
    
    //костыль
    //bool EntityIsNear(Entity object);
    
};

