#include "Level.h"
#include <iostream>
#include <fstream>
Level::Level()
{
}

Level::~Level()
{
}

void Level::load(std::string levelName)
{
	this->levelName = levelName;

	

	//Load the level

	std::ifstream file;
	file.open(levelName);
	if (file.fail())
	{
		perror(levelName.c_str());
		system("PAUSE");
		exit(1);
	}

	/*
	#####
	#@  #
	#####
	*/

	std::string line;
	std::vector<std::string> lineA;
	int amountMapRows = 0;

	while (std::getline(file, line))
	{
		lineA.push_back(line);
		amountMapRows++;
	}

	int amountMapColumns = lineA[0].size();

	int row = amountMapRows;
	int column = amountMapColumns;
	int sizeCount = 0;

	map.resize(row);
	for (auto& i : map.map)
	{
		i.resize(lineA[sizeCount].size());
		sizeCount++;
	}

	for (int i = 0; i < row; i++)
	{
		for (int x = 0; x < lineA[i].size(); x++)
		{
			std::string mapChar = lineA[i];
			map.setTile(i, x, mapChar[x]);
		}
	}
	file.close();
	//initalise player
	player.init("Cierce", 1, 20, 20, 10, 5, 30, map);
	//Process the level
	char tile;

	for (int row = 0; row < map.getSizeX(); row++)
	{
		for (int column = 0; column < map.getSizeY(row); column++)
		{
			tile = map.getTile(row, column);
			
			if (tile == map.tiles.player)
			{
				player.setPosition(row, column);
				map.setTile(row, column, map.tiles.player);
			}
			else if (tile == map.tiles.enemy)
			{

			}
			else if (tile == map.tiles.goblin)
			{
				enemies.push_back(Enemy("Goblin", map.tiles.goblin, 1, 1, 1, 2, 37)); //name, tile, level, health, attack, defense, experience
				enemies.back().setPosition(row, column);
				map.setTile(row, column, map.tiles.goblin);
			}
			else if (tile == map.tiles.snake)
			{
				enemies.push_back(Enemy("Snake", map.tiles.snake, 1, 6, 1, 1, 12)); //name, tile, level, health, attack, defense, experience
				enemies.back().setPosition(row, column);
				map.setTile(row, column, map.tiles.snake);
			}
			else if (tile == map.tiles.wall)
			{
				map.setTile(row, column, map.tiles.wall, false);
			}
			else if (tile == map.tiles.floor)
			{
				map.setTile(row, column, map.tiles.floor, false);
			}
			else if (tile == map.tiles.lockDoorOne)
			{

			}
			else if (tile == map.tiles.key)
			{

			}
			else if (tile == map.tiles.item)
			{

			}
		}
	}
	updateFOW();
}

void Level::render()
{
	system("cls");
	std::cout << map.getMap();

	//Stats
	std::cout << "|-------------------|" << std::endl;
	std::cout << "|---" << player.getName() << "-Stats----|" << std::endl;
	std::cout << "|-------------------|" << std::endl;
	std::cout << "|Level: " << player.getLevel() << "           |" << std::endl;
	std::cout << "|HP: " << player.getCurrentHealth() << "/" << player.getMaxHealth() << "          |" << std::endl;
	std::cout << "|Attack: " << player.getAttack() << "          |" << std::endl;
	std::cout << "|Defense: " << player.getDefense() << "         |" << std::endl;
	std::cout << "|EXP: " << player.getExperience() << "             |" << std::endl;
	std::cout << "|Keys: " << player.getKeys() << "            |" << std::endl;
	std::cout << "|Position X: " << player.getXPos() << " Y: " << player.getYPos() << " |" << std::endl;
	std::cout << "|-------------------|" << std::endl;

	//In-Game Dialogue
	std::cout << "|--------------------------------|" << std::endl;
	std::cout << "|-------DT-Game Dialogue!--------|" << std::endl;
	std::cout << "|-------DONT-SHIT-THE-BED--------|" << std::endl; //34 lines long 
	std::cout << "|--------------------------------|" << std::endl;
	std::cout << chatBox.getDialogue();
	std::cout << "|--------------------------------|" << std::endl;
	//std::cout << "|" << map.getTileVisibility(player.getXPos(), player.getYPos()) << "                               |" << std::endl;
	std::cout << "|" << player.getTileFromMapAtCoords(player.getXPos(), player.getYPos()+2) << "                               |" << std::endl;
	std::cout << "|--------------------------------|" << std::endl;
}

void Level::movePlayer(char input)
{
	int plrXPos = player.getXPos();
	int plrYPos = player.getYPos();

	switch (input)
	{
	case 'w': //UP
	case 'W':
		processPlayerMove(plrXPos - 1, plrYPos, "North");
		break;
	case 's': //DOWN
	case 'S':
		processPlayerMove(plrXPos + 1, plrYPos, "South");
		break;
	case 'd': //RIGHT
	case 'D':
		processPlayerMove(plrXPos, plrYPos + 1, "East");
		break;
	case 'a': //LEFT
	case 'A':
		processPlayerMove(plrXPos, plrYPos - 1, "West");
		break;
	}
}

