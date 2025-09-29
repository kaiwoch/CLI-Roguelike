#include "ItemMaxHP.h"
#include "Player.h"

MaxHPItem::MaxHPItem(std::string name, int maxHPAmount) : Item(name, "MaxHP") {
	this->maxHPAmount = maxHPAmount;
}

void MaxHPItem::UseItem(Player& player) {
	player.SetMaxHP(maxHPAmount);
}