#include "Coordinates.h"
#include <time.h>
#include <iostream>
#include "Inventory.h"
#pragma once

class Interectable {
protected:
    Coordinates pos;
    char symbol;
    bool isOpened;
public:
    Interectable();
    virtual void Open(Inventory& object_inventory);
    virtual void PrintInventory();
    Coordinates GetPosition();
    char GetSymbol();
    void SetPosition(Coordinates position);
    
    virtual ~Interectable() = default;
};
