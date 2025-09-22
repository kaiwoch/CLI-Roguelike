#include "Item.h"
#include <string>
#pragma once

class MaxHPItem : public Item {
private:
	int maxHPAmount;
public:
	MaxHPItem(std::string name, int maxHPAmount);
	void UseItem(Player& player) override;
};