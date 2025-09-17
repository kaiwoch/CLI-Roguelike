#include "ItemRing.h"
#include "Player.h"

Ring::Ring(std::string name, int healAmount) : Item(name) {
	this->healAmount = healAmount;
}

void Ring::UseItem(Player& player) {
	player.Heal(healAmount);
}