char Level::getTile(int row, int column)
{
	return map.getTile(row, column);
}

void Level::setTile(int row, int column, char tile)
{
	
	map.setTile(row, column, tile);
}

void Level::processPlayerMove(int targetXPos, int targetYPos, std::string direction)
{
	int plrXPos = player.getXPos();
	int plrYPos = player.getYPos();
	char moveToTile = getTile(targetXPos, targetYPos);
	
	if (moveToTile == map.tiles.player)
	{

	}
	else if (moveToTile == map.tiles.enemy)
	{

	}
	else if (moveToTile == map.tiles.wall)
	{
		chatBox.addDialogue("You run into a wall. James, wtf! That was pretty dumb.  Ayy lamo, u ok? "); 
	}
	else if (moveToTile == map.tiles.floor)
	{
		if (direction == "North") {
			chatBox.addDialogue("You move, North.");
		}
		else if (direction == "East") {
			chatBox.addDialogue("You move, East.");
		}
		else if (direction == "South") {
			chatBox.addDialogue("You move, South");
		}
		else if (direction == "West") {
			chatBox.addDialogue("You move, West.");
		}

		player.setPosition(targetXPos, targetYPos);
		
		if (player.getPrevTile() == map.tiles.openDoor)
		{
			player.setPrevTile(map.tiles.floor);
			setTile(plrXPos, plrYPos, map.tiles.openDoor);
		}
		else
		{
			setTile(plrXPos, plrYPos, map.tiles.floor);
		}

		setTile(targetXPos, targetYPos, map.tiles.player);
	}
	else if (moveToTile == map.tiles.openDoor)
	{
		player.setPrevTile(map.tiles.openDoor);
		chatBox.addDialogue("You walk through a door.");
		player.setPosition(targetXPos, targetYPos);
		setTile(plrXPos, plrYPos, map.tiles.floor);
		setTile(targetXPos, targetYPos, map.tiles.player);
	}
	else if (moveToTile == map.tiles.lockDoorOne || moveToTile == map.tiles.lockDoorTwo)
	{
		if (moveToTile == map.tiles.lockDoorOne && player.getKeys() == 0 || moveToTile == map.tiles.lockDoorTwo && player.getKeys() == 0)
		{
			chatBox.addDialogue("It's a locked door.");
		}
		else if (moveToTile == map.tiles.lockDoorOne && player.getKeys() >= 1 || moveToTile == map.tiles.lockDoorTwo && player.getKeys() >= 1)
		{
			std::string unlockDoor = "";

			do {
				chatBox.addDialogue("Unlock the door? (y/n)");
				render();
				std::cout << "Enter key (press ENTER to EXIT):";
				std::getline(std::cin, unlockDoor);
				
				if (unlockDoor[0] == 'y')
				{
					player.removeKey();
					chatBox.addDialogue("You unlock the door! " + std::to_string(player.getKeys()) + " key(s) left.");
					setTile(targetXPos, targetYPos, map.tiles.openDoor);
					return;
				}
				else if (unlockDoor[0] == 'n')
				{
					chatBox.addDialogue("You save your key for later.");
					return;
				}
			} while (unlockDoor.length() != 0);

			chatBox.addDialogue("You save your key for later.");
			return;
		}
	}
	else if (moveToTile == map.tiles.key)
	{
		chatBox.addDialogue("You picked up a rusty key.");
		player.addKey();
		setTile(targetXPos, targetYPos, map.tiles.floor);
	}
	else if (moveToTile == map.tiles.item)
	{

	}
	else
	{
		battleEnemy(targetXPos, targetYPos);
	}
}

void Level::battleEnemy(int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int attackRoll;
	int attackResult;

	for (int i = 0; i < enemies.size(); i++)
	{
		enemyX = enemies[i].getXPos();
		enemyY = enemies[i].getYPos();

		if (targetX == enemyX && targetY == enemyY)
		{
			//do battle
			attackRoll = player.battle();
			attackResult = enemies[i].takeDamage(attackRoll);
			chatBox.addDialogue("You hit " + enemies[i].getName() + " for " + std::to_string(attackResult) + ".");

			if (enemies[i].getHealth() <= 0)
			{
				chatBox.addDialogue(enemies[i].getName() + " died. You recieved " + std::to_string(enemies[i].getExperience()) + " experience.");

				if (player.addExperience(enemies[i].getExperience()))
				{
					chatBox.addDialogue("You leveled up!");
				}

				enemies[i] = enemies.back(); //gets the last element in the vector
				enemies.pop_back(); //remove last element from vector
				i--; //process vector in same space of enemy again (so we don't skip an enemy)
				setTile(targetX, targetY, map.tiles.floor);
				return;
			}
			return;
		}
	}
}

