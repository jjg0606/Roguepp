#include "LevelList.h"
#include "LevelMgr.h"
#include "ObjectMgr.h"
#include "PrintMgr.h"
#include "EngineInit.h"
using namespace std;

bool isGameRun = true;
void(*gameEnd)();

void TriggerGameEnd()
{
	isGameRun = false;
}

int main()
{
	LevelMgr& lvmgr = LevelMgr::GetInstance();
	gameEnd = TriggerGameEnd;
	// add level
	EngineAddLevels();
	// add gameobj
	EngineAddObj();


	lvmgr.SetLevel("intro");
	while (isGameRun)
	{
		PrintMgr::GetInstance().ClearPrint();
		PrintMgr::GetInstance().StartPrint();
		ObjectMgr::GetInstance().StartUpdate();
		
	}

	ObjectMgr::GetInstance().ClearEvenStatic();
	return 0;
}

