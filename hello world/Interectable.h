#include "Coordinates.h"
#include <time.h>
#include <iostream>
#pragma once

class Interectable {
protected:
    Coordinates pos;
    char symbol;
    bool isOpened;
public:
    Interectable();
    virtual void Open();
    virtual void PrintInventory();
    Coordinates GetPosition();
    char GetSymbol();
    void SetPosition(Coordinates position);
    
    virtual ~Interectable() = default;
};
