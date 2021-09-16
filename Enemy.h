#pragma once
#include "Entity.h"
#include "Space.h"
#include <random>
#include <ctime>
class Enemy : public Entity
{
public:
	Enemy();
	Enemy(std::string name, char tile, int level, int health, int attack, int defense, int experience);
	~Enemy();
	

	int battle();
	int takeDamage(int attack);
	char prevTile;

	//Getters
	char getTile() { return tile; }
	char getPrevTile(void) { return prevTile; }
	int getHealth() { return health; }
	int getExperience() { return experience; }

	//Setters
	void setPrevTile(char tile);

	//AI Movement
	std::string moveTo(int playerXPos, int playerYPos);
};

