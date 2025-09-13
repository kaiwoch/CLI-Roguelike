#include "Map.h"
#include "Coordinates.h"
#include <time.h>
#pragma once

class Entity {
protected:
    Coordinates pos;
    int walkSpeed;
    char symbol;
public:
    Entity();
    virtual void SpawnEntity(Map& map);
    virtual void MoveLeft(Map& map);
    virtual void MoveRight(Map& map);
    virtual void MoveUp(Map& map);
    virtual void MoveDown(Map& map);
};

