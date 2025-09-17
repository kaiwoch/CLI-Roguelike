#include <string>
//#include "Player.h"
#pragma once

class Player;

class Item {
protected:
    std::string name;
public:
    Item(std::string name);
    
    std::string GetName();
    virtual void UseItem(Player& player);
};
