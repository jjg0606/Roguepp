#pragma once
#include "GameObject.h"

class MapObject
	: public GameObject
{
public:
	int row;
	int col;
	std::string shape;
	virtual void Init() override = 0;
	virtual void Update() override = 0;
	virtual void SetVariable(std::string) override = 0;
	virtual void Interact(MapObject* origin) = 0;
};