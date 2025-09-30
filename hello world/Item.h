#include <string>
//#include "Player.h"
#pragma once

class Player;

class Item {
protected:
    std::string name;
    std::string type;
    int amount;
public:
    Item(std::string name, std::string type);
    
    std::string GetName() const;
    virtual void UseItem(Player& player);
    std::string GetType() const;
    int GetAmount() const;
    void SetAmount(int amount);
    void SetName(std::string name);
    void SetType(std::string name);
    
};
