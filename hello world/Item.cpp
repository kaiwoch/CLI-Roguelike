#include "Item.h"

Item::Item(std::string name, std::string type) {
    this->type = type;
    this->name = name;
}

std::string Item::GetName() const{
    return name;
}

void Item::UseItem(Player& player) {

}

std::string Item::GetType() const{
    return type;
}

void Item::SetName(std::string name) {
    this->name = name;
}

int Item::GetAmount() const {
    return amount;
}

void Item::SetAmount(int amount) {
    this->amount = amount;
}
