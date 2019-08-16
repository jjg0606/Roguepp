#pragma once
#include <string>

class GameObject
{
public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void SetVariable(std::string) = 0;
	bool isStatic;
};