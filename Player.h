#pragma once
#include "Entity.h"
#include "Space.h"
#include <random>
#include <ctime>
class Player : public Entity
{
public:
	Player();
	Player(std::string name, int level, int currentHealth, int maxHealth, int attack, int defense, int experience);
	~Player();

	int battle();
	int takeDamage(int attack);
	void addKey(void);
	void removeKey() { keys--; }
	void init(std::string name, int level, int currentHealth, int maxHealth, int attack, int defense, int experience, Space map);
	bool addExperience(int experience);

	//Setters
	void setPrevTile(char prevTile);
	
	//Getters
	std::string getName() { return name; }
	int getLevel() { return level; }
	int getCurrentHealth() { return currentHealth; }
	int getMaxHealth() { return maxHealth; }
	int getAttack() { return attack; }
	int getDefense() { return defense; }
	int getExperience() { return experience; }
	int getKeys() { return keys; }
	char getPrevTile(void) { return prevTile; }
	
private:
	int keys;
	int maxHealth;
	int currentHealth;
	int prevTileXPos;
	int prevTileYPos;
	void levelUp(void);
	char prevTile;
};

