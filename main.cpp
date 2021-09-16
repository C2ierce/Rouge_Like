#include <Windows.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "GameSystem.h"

GameSystem *gameSystem;

int main()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 600, 900, true);

	gameSystem = new GameSystem("level1.txt");
	return  0;
}