#include "Entity.h"

Entity::Entity(std::string name, int level, int health, int attack, int defense, int experience)
{
	this->name = name;
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->experience = experience;
	this->setTileVisibility(this->xPos, this->yPos, true);
	//this->tile = space2D[this->xPos][this->yPos].getTile(this->xPos, this->yPos);
}

Entity::Entity()
{

}

Entity::~Entity()
{

}


void Entity::init(std::string name, int level, int health, int attack, int defense, int experience)
{
	this->name = name;
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->experience = experience;
}

void Entity::setPosition(int xPos, int yPos)
{
	this->xPos = xPos;
	this->yPos = yPos;
}

int Entity::getXPos(void)
{
	return xPos;
}

int Entity::getYPos(void)
{
	return yPos;
}

std::string Entity::getName(void)
{
	return name;
}

void Entity::setMap(Space map)
{
	this->map = map;
}

int Entity::getXMapPos()
{
	for (int row = 0; row < map.getSizeX(); row++)
	{
		for (int column = 0; column < map.getSizeY(row); column++)
		{
			char tile;

			tile = map.getTile(row, column);

			if (tile == map.tiles.player)
			{
				return row;
			}
		}
	}
}

char Entity::getTileFromMapAtCoords(int xPos, int yPos)
{
	return this->map.getTile(xPos, yPos);
}

