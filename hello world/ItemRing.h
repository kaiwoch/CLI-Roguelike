#include "Item.h"
#include <string>
#pragma once

class Ring : public Item {
private:
	int healAmount;
public:
	Ring(std::string name, int healAmount);
	void UseItem(Player& player) override;
};