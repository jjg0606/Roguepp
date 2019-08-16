#pragma once
#include "GameObject.h"
#include <map>
#include <string>
// 맵 상의 스트링을 읽고 
// 그에 맞는 gameobj 객체를 생성해서 넘겨줌
// 싱글턴
class GameObjFactory
{
private:
	static GameObjFactory instance;
	GameObjFactory();
	std::map<std::string, GameObject*(*)()> objFactoryMap;
public:
	static GameObjFactory& GetInstance();
	void AddObj(std::string, GameObject*(*)());
	GameObject* GetObj(std::string key);
};