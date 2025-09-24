#include "Item.h"
#include <vector>
#include <iostream>
#include "CrossplatformFuncs.h"
#pragma once

class Inventory {
private:
    std::vector<Item*> inventory;
    CrossplatformFuns cf;
public:
    void PrintInventory();
    void AddItem(Item* item);
    void RemoveItem(Item* item);
    std::vector<Item*> GetInventory();
    Item* ChoiseItem(unsigned int index);
};
