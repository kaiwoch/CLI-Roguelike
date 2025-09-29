#include "Coordinates.h"
#include <time.h>
#include <iostream>
#include <string>
#include "Inventory.h"
#pragma once

class Interectable {
protected:
    Inventory inventory;
    Coordinates pos;
    std::string symbol;
    std::string type;
    bool isDoor;
public:
    Interectable(std::string type);
    virtual void Open(Inventory& object_inventory);
    virtual void PrintInventory();
    std::string GetType() const;
    Coordinates GetPosition() const;
    std::string GetSymbol();
    void SetPosition(Coordinates position);
    void SetIsOpened(bool isOpened);
    bool GetIsDoor();
    Inventory GetInventory() const;

    friend void to_json(json& j, const Interectable& i);
    friend void from_json(const json& j, Interectable& i);
    
    virtual ~Interectable() = default;
};
