#include "EngineInit.h"
#include "LevelList.h"
#include "LevelMgr.h"
#include "ObjectMgr.h"
#include "PrintMgr.h"
#include "GameObjFactory.h"
#include <string>
#include <regex>
using namespace std;

void EngineAddLevels()
{
	LevelMgr& lvmgr = LevelMgr::GetInstance();
	lvmgr.AddLevel("intro", LevelIntro);
	lvmgr.AddLevel("startmap", LevelStartMap);
}

void EngineAddObj()
{
	GameObjFactory& objfac = GameObjFactory::GetInstance();
}
