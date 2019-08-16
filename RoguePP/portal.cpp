#include "portal.h"
#include "ObjectMgr.h"
#include "LevelMgr.h"
#include "player.h"
#include <regex>
using namespace std;

portal::portal() : nextMapRow(0), nextMapCol(0), nextmap("")
{
	shape = "£À";
}

void portal::Init()
{

}

void portal::Update()
{

}

void portal::SetVariable(string text)
{
	regex portalregex(R"((\d+) (\d+) (\w+) (\d+) (\d+))");
	smatch match;
	regex_match(text, match, portalregex);

	this->row = stoi(match[1]);
	this->col = stoi(match[2]);
	this->nextmap = match[3];
	this->nextMapRow = stoi(match[4]);
	this->nextMapCol = stoi(match[5]);
}

void portal::Interact(MapObject* origin)
{
	player* pl = (player*)origin;
	pl->row = this->nextMapRow;
	pl->col = this->nextMapCol;
	LevelMgr::GetInstance().SetLevel(nextmap);
}
