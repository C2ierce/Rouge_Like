#include "Space.h"

Space::Space()
{
	isVisible = false;
	hasBeenExplored = false;
	tile = ' ';
}

Space::~Space()
{

}

void Space::setResizeMap(int d1Size, int d2Size)
{
	this->resize(d1Size);
	for (int i = 0; i < map.size(); i++)
	{
		this[i].resize(d2Size);
	}
}

void Space::resize(int row)
{
	map.resize(row);
}

void Space::setTile(int xPos, int yPos, char tile)
{
	map[xPos][yPos].tile = tile;
}

void Space::setTile(int xPos, int yPos, char tile, bool visibility)
{
	map[xPos][yPos].tile = tile;
	map[xPos][yPos].isVisible = visibility;
}

char Space::getTile(int xPos, int yPos)
{
	return map[xPos][yPos].tile;
}

int Space::getSizeX()
{
	return map.size();
}

int Space::getSizeY(int y)
{
	return map[y].size();
}

bool Space::getTileVisibility(int xPos, int yPos)
{
	return map[xPos][yPos].isVisible;
}

bool Space::getTileVisibility()
{
	return this->isVisible;
}

void Space::setTileVisibility(int xPos, int yPos, bool visibility)
{
	map[xPos][yPos].isVisible = visibility;
}

std::string Space::getMap()
{
	std::string mMap = ""; //clears the map that we store in this string
	//Map
	for (int row = 0; row < map.size(); row++)
	{
		for (int column = 0; column < map[row].size(); column++)
		{
			//compare to second map array and see where player position is and then only render tiles that are set to visibility true
			//strMap += levelData[row][column];
			if (map[row][column].isVisible)
			{
				mMap += map[row][column].tile;
			}
			else
			{
				mMap += ' ';
			}
		}
		mMap += "\n";
	}
	return mMap;
}

void Space::setHasBeenExplored(int xPos, int yPos, bool hasBeenExplored)
{
	map[xPos][yPos].hasBeenExplored = hasBeenExplored;
}

bool Space::getHasBeenExplored(int xPos, int yPos)
{
	return map[xPos][yPos].hasBeenExplored;
}

void Space::setPlayerView(int plrXPos, int plrYPos)
{
	//SET PLAYER PERSPECTIVE TO SQUARE I.E. 
	//...
	//.@.
	//...
	map[plrXPos][plrYPos].isVisible = true;
	map[plrXPos - 1][plrYPos].isVisible = true; //UP
	map[plrXPos][plrYPos - 1].isVisible = true; //LEFT
	map[plrXPos][plrYPos + 1].isVisible = true; //RIGHT
	map[plrXPos + 1][plrYPos].isVisible = true; //DOWN
	map[plrXPos + 1][plrYPos - 1].isVisible = true; //BTM LEFT
	map[plrXPos + 1][plrYPos + 1].isVisible = true; //BTM RIGHT
	map[plrXPos - 1][plrYPos - 1].isVisible = true; //TOP LEFT
	map[plrXPos - 1][plrYPos + 1].isVisible = true; //TOP RIGHT

	//SET TILE TO EXPLORED
	map[plrXPos][plrYPos].hasBeenExplored = true;
	map[plrXPos - 1][plrYPos].hasBeenExplored = true; //UP
	map[plrXPos][plrYPos - 1].hasBeenExplored = true; //LEFT
	map[plrXPos][plrYPos + 1].hasBeenExplored = true; //RIGHT
	map[plrXPos + 1][plrYPos].hasBeenExplored = true; //DOWN
	map[plrXPos + 1][plrYPos - 1].hasBeenExplored = true; //BTM LEFT
	map[plrXPos + 1][plrYPos + 1].hasBeenExplored = true; //BTM RIGHT
	map[plrXPos - 1][plrYPos - 1].hasBeenExplored = true; //TOP LEFT
	map[plrXPos - 1][plrYPos + 1].hasBeenExplored = true; //TOP RIGHT
}