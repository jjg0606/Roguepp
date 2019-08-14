#pragma once
#include "GameObject.h"

// ���� GameObject�� ����
// �̱���
class ObjectMgr
{
private:
	ObjectMgr();
	static ObjectMgr instance;
	GameObject** gameObjQue;
	int queSize;
	int queCapacity;
public:
	static ObjectMgr& GetInstance();
	void StartInit();
	void StartUpdate();
	void AddQue(GameObject* gameObj);
	void ClearQue();
	void ClearEvenStatic();
	void SetQueCapacity(int capacity);
};