#pragma once
#include <iostream>
#include "Space.h"

class Entity : public Space
{
public:
	Entity();
	Entity(std::string name, int level, int health, int attack, int defense, int experience);
	~Entity();

	void init(std::string name, int level, int health, int attack, int  defense, int experience);

	//Setters
	void setPosition(int x, int y);
	void setMap(Space map);

	//Getters
	int getXPos(void);
	int getYPos(void);
	int getXMapPos();
	char getTileFromMapAtCoords(int xPos, int yPos);

	std::string getName(void);
	Space map;
protected:
	//Attributes
	std::string name;
	int level;
	int health;
	int attack;
	int defense;
	int experience;

	//Position
	int xPos;
	int yPos;
};

