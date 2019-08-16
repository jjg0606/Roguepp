#include "zergling.h"
#include "BattleSystem.h"
#include "ObjectMgr.h"
#include "GameMap.h"
#include <regex>

using namespace std;
extern void(*gameEnd)();
extern int ZERGLING_HP_MAX;
extern int	ZERGLING_MP_MAX;
extern int	ZERGLING_ATK;
extern int	ZERGLING_DEF;

zergling::zergling()
{
	shape = "¢Á";

	hpmax = ZERGLING_HP_MAX;
	hp = hpmax;
	mpmax = ZERGLING_MP_MAX;
	mp = mpmax;
	atk = ZERGLING_MP_MAX;
	def = ZERGLING_DEF;
	name = "Àú±Û¸µ";
}

void zergling::Interact(MapObject* origin)
{
	BattleSystem::StartBattle(this);
	if (this->hp <= 0)
	{
		((GameMap*)ObjectMgr::GetInstance().GetObjFromMap(GameMap::name))->objMap[row][col] = nullptr;
		this->row = -1;
		this->col = -1;
	}
	if (((BattleObj*)origin)->hp <= 0)
	{
		gameEnd();
	}
	
}

void zergling::Update()
{

}

void zergling::Init()
{
}

void zergling::SetVariable(string text)
{
	regex pointregex(R"((\d+) (\d+))");
	smatch match;
	regex_match(text, match, pointregex);

	this->row = stoi(match[1]);
	this->col = stoi(match[2]);
}