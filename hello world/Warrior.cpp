#include "Warrior.h"

Warrior::Warrior() : Entity("Warrior") {
    MaxHPItem* RingOfLife = new MaxHPItem("ring of life", 150);
    HealItem* HealthPotion = new HealItem("health potion", 50);
    HealItem* Bread = new HealItem("bread", 10);
    DamageItem* HugeSword = new DamageItem("huge sword", 35);
    DamageItem* Stick = new DamageItem("stick", 25);
    
    std::vector<Item*> items = {RingOfLife, HealthPotion, Bread, HugeSword, Stick};
    int rand_size = rand() % items.size();
    for (unsigned int i = 0; i < rand_size; i++) {
        int rand_item = rand() % items.size();
        inventory.AddItem(items[rand_item]);
    }
    
    symbol = "W";
    max_hp = 100;
}

//Если передавать по значению, то игрок будет заспавнен в копии карты

void Warrior::MoveLeft(Map& map) {
    Entity::MoveLeft(map);
    map.SetElement(pos, symbol);
}

void Warrior::MoveRight(Map& map) {
    Entity::MoveRight(map);
    map.SetElement(pos, symbol);
}

void Warrior::MoveUp(Map& map) {
    Entity::MoveUp(map);
    map.SetElement(pos, symbol);
}

void Warrior::MoveDown(Map& map) {
    Entity::MoveDown(map);
    map.SetElement(pos, symbol);
}

void Warrior::RandomAI(Map& map) {
    Entity::RandomAI(map);
    srand(time(NULL));
    int direction = rand() % 4;
    
    switch (direction) {
        case 0:
            MoveRight(map);
            break;
        case 1:
            MoveUp(map);
            break;
        case 2:
            MoveLeft(map);
            break;
        case 3:
            MoveDown(map);
            break;
    }
}

std::string Warrior::getType() const {
    return Entity::getType();
}