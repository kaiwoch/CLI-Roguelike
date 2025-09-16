#include "Map.h"
#include "Entity.h"
#pragma once

class Player : public Entity {
public:
    Player(Map& map);
    void SpawnEntity(Map& map) override;
    void MoveLeft(Map& map) override;
    void MoveRight(Map& map) override;
    void MoveUp(Map& map) override;
    void MoveDown(Map& map) override;
    
    void Use(Map& map);
};
