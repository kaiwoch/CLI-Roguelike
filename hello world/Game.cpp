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
    Player player(map);
    Mage mage(map);
    Warrior warrior(map);
    Chest chest_001;
    Chest chest_002;
    map.SpawnObject(&chest_001);
    map.SpawnObject(&chest_002);
    
    while(isRunning) {
        std::cout << "Player pos:" << std::endl;
        std::cout << "X: " << player.GetPosition().GetX() << " | " << "Y: " << player.GetPosition().GetY() << std::endl;
        char input;
        
        map.PrintMap();
        
        mage.RandomeAI(map);
        warrior.RandomeAI(map);
        
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
            default:
                break;
        }
        //isRunning = Stop();
    }
}

bool Game::Stop() {
    return false;
}
