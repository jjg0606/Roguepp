#pragma once
#include "GameObject.h"
#include "Printable.h"

// ȭ�� ��ܿ� �ߴ� ������ �����ϴ� UI Ŭ����
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