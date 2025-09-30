#include "ItemMaxHP.h"
#include "Player.h"

MaxHPItem::MaxHPItem(std::string name, int amount) : Item(name, "MaxHP") {
	this->amount = amount;
}

void MaxHPItem::UseItem(Player& player) {
	player.SetMaxHP(amount);
}
