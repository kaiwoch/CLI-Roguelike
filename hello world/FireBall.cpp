#include "FireBall.h"

FireBall::FireBall(Map& map) : Entity("FireBall") {
    damage = 10;
    symbol = "*";
    next_symbol = " ";
}

void FireBall::RandomAI(Map& map) {
    Entity::RandomAI(map);
    
    if (next_symbol != " ") {
        if (next_object != nullptr) {
            std::cout << next_object->GetSymbol() << std::endl;
            Damage(next_object, damage);
        }
        map.DeleteObject(this);
        return;
    }
    
    float dir = map.GetDirectionToPlayer(this); // в таком случае шар будет преследовать игрока
    
    
    int x = std::round(GetPosition().GetX() + walkSpeed * std::cos(dir));
    int y = std::round(GetPosition().GetY() - walkSpeed * std::sin(dir));
    
    Coordinates next_position;
    next_position.SetX(x);
    next_position.SetY(y);
    

    //map.SetElement(pos, next_symbol);
    next_object = map.GetObjectA(next_position);
    next_symbol = map.GetElement(next_position);
    if (next_symbol == " ") {
        map.SetElement(pos, next_symbol);
        pos = next_position;
        map.SetElement(pos, symbol);
    } else {
        map.SetElement(pos, " ");
    }
    
    
}

std::string FireBall::getType() const {
    return Entity::getType();
}
