#pragma once
#include "Printable.h"

constexpr int PRINTABLE_QUE_MAX = 10;

// ȭ���� ����� �����ϴ� Ŭ���� (�̱���)
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
