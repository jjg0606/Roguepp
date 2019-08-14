#include "GameObjFactory.h"

using namespace std;

GameObjFactory GameObjFactory::instance;

GameObjFactory::GameObjFactory()
{

}

GameObjFactory& GameObjFactory::GetInstance()
{
	return instance;
}

void GameObjFactory::AddObj(string code, GameObject*(*createfunc)(string))
{
	objFactoryMap.insert(make_pair(code, createfunc));
}

GameObject* GameObjFactory::GetObj(string code, string args)
{
	return objFactoryMap[code](args);
}