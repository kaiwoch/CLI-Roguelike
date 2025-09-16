#include <string>
#pragma once

class Item {
protected:
    std::string name;
public:
    Item(std::string name);
    
    std::string GetName();
};
