#pragma once
#include "BattleObj.h"
#include "player.h"

class BattleSystem
{
private:
	BattleSystem(BattleObj* target);
	std::string infobar;
	void PrintBattleSwitch();
	void ProcessInput();
	void Update();
	int curmenu;
	int cursorpos;
	bool isEnd;
	player* mPlayer;
	BattleObj* target;
	void init();
public:
	static void StartBattle(BattleObj* target);
};
