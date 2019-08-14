#pragma once
#include "GameObject.h"
#include "GameMap.h"
#include <string>

class MapObject
	: public GameObject
{
public:
	int row;
	int col;
	std::string shape;
	void Init() override;
	void Update() override;
	void Interact();
};