#include "Map.h"
#include "Player.h"
#include "Mage.h"
#include "Warrior.h"
#include "Chest.h"
#include "Door.h"
#pragma once

class Level {
private:
	int num_stage;
	Map map;
public:
	Level();
	Map NextLevel(Player* player);
    Map GetCurrentMap();
    void SetMap(Map map);
	int GetStageNumber();
    void SetStageNumber(int num_stage);
};

