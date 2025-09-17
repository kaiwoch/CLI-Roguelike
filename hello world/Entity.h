#include "Map.h"
#include "Coordinates.h"
#include "Inventory.h"
#include <time.h>
#pragma once

class Entity {
protected:
    Coordinates pos;
    int walkSpeed;
    char symbol;
    Inventory inventory;
public:
    Entity();
    virtual void SpawnEntity(Map& map);
    virtual void MoveLeft(Map& map);
    virtual void MoveRight(Map& map);
    virtual void MoveUp(Map& map);
    virtual void MoveDown(Map& map);
    virtual void PrintInventory();
    Coordinates GetPosition();
    
    
    //костыль
    //bool EntityIsNear(Entity object);
    
};

