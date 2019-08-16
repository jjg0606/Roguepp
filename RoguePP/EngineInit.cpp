#include "EngineInit.h"
#include "LevelList.h"
#include "LevelMgr.h"
#include "ObjectMgr.h"
#include "PrintMgr.h"
#include "GameObjFactory.h"
#include "wall.h"
#include "portal.h"
#include "zergling.h"
#include <string>
#include <regex>
using namespace std;

void EngineAddLevels()
{
	LevelMgr& lvmgr = LevelMgr::GetInstance();
	lvmgr.AddLevel("intro", LevelIntro);
	lvmgr.AddLevel("startmap", LevelStartMap);
	lvmgr.AddLevel("secondmap", LevelSecondMap);
}

void EngineAddObj()
{
	GameObjFactory& objfac = GameObjFactory::GetInstance();
	objfac.AddObj("wall", []()->GameObject* {return new wall();});
	objfac.AddObj("portal", []()->GameObject* {return new portal(); });
	objfac.AddObj("zergling", []()->GameObject* {return new zergling(); });
}
