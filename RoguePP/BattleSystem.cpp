#include "BattleSystem.h"
#include "PrintMgr.h"
#include "ObjectMgr.h"
#include "InputTrans.h"
#include <conio.h>
#include <iostream>

using namespace std;
void BattleSystem::PrintBattleSwitch()
{
	if (curmenu == 0)
	{
		cout << "\n";
		cout << (cursorpos == 0 ? "��" : "  ") << "�����ϱ�" << '\n';
		cout << (cursorpos == 1 ? "��" : "  ") << "��ų����" << '\n';
		cout << (cursorpos == 2 ? "��" : "  ") << "����ϱ�" << '\n';
	}
}

void BattleSystem::ProcessInput()
{
	InputBtn btn = InputTrans::getKey(getch());
	if (btn == InputBtn::DOWN)
	{
		cursorpos = cursorpos + 1 < 3 ? cursorpos + 1 : 2;
	}
	else if (btn == InputBtn::UP)
	{
		cursorpos = cursorpos - 1 >= 0 ? cursorpos - 1 : 0;
	}
	else if (btn == InputBtn::CONFIRM)
	{
		if (curmenu == 0)
		{
			if (cursorpos == 0) // �����ϱ�
			{
				infobar = "�÷��̾��� ����!";
			}
			else if (cursorpos == 2) // ����ϱ�
			{
				infobar = "�÷��̾� ���!";
			}
		}
	}
	else if (btn == InputBtn::CANCEL)
	{
		if (curmenu > 0)
		{
			curmenu = 0;
			cursorpos = 0;
		}
	}
}

void BattleSystem::StartBattle(BattleObj* target)
{
	BattleSystem bs(target);
	while (!bs.isEnd)
	{
		bs.Update();
	}
}

BattleSystem::BattleSystem(BattleObj* Target)
{
	this->target = Target;
	this->mPlayer = (player*)ObjectMgr::GetInstance().GetObjFromMap(player::name);
	curmenu = 0;
	cursorpos = 0;
	isEnd = false;
	init();
}

void BattleSystem::Update()
{
	system("cls");
	cout << infobar << '\n';
	cout << "\t\t\t<" << target->name << ">\n";
	cout << "\t\t\thp = " << target->hp << '\n';

	cout << "<�÷��̾�>" << '\n';
	cout << "hp = " << mPlayer->hp;
	PrintBattleSwitch();
	
	ProcessInput();
}

void BattleSystem::init()
{
	infobar = target->name + "���� ���� !!!";
}