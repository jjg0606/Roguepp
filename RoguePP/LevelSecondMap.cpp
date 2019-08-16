#include "LevelList.h"
#include "GameObject.h"
#include "Printable.h"
#include "ObjectMgr.h"
#include "PrintMgr.h"
#include "InputTrans.h"
#include "MapFileReader.h"
#include "MapObject.h"
#include "GameMap.h"
#include "player.h"
#include "infoTop.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

void LevelSecondMap()
{
	ObjectMgr& omgr = ObjectMgr::GetInstance();
	PrintMgr& pmgr = PrintMgr::GetInstance();
	MapFileReader& mfr = MapFileReader::GetInstance();
	if (!mfr.OpenMap("second.txt"))
	{
		return;
	}

	infoTop* ift = (infoTop*)omgr.GetObjFromMap(infoTop::name);
	omgr.AddQue(ift);

	ift->isShowing = true;
	ift->msg = "두번째 마을 입니다.";

	int rows = 0, cols = 0;
	mfr.GetMapSize(rows, cols);
	GameMap* mapobj = new GameMap(rows, cols);

	omgr.AddMap(GameMap::name, mapobj);
	omgr.AddQue(mapobj);
	while (true)
	{
		MapObject* curread = (MapObject*)mfr.ReadObject();
		if (curread == nullptr)
		{
			break;
		}
		omgr.AddQue(curread);
		mapobj->objMap[curread->row][curread->col] = curread;
	}
	mfr.CloseMap();

	//// PRINT ORDER ////
	pmgr.AddQue(ift);
	pmgr.AddQue(mapobj);
}