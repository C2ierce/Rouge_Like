#pragma once
#include <iostream>
#include "Level.h"

class GameSystem
{
public:
	GameSystem();
	GameSystem(std::string gameLevelFile);
	~GameSystem();

	void playGame();
private:
	Level level;
};

