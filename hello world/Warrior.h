#include "Entity.h"
#pragma once

class Warrior : public Entity {
public:
    Warrior();
    
    void MoveLeft(Map& map) override;
    void MoveRight(Map& map) override;
    void MoveUp(Map& map) override;
    void MoveDown(Map& map) override;
    void RandomAI(Map& map) override;
    std::string getType() const override;
    void Attack(Map& map) override;
};
