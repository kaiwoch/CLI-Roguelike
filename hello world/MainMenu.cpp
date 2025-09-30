#include "MainMenu.h"

MainMenu::MainMenu() {
    symbol = "*";
	width = 40;
	height = 40;
	BuildMenu();
}

void MainMenu::BuildMenu() {
	std::vector<std::string> line;
	for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
        	if (x == 0 || y == 0 || x == height - 1 || y == height - 1) {
                line.push_back(symbol);
            } else {
            	line.push_back(" ");
            }
        }
        menu.push_back(line);
        line = {};
    }

	for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            if (x == 0 || y == 0 || x == height - 1 || y == height - 1) {
                menu[y][x] = symbol;
            }
        }
    }
    
    PrintText();

}

void MainMenu::PrintMenu() {
	for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            std::string s = menu[y][x];
            cf.Print("%s ", s.c_str());
        }
        cf.Print("\n");
    }
}

void MainMenu::PrintButton(int amount) {
	int b_height = 18;
	int b_width = 6;

	int start_y = (amount) - (b_width / 2);
	int start_x = (height / 2) - (b_height / 2);

	for (unsigned int y = start_y; y < start_y + b_width; y++) {
        for (unsigned int x = start_x; x < start_x + b_height; x++) {
            if (x == start_x || y == start_y || x == start_x + b_height - 1 || y == start_y + b_width - 1) {
                menu[y][x] = symbol;
            }
        }
    }
}

void MainMenu::PrintText() {
    std::vector<std::string> text = {"LOAD", "SAVE", "EXIT"};
    
    for (unsigned int i = 0; i < text.size(); i++) {
        int start_y = (i + 1) * 10;
        int start_x = (height / 2) - (text[i].size() / 2);
        
        for (unsigned int j = 0; j < text[i].size(); j++) {
            menu[start_y][start_x + j] = text[i][j];
        }
    }
}

void MainMenu::Flush() {
	for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            if (x == 0 || y == 0 || x == height - 1 || y == height - 1) {
                menu[y][x] = symbol;
            } else {
                if (menu[y][x] == symbol) {
                    menu[y][x] = " ";
                }
            }
        }
    }
}
