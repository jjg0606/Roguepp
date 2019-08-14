#include "LevelMgr.h"
#include "PrintMgr.h"
#include "ObjectMgr.h"
using namespace std;

LevelMgr LevelMgr::instance;

LevelMgr::LevelMgr()
{

}

LevelMgr& LevelMgr::GetInstance()
{
	return instance;
}

void LevelMgr::SetLevel(string name)
{
	// TODO:
	// 현재 작동하고 있는 Mgr 들 초기화하고
	// levelPointer를 작동시켜, 새로 레벨을 세팅
	ObjectMgr::GetInstance().ClearQue();
	PrintMgr::GetInstance().ClearQue();
	PrintMgr::GetInstance().ClearPrint();
	levelPointerMap[name]();
	ObjectMgr::GetInstance().StartInit();
}

void LevelMgr::AddLevel(string name, void(*levelPointer)())
{
	levelPointerMap.insert(make_pair(name, levelPointer));
}