#pragma once
#include <map>
#include <string>
#include "GameObject.h"

// °¢Á¾ GameObject¸¦ °ü¸®
// ½Ì±ÛÅæ
class ObjectMgr
{
private:
	ObjectMgr();
	static ObjectMgr instance;
	GameObject** gameObjQue;
	int queSize;
	int queCapacity;
	std::map<std::string, GameObject*> gameObjMap;
	bool isCleared;
public:
	static ObjectMgr& GetInstance();
	void StartInit();
	void StartUpdate();
	void AddQue(GameObject* gameObj);
	void ClearQue();
	void ClearEvenStatic();
	void SetQueCapacity(int capacity);
	void AddMap(std::string, GameObject*);

	GameObject* GetObjFromMap(std::string);
};