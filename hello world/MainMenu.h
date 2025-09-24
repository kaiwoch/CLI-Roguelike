#include <vector>
#include <string>
#include "CrossplatformFuncs.h"
#pragma once

class MainMenu {
private:
	int width;
    int height;
	std::vector<std::vector<std::string>> menu;
	CrossplatformFuns cf;
public:
	void BuildMenu();
	MainMenu();
	void PrintMenu();
	void PrintButton(int amount);
	void Flush();
};