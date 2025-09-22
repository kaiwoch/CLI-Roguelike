#include "Map.h"
#include "Coordinates.h"
#include "Inventory.h"
#include <string>
#include <time.h>
#pragma once

class Entity {
protected:
    int max_hp;
    int hp;
    int damage;
    Coordinates pos;
    int walkSpeed;
    std::string symbol;
    Inventory inventory;
public:
    Entity();
    virtual void MoveLeft(Map& map);
    virtual void MoveRight(Map& map);
    virtual void MoveUp(Map& map);
    virtual void MoveDown(Map& map);
    virtual void PrintInventory();
    virtual void RandomAI(Map& map);
    virtual void Damage(Entity* entity, int damage);
    virtual void Attack(Map& map);
    virtual void TakeDamage(int damage);
    Coordinates GetPosition();
    int GetHP();
    int GetMaxHP();
    std::string GetSymbol();
    void SetPosition(Coordinates position);
    
    
    //костыль
    //bool EntityIsNear(Entity object);
    
};

