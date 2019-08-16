#pragma once
#include "MapObject.h"

class portal
	: public MapObject
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void SetVariable(std::string) override;
	virtual void Interact(MapObject* origin) override;
	portal();
	std::string nextmap;
	int nextMapRow;
	int nextMapCol;
	/*int row;
	int col;
	std::string shape;*/
};