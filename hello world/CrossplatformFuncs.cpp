#include "CrossplatformFuncs.h"

#ifdef _WIN32
    #include <cstdarg>
    #include <conio.h>
	#include <iostream>
	#include <windows.h>
#else
    #include <ncurses.h>
#endif

int CrossplatformFuns::GetInput() {
#ifdef _WIN32
    return _getch();
#else
    return getch();
#endif
}

void CrossplatformFuns::SetColor(std::string s) {
	#ifdef _WIN32
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        if (s == "P") {
            SetConsoleTextAttribute(hConsole, WindowsColors::White);
            Print("%s ", s.c_str());
            SetConsoleTextAttribute(hConsole, WindowsColors::White);
        } else if (s == "*" || s == "=") {
            SetConsoleTextAttribute(hConsole, WindowsColors::Red);
            Print("%s ", s.c_str());
            SetConsoleTextAttribute(hConsole, WindowsColors::White);
        } else if (s == "#") {
            SetConsoleTextAttribute(hConsole, WindowsColors::Green);
            Print("%s ", s.c_str());
            SetConsoleTextAttribute(hConsole, WindowsColors::White);
        } else if (s == "M" || s == "W") {
            SetConsoleTextAttribute(hConsole, WindowsColors::Yellow);
            Print("%s ", s.c_str());
            SetConsoleTextAttribute(hConsole, WindowsColors::White);
        } else {
            SetConsoleTextAttribute(hConsole, WindowsColors::Blue);
            Print("%s ", s.c_str());
            SetConsoleTextAttribute(hConsole, WindowsColors::White);
        }
    #else
        if (s == "P") {
            attron(COLOR_PAIR(1));
            printw("%s ", s.c_str());
            attroff(COLOR_PAIR(1));
        } else if (s == "*" || s == "=") {
            attron(COLOR_PAIR(2));
            printw("%s ", s.c_str());
            attroff(COLOR_PAIR(2));
        } else if (s == "#") {
            attron(COLOR_PAIR(3));
            printw("%s ", s.c_str());
            attroff(COLOR_PAIR(3));
        } else if (s == "M" || s == "W") {
            attron(COLOR_PAIR(5));
            printw("%s ", s.c_str());
            attroff(COLOR_PAIR(3));
        } else {
            attron(COLOR_PAIR(4));
            printw("%s ", s.c_str());
            attroff(COLOR_PAIR(4));
        }
    #endif
}

void CrossplatformFuns::Print(const char *fmt, ...) {
	va_list args;
    va_start(args, fmt);
    
#ifdef _WIN32
    vprintf(fmt, args);
#else
    vw_printw(stdscr, fmt, args);
#endif
    
    va_end(args);
}

void CrossplatformFuns::ClearScreen() {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;

    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, ' ', cellCount, {0, 0}, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, {0, 0}, &count);
    SetConsoleCursorPosition(hConsole, {0, 0});
#endif
}
