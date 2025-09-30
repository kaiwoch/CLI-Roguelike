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
    
    bool Use(Map& map);
    void Attack(Map& map);
    void UseItem(unsigned int);
    void Heal(int healAmount);
    void SetMaxHP(int amount);
    void TakeDamage(int damage) override;
    bool IsAlive();
    std::string getType() const override;
};
