#pragma once
#include <string>
#include <fstream>
#include "GameObject.h"

// Map 텍스트 파일을 읽고,
// 읽은 내용을 바탕으로 객체를 생성해서 넘겨줌
// 싱글턴
class MapFileReader
{
private:
	static MapFileReader instance;
	MapFileReader();
	std::ifstream ifs;
public:
	bool OpenMap(std::string);
	void GetMapSize(int& rows, int& cols);
	GameObject* ReadObject();
	void CloseMap();
	static MapFileReader& GetInstance();
};