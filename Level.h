#pragma once
#include <vector>
#include <list>
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "DialogueBox.h"
#include "Space.h"
#include "ChatBox.h"

class Level
{
public:
	Level();
	~Level();

	void load(std::string fileName);
	void render();
	void movePlayer(char input);
	void updateEnemies();
	void updateFOW();
	void updatePlayerMap();
	void updateEnemiesMap();

	//Getters
	char getTile(int row, int column);
	
	//Setters
	void setTile(int row, int column, char tile);

	Space map;
private:
	Player player;
	std::vector <Enemy> enemies;
	std::string levelName;
	std::string strMap = "";
	std::string strMapFlip = "";
	DialogueBox dialogueBox;
	ChatBox chatBox;
	void processPlayerMove(int newRowPos, int newColumnPos, std::string direction);
	void processEnemyMove(int enemyIndex, int targetXPos, int targetYPos);
	void battleEnemy(int targetX, int targetY);
	void battlePlayer(int targetX, int targetY);
	void gameOver();
};

