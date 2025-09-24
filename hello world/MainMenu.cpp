#include "MainMenu.h"

MainMenu::MainMenu() {
	width = 40;
	height = 40;
	BuildMenu();
}

void MainMenu::BuildMenu() {
	std::vector<std::string> line;
	for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
        	if (x == 0 || y == 0 || x == height - 1 || y == height - 1) {
                line.push_back("#");
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
                menu[y][x] = "#";
            }
        }
    }

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
                menu[y][x] = "#";
            }
        }
    }
}

void MainMenu::Flush() {
	for (unsigned int y = 0; y < width; y++) {
        for (unsigned int x = 0; x < height; x++) {
            if (x == 0 || y == 0 || x == height - 1 || y == height - 1) {
                menu[y][x] = "#";
            } else {
            	menu[y][x] = " ";
            }
        }
    }
}