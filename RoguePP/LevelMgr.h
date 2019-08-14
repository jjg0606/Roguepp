#pragma once
#include <string>
#include <map>

// 각종 level 을 관리
// PrintMgr, ObjectMgr 등 게임에 필요한
// 각종 오브젝트를 레벨 변경시에 세팅하는 역할
// 싱글톤
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