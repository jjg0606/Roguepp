#include "GameMap.h"
#include <iostream>

using namespace std;

GameMap::GameMap(int _rows,int _cols) : rows(_rows),cols(_cols)
{
	isShowing = true;
	objMap = new MapObject**[rows];
	for (int r = 0; r < rows; r++)
	{
		objMap[r] = new MapObject*[cols];
		for (int c = 0; c < cols; c++)
		{
			objMap[r][c] = nullptr;
		}
	}
}

GameMap::~GameMap()
{
	for (int r = 0; r < rows; r++)
	{
		delete[] objMap[r];
	}
	delete[] objMap;
}

void GameMap::Init()
{
}

void GameMap::Update()
{

}

void GameMap::Print()
{
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << ((objMap[r][c] == nullptr) ? "  " : objMap[r][c]->shape);
		}
		cout << '\n';		
	}
}

void GameMap::SetVariable(string text)
{

}

bool GameMap::isInBoundary(int nextrow, int nextcol)
{
	if (nextrow < 0 || nextrow >= rows || nextcol < 0 || nextcol >= cols)
	{
		return false;
	}
	return true;
}

const string GameMap::name = "map";