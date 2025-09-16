#include "Item.h"

Item::Item(std::string name) {
    this->name = name;
}

std::string Item::GetName() {
    return name;
}
