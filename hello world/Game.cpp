#include "Game.h"
#include "Level.h"
#include "Player.h"
#include <iostream>

Game::Game() {
    isRunning = true;
}

void Game::Run() {
    Level level;
    Player player;

    map = level.NextLevel(&player);
    
    while(isRunning) {
        system("clear");
        std::cout << "Player pos:" << std::endl;
        std::cout << "X: " << player.GetPosition().GetX() << " | " << "Y: " << player.GetPosition().GetY() << " | HP: " << player.GetHP() << std::endl;
        char input;
        
        map.PrintMap();
        
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
                {
                    bool isDoor = player.Use(map);
                    if (isDoor) {
                        map = level.NextLevel(&player);
                    }
                }
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
            case 'l':
                map.Debug();
            default:
                break;
        }
        //isRunning = Stop();
    }
}

bool Game::Stop() {
    return false;
}
