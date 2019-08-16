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


void LevelStartMap()
{
	ObjectMgr& omgr = ObjectMgr::GetInstance();
	PrintMgr& pmgr = PrintMgr::GetInstance();
	MapFileReader& mfr = MapFileReader::GetInstance();
	if (!mfr.OpenMap("firstmap.txt"))
	{
		return;
	}

	infoTop* ift = nullptr;
	ift = (infoTop*)omgr.GetObjFromMap(infoTop::name);
	if (ift == nullptr)
	{
		ift = new infoTop();
		omgr.AddMap(infoTop::name, ift);
		omgr.AddQue(ift);
	}
	ift->isShowing = true;
	ift->msg = "첫번째 마을 입니다.";
	
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
	if (omgr.GetObjFromMap(player::name) == nullptr)
	{
		player* pl = new player();
		pl->row = rows / 2;
		pl->col = cols / 2;
		omgr.AddMap(player::name, pl);
		omgr.AddQue(pl);
	}			

	//// PRINT ORDER ////
	pmgr.AddQue(ift);
	pmgr.AddQue(mapobj);
}