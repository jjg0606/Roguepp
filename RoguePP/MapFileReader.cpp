#include "MapFileReader.h"
#include "GameObjFactory.h"

using namespace std;

MapFileReader MapFileReader::instance;

MapFileReader::MapFileReader()
{
}

MapFileReader& MapFileReader::GetInstance()
{
	return instance;
}

bool MapFileReader::OpenMap(std::string filename)
{
	ifs.open(filename, ios::in);
	
	return ifs.good() ? true : false;
}

void MapFileReader::CloseMap()
{
	ifs.close();
}

void MapFileReader::GetMapSize(int& rows, int& cols)
{
	ifs >> rows >> cols;
}

GameObject* MapFileReader::ReadObject()
{
	if (!ifs.good()||ifs.cur == ifs.end)
	{
		return nullptr;
	}

	string variabletxt = "";
	int row = 0, col = 0;
	ifs >> row >> col;

	variabletxt.append(to_string(row) + " " + to_string(col));

	string objectType = "";
	ifs >> objectType;

	int parameterCount = 0;
	ifs >> parameterCount;

	string param = "";
	for (int i = 0; i < parameterCount; i++)
	{
		ifs >> param;
		variabletxt.append(" " + param);
		param.clear();
	}

	GameObject* makingObject = GameObjFactory::GetInstance().GetObj(objectType);
	if (makingObject == nullptr)
	{
		return nullptr;
	}

	makingObject->SetVariable(variabletxt);

	return makingObject;
}