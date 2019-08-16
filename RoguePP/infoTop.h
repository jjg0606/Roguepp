#pragma once
#include "GameObject.h"
#include "Printable.h"

// 화면 상단에 뜨는 정보를 관리하는 UI 클래스
class infoTop
	: public GameObject, public Printable
{
public:
	infoTop();
	std::string msg;
	const static std::string name;
	//bool isShowing;
	void Init() override;
	void Update() override
	{
	};
	void Print() override;
	virtual void SetVariable(std::string) override
	{
	};
};