#include "Skill.h"
#include "BattleObj.h"

// battle object who can use skill
class BattleObjS
	: public BattleObj
{
public:
	/*int hp;
	int mp;
	int atk;
	int def;*/
	Skill** list;
	int skillcount;
};