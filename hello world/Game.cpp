#include "Game.h"
#include "Player.h"
#include "Mage.h"
#include <iostream>

Game::Game() {
    isRunning = true;
}

void Game::Run() {
    Player player(map);
    Mage mage(map);
    
    while(isRunning) {
        char input;
        
        map.PrintMap();
        
        mage.RandomeAI(map);
        
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
            default:
                break;
        }
        //isRunning = Stop();
    }
}

bool Game::Stop() {
    return false;
}
