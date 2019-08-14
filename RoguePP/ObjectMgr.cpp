#include "ObjectMgr.h"
ObjectMgr ObjectMgr::instance;

ObjectMgr::ObjectMgr()
	: gameObjQue(nullptr), queSize(0), queCapacity(0)
{
	SetQueCapacity(100);
}

ObjectMgr& ObjectMgr::GetInstance()
{
	return instance;
}

void ObjectMgr::StartInit()
{
	for (int i = 0; i < queSize; i++)
	{
		gameObjQue[i]->Init();
	}
}

void ObjectMgr::StartUpdate()
{
	for (int i = 0; i < queSize; i++)
	{
		gameObjQue[i]->Update();
	}
}

void ObjectMgr::AddQue(GameObject* gameObj)
{
	if (queSize + 1 >= queCapacity)
	{
		return;
	}

	gameObjQue[queSize] = gameObj;
	queSize++;
}

void ObjectMgr::ClearQue()
{
	int front = 0;
	for (int i = 0; i < queSize; i++)
	{
		if (gameObjQue[i]->isStatic)
		{
			gameObjQue[front++] = gameObjQue[i];
		}
		else
		{
			delete gameObjQue[i];
		}
	}
	queSize = front;

}

void ObjectMgr::ClearEvenStatic()
{
	for (int i = 0; i < queSize; i++)
	{
		delete gameObjQue[i];
	}
	queSize = 0;
}

void ObjectMgr::SetQueCapacity(int capacity)
{
	this->queCapacity = capacity;
	if (gameObjQue != nullptr)
	{
		delete[] gameObjQue;
	}

	gameObjQue = new GameObject*[capacity];
	this->queSize = 0;
}