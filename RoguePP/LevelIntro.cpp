#include "LevelList.h"
#include "GameObject.h"
#include "Printable.h"
#include "ObjectMgr.h"
#include "PrintMgr.h"
#include "InputTrans.h"
#include "LevelMgr.h"
#include <conio.h>
#include <iostream>
#include <Windows.h>

using namespace std;

extern void(*gameEnd)();

class IntroObj 
	: public GameObject, public Printable
{
private:
	int frame = 0;
	int cursorPos = 0;
public:
	void Init() override
	{
		isStatic = false;
	}

	void Update() override
	{
		bool canGoOut = false;
		while (kbhit()&&!canGoOut)
		{
			InputBtn input = InputTrans::getKey(getch());
			switch (input)
			{
			case InputBtn::UP:				
				cursorPos--;
				cursorPos = cursorPos < 0 ? 0 : cursorPos;
				canGoOut = true;
				break;
			case InputBtn::DOWN:				
				cursorPos++;
				cursorPos = cursorPos > 2 ? 2 : cursorPos;
				canGoOut = true;
				break;
			case InputBtn::CONFIRM:
				ConfirmBtnPressed();
				canGoOut = true;
				break;
			default:
				break;
			}
		}		
	}

	void ConfirmBtnPressed()
	{
		switch (cursorPos)
		{
		case 0:
			StartNewGame();
			break;
		case 1:
			LoadGame();
			break;
		case 2:
			EndGame();
			break;
		}
	}

	void StartNewGame()
	{
		LevelMgr::GetInstance().SetLevel("startmap");
	}

	void LoadGame()
	{

	}

	void EndGame()
	{
		gameEnd();
	}

	void Print() override
	{
		cout << "\n\n\n";
		cout << "\t\t" << "����    ����    ����"<< '\n';
		cout << "\t\t" << "��  ��    ��  ��    ��    "  << '\n';
		cout << "\t\t" << "���      ��  ��    ��    " << '\n';
		cout << "\t\t" << "��  ��    ��  ��    ��  ��" << '\n';
		cout << "\t\t" << "��  ��    ��  ��    ��  ��" << '\n';
		cout << "\t\t" << "��  ��    ����    ����" << '\n';
		cout << "\n\n";
		cout << "\t\t" << (cursorPos == 0 ? "��" : "  ") << "\tStart New Game" << '\n';
		cout << "\t\t" << (cursorPos == 1 ? "��" : "  ") <<"\t   Load Game" << '\n';
		cout << "\t\t" << (cursorPos == 2 ? "��" : "  ") <<"\t      Exit" << '\n';
	}
};

void LevelIntro()
{
	IntroObj* introObj = new IntroObj();
	ObjectMgr::GetInstance().AddQue(introObj);
	PrintMgr::GetInstance().AddQue(introObj);
}