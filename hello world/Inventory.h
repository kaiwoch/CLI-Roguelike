#include "Item.h"
#include <vector>
#include <iostream>
#pragma once

class Inventory {
private:
    std::vector<Item*> inventory;
public:
    void PrintInventory();
    void AddItem(Item* item);
};
