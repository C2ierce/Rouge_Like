#pragma once
#include <vector>;
#include <string>
class Space
{
public:
	std::vector<std::vector<Space>> map;
	Space();
	~Space();

	Space(int d1Size, int d2Size)
	{
		map.resize(d1Size);
		for (int i = 0; i < map.size(); i++)
			map[i].resize(d2Size);
	}

	struct Tiles
	{
		char player = '@';
		char enemy = 'e';
		char goblin = 'g';
		char snake = 's';
		char wall = '#';
		char floor = '.';
		char lockDoorOne = '|';
		char lockDoorTwo = '-';
		char openDoor = '/';
		char key = 'k';
		char item = 'i';
		char space = ' ';
	}  tiles;
	
	//Setters
	void setTile(int xPos, int yPos, char tile);
	void setTile(int xPos, int yPos, char tile, bool visibility);
	void setResizeMap(int d1Size, int d2Size);
	void resize(int row);
	void setHasBeenExplored(int xPos, int yPos, bool hasBeenExplored);
	void setPlayerView(int plrXPos, int plrYPos);

	//Getters
	char getTile(int xPos, int yPos);
	bool getTileVisibility(int xPos, int yPos);
	bool getTileVisibility();
	void setTileVisibility(int xPos, int yPos, bool visibility);
	bool getHasBeenExplored(int xPos, int yPos);
	
	std::string getMap();

	int getSizeX();
	int getSizeY(int y);
	float fGlobalGoal;				// Distance to goal so far
	float fLocalGoal;				// Distance to goal if we took the alternative route
	int x;							// Nodes position in 2D space
	int y;
protected:
	char tile;
	bool isVisible;
	bool hasBeenExplored;
};