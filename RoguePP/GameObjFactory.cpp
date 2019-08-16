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

void GameObjFactory::AddObj(string code, GameObject*(*createfunc)())
{
	objFactoryMap.insert(make_pair(code, createfunc));
}

GameObject* GameObjFactory::GetObj(string code)
{
	auto func = objFactoryMap[code];
	if (func == nullptr)
	{
		return nullptr;
	}
	return func();
}