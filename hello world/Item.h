#include <string>
//#include "Player.h"
#pragma once

class Player;

class Item {
protected:
    std::string name;
    std::string type;
public:
    Item(std::string name, std::string type);
    
    std::string GetName() const;
    virtual void UseItem(Player& player);
    std::string GetType() const;
};
