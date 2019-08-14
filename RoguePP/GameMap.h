#pragma once
#include "GameObject.h"
#include "Printable.h"
#include "MapObject.h"

class GameMap
	: public GameObject, public Printable
{
public:
	void Init() override;
	void Update() override;
	void Print() override;
	bool isInBoundary(int nextrow, int nextcol);
	int rows;
	int cols;
	MapObject*** objMap;
	GameMap(int _rows, int _cols);
};