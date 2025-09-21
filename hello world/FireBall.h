#include "Entity.h"

#pragma once

class FireBall : public Entity {
private:
    char next_symbol;
    Entity* next_object;
public:
    FireBall(Map& map);
    
    void RandomAI(Map& map) override;
    
};
