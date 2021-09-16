#include "Player.h"

Player::Player()
{
	//tiles.player = 'P';
}

Player::Player(std::string name, int level, int currentHealth, int maxHealth, int attack, int defense, int experience)
{
	this->name = name;
	this->level = level;
	this->health = currentHealth;
	this->maxHealth = maxHealth;
	this->attack = attack;
	this->defense = defense;
	this->experience = experience;
}

Player::~Player()
{
}

void Player::init(std::string name, int level, int currentHealth, int maxHealth, int attack, int defense, int experience, Space map)
{
	this->name = name;
	this->level = level;
	this->currentHealth = currentHealth;
	this->maxHealth = maxHealth;
	this->attack = attack;
	this->defense = defense;
	this->experience = experience;
	this->map = map;
}

void Player::addKey(void)
{
	keys++;
}

bool Player::addExperience(int experience)
{
	this->experience += experience;
	while (this->experience >= 100) //leveled up
	{
		this->experience -= 100;
		levelUp();

		if (experience < 100)
		{
			return true;
		}
	}
	return false;
}

void Player::setPrevTile(char prevTile)
{
	this->prevTile = prevTile;
}

int Player::takeDamage(int attack)
{
	attack -= defense;
	if (attack > 0)
	{
		currentHealth -= attack;
		return attack;
	}
	else if(attack <= 0)
	{
		return 0;
	}
	return 0;
}

int Player::battle()
{
	std::default_random_engine randomEngine(time(NULL));
	std::uniform_int_distribution<int> attackRoll(0, this->attack);
	return attackRoll(randomEngine);
}

void Player::levelUp(void)
{
	attack += 2;
	defense += 1;
	maxHealth += 5;
	health = maxHealth;
	level++;
}