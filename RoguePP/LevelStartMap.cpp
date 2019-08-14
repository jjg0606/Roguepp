#include "LevelList.h"
#include "GameObject.h"
#include "Printable.h"
#include "ObjectMgr.h"
#include "PrintMgr.h"
#include "InputTrans.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

class StartMapObj
	: public GameObject, public Printable
{
public:
	void Init()
	{
		this->isStatic = false;
	}

	void Update()
	{

	}

	void Print()
	{
		cout << "this is startmap" << '\n';
		cout << "developing now" << '\n';
	}

};

void LevelStartMap()
{
	StartMapObj* smo = new StartMapObj();
	ObjectMgr::GetInstance().AddQue(smo);
	PrintMgr::GetInstance().AddQue(smo);
}