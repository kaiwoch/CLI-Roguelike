#include "Item.h"
#include <string>
#pragma once

class MaxHPItem : public Item {
public:
	MaxHPItem(std::string name, int amount);
	void UseItem(Player& player) override;
};
