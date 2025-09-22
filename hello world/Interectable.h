#include "Coordinates.h"
#include <time.h>
#include <iostream>
#include <string>
#include "Inventory.h"
#pragma once

class Interectable {
protected:
    Coordinates pos;
    std::string symbol;
    bool isDoor;
public:
    Interectable();
    virtual void Open(Inventory& object_inventory);
    virtual void PrintInventory();
    Coordinates GetPosition();
    std::string GetSymbol();
    void SetPosition(Coordinates position);
    void SetIsOpened(bool isOpened);
    bool GetIsDoor();
    
    virtual ~Interectable() = default;
};
