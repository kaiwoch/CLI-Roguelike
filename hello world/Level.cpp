#include "Level.h"

Level::Level() {
	num_stage = 0;
}

Map Level::NextLevel(Player* player) {
	num_stage++;
	map = Map();
    Door* door = new Door;
    map.SpawnObject(door);
	map.SpawnObject(player);
    
    int count_enemies = 1 + rand() % 5;
    for (int i = 0; i < count_enemies; i++) {
    	int enemy_type = rand() % 2;
    	switch (enemy_type) {
    	case 0: {
    		// Обратить внимание, что если создать просто объект, а потом передать его адрес, то объект сотрется из памяти и адрес будет указывать на пустое пространство
    		Warrior* warrior = new Warrior;
    		map.SpawnObject(warrior);
    		}
    		break;
    	case 1: {
    		Mage* mage = new Mage;
    		map.SpawnObject(mage);
    		}
    	break;
    	}
    }

    int count_chests = 1 + rand() % 3;
    for (int i = 0; i < count_chests; i++) {
    	Chest* chest = new Chest;
    	map.SpawnObject(chest);
    }


    return map; 
}

int Level::GetStageNumber() {
	return num_stage;
}

Map Level::GetCurrentMap() {
    return map;
}
