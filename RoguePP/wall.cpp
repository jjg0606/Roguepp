#include "wall.h"
#include <regex>
using namespace std;

wall::wall()
{
	this->shape = "бс";
}

void wall::Init()
{

}

void wall::Update()
{

}

void wall::SetVariable(string text)
{
	regex wallregex(R"((\d+) (\d+))");
	smatch match;
	regex_match(text, match, wallregex);

	this->row = stoi(match[1]);
	this->col = stoi(match[2]);
}

void wall::Interact(MapObject* origin)
{
	
}