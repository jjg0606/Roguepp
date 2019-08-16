#pragma once
#include "GameObject.h"
#include <map>
#include <string>
// �� ���� ��Ʈ���� �а� 
// �׿� �´� gameobj ��ü�� �����ؼ� �Ѱ���
// �̱���
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