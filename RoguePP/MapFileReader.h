#pragma once
#include <string>
#include <fstream>
#include "GameObject.h"

// Map �ؽ�Ʈ ������ �а�,
// ���� ������ �������� ��ü�� �����ؼ� �Ѱ���
// �̱���
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