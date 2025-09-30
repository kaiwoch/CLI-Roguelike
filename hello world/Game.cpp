#include "Game.h"
#include "Level.h"
#include "Player.h"
#include "MainMenu.h"
#include <iostream>
#include "SaveSystem.h"

#ifdef _WIN32
    #include <cstdarg>
    #include <conio.h>
#else
    #include <ncurses.h>
#endif

Game::Game() {
    isRunning = true;
    isDebug = false;
}

void Game::Run() {
    // это должно быть в первую очередь!
    #ifdef _WIN32

    #else
        initscr();
        noecho();
        curs_set(0);
        keypad(stdscr, TRUE);
    #endif
    SaveSystem save;
    MainMenu menu;
    isDebug = true;
    Level level;
    Player player;

    map = level.NextLevel(&player);
    
    while(isRunning) {
        if (!player.IsAlive()) {
            break;
        }
        //это для кнопки
        int tmp = 10;
        #ifdef _WIN32
            system("cls");
        #else
            clear();
        #endif
        if (isDebug) {
            map.Debug();
        }

        cf.Print("# # # # # # # # # # # # # # # # # S T A G E : %d # # # # # # # # # # # # # # # #\n", level.GetStageNumber());
    
        map.PrintMap();
        PrintEntityHPBar(player);

        auto object = map.GetNearstEntityObject(player.GetPosition());
        if (object != nullptr) {
            PrintEntityHPBar(*object);
        }
        #ifdef _WIN32

        #else
            refresh();
        #endif
        int key = cf.GetInput();
        
        switch (key) {
            case 27:
                while(isRunning) {
                    #ifdef _WIN32
                        system("cls");
                    #else
                        clear();
                    #endif
                    cf.Print("\n");
                    
                    menu.Flush();
                    menu.PrintButton(tmp);
                    menu.PrintMenu();

                    int choise = cf.GetInput();

                    if (choise == 27) {
                        break;
                    } 
                    if (choise == 's' && tmp < 30) {
                        tmp+=10;
                    } else if (choise == 'w' && tmp > 10) {
                        tmp -= 10;
                    }
                    if (choise == 10 || choise == 13) {
                        switch (tmp) {
                            case 10:
                                break;
                            case 20:
                                save.TestFunc(level);
                                break;
                            case 30:
                                isRunning = Stop();
                                break;
                                
                            default:
                                break;
                        }
                    }
                    
                }
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
                    int choise = cf.GetInput();
                    if (choise == 'i') {
                        break;
                    }
                    player.UseItem(choise - 48);
                }
                break;
            case 'x':
                player.Attack(map);
                break;
            case 'l':
                level = save.Load();
                map = level.GetCurrentMap();
                Entity* loaded_player = map.GetPlayer();
                if (loaded_player != nullptr) {
                    //TODO: Не доделал
                }
                
            default:
                cf.Print("%d", key);
                break;
        }
        //isRunning = Stop();
        //refresh(); ===
    }
}

bool Game::Stop() {
    return false;
}

void Game::PrintEntityHPBar(Entity& object) {
    if (object.GetSymbol() == "*") {
        return;
    }
    int procent = int(float(object.GetHP()) / float(object.GetMaxHP()) * 100) / 10;
    cf.Print("%s %s ", object.GetSymbol().c_str() , "HP: [");
    for (int i = 0; i < procent; i++) {
        cf.SetColor("=");
    }
    for (int i = 0; i < 10 - procent; i++) {
        cf.SetColor(" ");
    }
    cf.Print("%s %d/%d     ", "]", object.GetHP(), object.GetMaxHP());
}
