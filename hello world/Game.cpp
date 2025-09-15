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
    Chest chest(map);
    
    while(isRunning) {
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
                
            default:
                break;
        }
        //isRunning = Stop();
    }
}

bool Game::Stop() {
    return false;
}
