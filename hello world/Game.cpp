#include "Game.h"
#include "Level.h"
#include "Player.h"
#include <iostream>

#ifdef _WIN32
    #include <conio.h>
#else
    #include <ncurses.h>
#endif

Game::Game() {
    isRunning = true;
    isDebug = false;
}

void Game::Run() {
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    
    isDebug = false;
    Level level;
    Player player;

    map = level.NextLevel(&player);
    
    while(isRunning) {
        clear();
        //system("clear");
        if (isDebug) {
            map.Debug();
        }
        Print("Player pos:\n");
        //printw("Player pos:\n");
        //std::cout << "Player pos:" << std::endl;
        printw("X: %d | Y: %d | HP: %d/%d\n", player.GetPosition().GetX(), player.GetPosition().GetY(), player.GetHP(), player.GetMaxHP());
        //std::cout << "X: " << player.GetPosition().GetX() << " | " << "Y: " << player.GetPosition().GetY() << " | HP: " << player.GetHP() << "/" << player.GetMaxHP() << std::endl;
        printw("# # # # # # # # # # # # # # # # # S T A G E : %d # # # # # # # # # # # # # # # #", level.GetStageNumber());
        //std::cout << "# # # # # # # # # # # # # # # # # S T A G E : " << level.GetStageNumber() <<" # # # # # # # # # # # # # # # #" << std::endl;
        //char input;
    
        
        map.PrintMap();
        refresh();
        int key = GetInput();
        
        //std::cin >> input;
        switch (key) {
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
                    int choise = GetInput();
                    //std::cout << choise << std::endl;
                    if (choise == 'i') {
                        break;
                    }
                    player.UseItem(choise - 48);
                }
                break;
            case 'x':
                player.Attack(map);
                break;
            default:
                break;
        }
        //isRunning = Stop();
        refresh();
    }
}

bool Game::Stop() {
    return false;
}

int Game::GetInput() {
#ifdef _WIN32
    return _getch();
#else
    return getch();
#endif
}

void Game::Print(const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    
#ifdef _WIN32
    vprintf(fmt, args);
#else
    vw_printw(stdscr, fmt, args);
#endif
    
    va_end(args);
}
