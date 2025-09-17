#include "Entity.h"
#pragma once

class Mage : public Entity {
public:
    Mage(Map& map);
    void SpawnEntity(Map& map) override;
    void MoveLeft(Map& map) override;
    void MoveRight(Map& map) override;
    void MoveUp(Map& map) override;
    void MoveDown(Map& map) override;
    void RandomeAI(Map& map);
};


