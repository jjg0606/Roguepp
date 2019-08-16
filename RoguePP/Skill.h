#pragma once
#include "BattleObj.h"
#include <string>

class Skill
{
public:
	std::string name;
	std::string info;
	int cost;
	virtual void Active(BattleObj* user, BattleObj* enemy) = 0;
};