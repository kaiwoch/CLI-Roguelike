#include "Entity.h"

#pragma once

class FireBall : public Entity {
private:
    std::string next_symbol;
    Entity* next_object;
public:
    FireBall(Map& map);
    
    void RandomAI(Map& map) override;
    std::string getType() const override;

};
