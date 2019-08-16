#pragma once
#include "MapObject.h"
#include "GameMap.h"
#include "BattleObjS.h"

class player
	: public MapObject, public BattleObjS
{
protected:
	void(player::*upfunc)();
public:
	const static std::string name;
	virtual void Init() override;
	virtual void Update() override;
	virtual void SetVariable(std::string) override;
	virtual void Interact(MapObject* origin) override;
	player();
	GameMap* map;
	/*int row;
	int col;
	std::string shape;*/
	void MovePhase();

	//from battleobjs
	/*int hp;
	int mp;
	int atk;
	int def;*/
	/*Skill** list;
	int skillcount;*/
};
