#include "Entity.h"
#pragma once

class Warrior : public Entity {
public:
    Warrior();
    
    void MoveLeft(Map& map) override;
    void MoveRight(Map& map) override;
    void MoveUp(Map& map) override;
    void MoveDown(Map& map) override;
    void RandomeAI(Map& map);
};