void Level::updateEnemies()
{
	std::string aiMove;
	int plrXPos = player.getXPos();
	int plrYpos = player.getYPos();
	int eneXPos;
	int eneYPos;

	for (int enemyIndex = 0; enemyIndex < enemies.size(); enemyIndex++)
	{
		aiMove = enemies[enemyIndex].moveTo(plrXPos, plrYpos);
		int eneXPos = enemies[enemyIndex].getXPos();
		int eneYPos = enemies[enemyIndex].getYPos();
		
		enemies[enemyIndex].setMap(this->map); //updates the enemy maps moved from own function due to time taken to complete 

		switch (aiMove[0])
		{
		case 'w': //UP
			processEnemyMove(enemyIndex, eneXPos - 1, eneYPos);
			break;
		case 's': //DOWN
			processEnemyMove(enemyIndex, eneXPos + 1, eneYPos);
			break;
		case 'a': //LEFT
			processEnemyMove(enemyIndex, eneXPos, eneYPos - 1);
			break;
		case 'd': //RIGHT
			processEnemyMove(enemyIndex, eneXPos, eneYPos + 1);
			break;
		}
	}
}

void Level::processEnemyMove(int enemyIndex, int targetXPos, int targetYPos)
{
	int plrXPos = player.getXPos();
	int plrYPos = player.getYPos();
	int eneXPos = enemies[enemyIndex].getXPos();
	int eneYPos = enemies[enemyIndex].getYPos();

	char moveToTile = getTile(targetXPos, targetYPos);

	if (moveToTile == map.tiles.player)
	{
		battlePlayer(eneXPos, eneYPos);
	}
	else if (moveToTile == map.tiles.enemy)
	{

	}
	else if (moveToTile == map.tiles.wall)
	{

	}
	else if (moveToTile == map.tiles.floor)
	{
		enemies[enemyIndex].setPosition(targetXPos, targetYPos);
		if (enemies[enemyIndex].getPrevTile() == map.tiles.openDoor)
		{
			enemies[enemyIndex].setPrevTile(map.tiles.floor);
			setTile(eneXPos, eneYPos, map.tiles.openDoor);
		}
		else
		{
			setTile(eneXPos, eneYPos, map.tiles.floor);
		}
		setTile(targetXPos, targetYPos, enemies[enemyIndex].getTile());
	}
	else if (moveToTile == map.tiles.openDoor)
	{
		enemies[enemyIndex].setPrevTile(map.tiles.openDoor);
		enemies[enemyIndex].setPosition(targetXPos, targetYPos);
		setTile(eneXPos, eneYPos, map.tiles.floor);
		setTile(targetXPos, targetYPos, enemies[enemyIndex].getTile()); //BUGGED CODE? NANI
	}
	else
	{
		
	}
}

void Level::updateFOW()
{
	char tile;
	for (int row = 0; row < map.getSizeX(); row++)
	{
		for (int column = 0; column < map.getSizeY(row); column++)
		{
			tile = map.getTile(row, column);

			if (tile == map.tiles.player)
			{
				map.setPlayerView(row, column);
			}
			else if(tile == map.tiles.snake)
			{
				map.setTileVisibility(row, column, true);
			}
			else if(tile == map.tiles.goblin)
			{
				map.setTileVisibility(row, column, true);
			}
			else 
			{
				if (!(map.getHasBeenExplored(row, column)))
				{
					map.setTileVisibility(row, column, false);
				}
			}
		}
	}
}

void Level::updatePlayerMap()
{
	player.setMap(this->map);
}

void Level::updateEnemiesMap()
{
	for (int row = 0; row < enemies.size(); row++)
	{
		enemies[row].setMap(this->map);
	}
}

void Level::battlePlayer(int targetX, int targetY)
{
	int enemyX;
	int enemyY;
	int attackRoll;
	int attackResult;

	for (int i = 0; i < enemies.size(); i++)
	{
		enemyX = enemies[i].getXPos();
		enemyY = enemies[i].getYPos();

		if (targetX == enemyX && targetY == enemyY)
		{
			attackRoll = enemies[i].battle();
			player.takeDamage(attackRoll);
			//dialogueBox.addDialogue(enemies[i].getName() + " hit " + player.getName() + " for " + std::to_string(attackResult) + ".");
			int plrHP = player.getCurrentHealth();
			if (player.getCurrentHealth() <= 0)
			{
				chatBox.addDialogue(player.getName() + " was killed by " + enemies[i].getName() + ".");
				setTile(player.getXPos(), player.getYPos(), map.tiles.floor);
				render();
				system("PAUSE");
				gameOver();
				return;
			}
			return;
		}
	}
}

void Level::gameOver()
{
	system("CLS");

	char playAgain;
	std::cout << "Would you like to play again? (y/n) ";
	std::cin >> playAgain;

	if (playAgain == 'y')
	{
		enemies.clear();
		chatBox.resetDialogue();
		load(levelName);
	}
	else if (playAgain == 'n')
	{
		std::cout << "Thank-you for playing Rogue_Like beta 0.1!" << std::endl;
		system("PAUSE");
		exit(0);
	}
	else
	{
		return gameOver();
	}
}