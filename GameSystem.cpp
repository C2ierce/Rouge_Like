#include "GameSystem.h"
#include <conio.h>

GameSystem::GameSystem()
{

}

GameSystem::GameSystem(std::string levelFile)
{
	level.load(levelFile);
	playGame();
}

GameSystem::~GameSystem()
{
}

void GameSystem::playGame()
{
	bool isPlaying = true;
	while (isPlaying != false)
	{
		level.render();
		level.movePlayer(_getch());
		level.updateEnemies();
		level.updateFOW();
		level.updatePlayerMap();
		level.updateEnemiesMap();
	}
}
