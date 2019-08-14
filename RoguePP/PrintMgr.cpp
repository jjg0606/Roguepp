#include "PrintMgr.h"
#include <iostream>

using namespace std;

PrintMgr PrintMgr::instance;

PrintMgr::PrintMgr() : queSize(0)
{
	
}

PrintMgr& PrintMgr::GetInstance()
{
	return instance;
}

void PrintMgr::StartPrint()
{
	for (int i = 0; i < queSize; i++)
	{
		printableQue[i]->Print();
	}
}

void PrintMgr::ClearPrint()
{
	system("cls");
}

void PrintMgr::AddQue(Printable* printableObj)
{
	if (queSize + 1 >= PRINTABLE_QUE_MAX)
	{
		return;
	}

	printableQue[queSize] = printableObj;
	queSize++;
}

void PrintMgr::ClearQue()
{
	queSize = 0;
}
