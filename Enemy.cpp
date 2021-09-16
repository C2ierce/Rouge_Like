#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

Enemy::Enemy(std::string name, char tile, int level, int health, int attack, int defense, int experience)
{
	this->name = name;
	this->tile = tile;
	this->level = level;
	this->health = health;
	this->attack = attack;
	this->defense = defense;
	this->experience = experience;
}

int Enemy::battle()
{
	std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackRoll(0, this->attack);
	return attackRoll(randomEngine);
}

int Enemy::takeDamage(int attack)
{
	attack -= defense;
	if (attack > 0)
	{
		health -= attack;
		return attack;
	}
	else if (attack <= 0)
	{
		return 0;
	}
	return 0;
}

void Enemy::setPrevTile(char tile)
{
	prevTile = tile;
}

std::string Enemy::moveTo(int playerXPos, int playerYPos)
{
	int distance;
	int dx = this->xPos - playerXPos; //difference in x
	int dy = this->yPos - playerYPos; //in y
	int adx = abs(dx); //absolute x
	int ady = abs(dy); //abs y

	distance = adx + ady;
	//std::cout << "Distance: " << distance << std::endl;
	if (distance <= 5)
	{
		//std::cout << "dif x: " << dx << " dif y: " << dy << " abs dif x: " << adx << " abs dif y: " << ady << std::endl;
		//system("pause");
		if (adx > ady) //if absolute difference x is less than y
		{
			if (dx > 0) //if difference in y is > 0 move the enemy up
			{
				return "w";
			} 
			else if(dx < 0)
			{
				return "s";
			}
		} 
		else 
		{
			if (dy > 0) //if difference in x is > 0 move the enemy left
			{
				return "a";
			} 
			else if(dy < 0)
			{
				return "d";
			}
		}
	}
	//Random movement
	std::default_random_engine randEngine(time(NULL));
	std::uniform_int_distribution<int> moveRoll(0, 3);
	int randMove = moveRoll(randEngine);
	switch (randMove)
	{
		case 0:
			return "w";
		case 1:
			return "a";
		case 2:
			return "s";
		case 3: 
			return "d";
		default:
			return ".";
	}
}
