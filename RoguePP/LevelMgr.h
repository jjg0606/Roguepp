#pragma once
#include <string>
#include <map>

// ���� level �� ����
// PrintMgr, ObjectMgr �� ���ӿ� �ʿ���
// ���� ������Ʈ�� ���� ����ÿ� �����ϴ� ����
// �̱���
class LevelMgr
{
private:
	LevelMgr();
	static LevelMgr instance;
	std::map<std::string, void(*)()> levelPointerMap;
public:
	static LevelMgr& GetInstance();
	void SetLevel(std::string name);
	void AddLevel(std::string name, void(*levelPointer)());
};