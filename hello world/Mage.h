#include "Entity.h"
#include "FireBall.h"
#pragma once

class Mage : public Entity {
private:
    int timer;
public:
    Mage();
    void MoveLeft(Map& map) override;
    void MoveRight(Map& map) override;
    void MoveUp(Map& map) override;
    void MoveDown(Map& map) override;
    void RandomAI(Map& map) override;
    void Attack(Map& map) override;
};


