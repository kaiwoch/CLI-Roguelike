#include "Game.h"
#include "Player.h"
#include "Mage.h"
#include "Warrior.h"
#include "Chest.h"
#include <iostream>

Game::Game() {
    isRunning = true;
}

void Game::Run() {
    Player player;
    Mage mage_001;
    Warrior warrior_001;
    Chest chest_001;
    Chest chest_002;
    
    map.SpawnObject(&chest_001);
    map.SpawnObject(&chest_002);
    map.SpawnObject(&warrior_001);
    map.SpawnObject(&mage_001);
    map.SpawnObject(&player);
    
    while(isRunning) {
        std::cout << "Player pos:" << std::endl;
        std::cout << "X: " << player.GetPosition().GetX() << " | " << "Y: " << player.GetPosition().GetY() << " | HP: " << player.GetHP() << std::endl;
        char input;
        
        map.PrintMap();
        
        mage_001.RandomeAI(map);
        warrior_001.RandomeAI(map);
        
        std::cin >> input;
        switch (input) {
            case 'a':
                player.MoveLeft(map);
                break;
            case 'd':
                player.MoveRight(map);
                break;
            case 'w':
                player.MoveUp(map);
                break;
            case 's':
                player.MoveDown(map);
                break;
            case 'e':
                player.Use(map);
                break;
            case 'i':
                while(true) {
                    player.PrintInventory();
                    int choise = 0;
                    std::cin >> choise;
                    if (choise == 0) {
                        break;
                    }
                    player.UseItem(choise);
                }
                break;
            case 'x':
                player.Attack(map);
                break;
            default:
                break;
        }
        //isRunning = Stop();
    }
}

bool Game::Stop() {
    return false;
}
