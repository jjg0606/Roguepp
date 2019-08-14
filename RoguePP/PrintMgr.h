#pragma once
#include "Printable.h"

constexpr int PRINTABLE_QUE_MAX = 10;

// 화면의 출력을 관리하는 클래스 (싱글턴)
class PrintMgr
{
private :
	PrintMgr();
	static PrintMgr instance;
	Printable* printableQue[PRINTABLE_QUE_MAX];
	int queSize;
public:
	static PrintMgr& GetInstance();
	void StartPrint();
	void ClearPrint();
	void AddQue(Printable* printableObj);
	void ClearQue();
};
