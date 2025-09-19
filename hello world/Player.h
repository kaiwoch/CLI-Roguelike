#include "Map.h"
#include "Entity.h"
#pragma once

class Player : public Entity {
public:
    Player();

    void MoveLeft(Map& map) override;
    void MoveRight(Map& map) override;
    void MoveUp(Map& map) override;
    void MoveDown(Map& map) override;
    
    void Use(Map& map);
    void Attack(Map& map);
    void UseItem(unsigned int);
    void Heal(int healAmount);
};
