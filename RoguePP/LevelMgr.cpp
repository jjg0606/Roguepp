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
	// ���� �۵��ϰ� �ִ� Mgr �� �ʱ�ȭ�ϰ�
	// levelPointer�� �۵�����, ���� ������ ����
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