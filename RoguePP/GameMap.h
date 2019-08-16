#pragma once
#include "GameObject.h"
#include "Printable.h"
#include "MapObject.h"

class GameMap : public GameObject, public Printable
{
private:
	int rows;
	int cols;

public:
	MapObject*** objMap;
	const static std::string name;
	void Init() override;
	void Update() override;
	void Print() override;
	virtual void SetVariable(std::string) override;
	bool isInBoundary(int nextrow, int nextcol);
	//bool isShowing;
	GameMap(int _rows,int _cols);
	~GameMap();
};