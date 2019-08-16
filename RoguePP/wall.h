#pragma once
#include "MapObject.h"

class wall
	: public MapObject
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void SetVariable(std::string) override;
	virtual void Interact(MapObject* origin) override;
	wall();
	/*int row;
	int col;
	std::string shape;*/
};