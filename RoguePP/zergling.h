#pragma once
#include "MapObject.h"
#include "BattleObj.h"

class zergling
	: public MapObject, public BattleObj
{
public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void SetVariable(std::string) override;
	virtual void Interact(MapObject* origin) override;
	zergling();
	
	/*int hp;
	int hpmax;
	int mp;
	int mpmax;
	int atk;
	int def;*/
};