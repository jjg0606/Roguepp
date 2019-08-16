#include "player.h"
#include "ObjectMgr.h"
#include "InputTrans.h"
#include <iostream>
#include <conio.h>

using namespace std;

extern int PLAYER_HP_MAX;
extern int PLAYER_MP_MAX;
extern int PLAYER_DEFAULT_ATK;
extern int PLAYER_DEFAULT_DEF;

player::player()
{
	isStatic = true;
	
	this->shape = "ขอ";	
	this->upfunc = nullptr;

	hpmax = PLAYER_HP_MAX;
	hp = hpmax;
	mpmax = PLAYER_MP_MAX;
	mp = mpmax;
	atk = PLAYER_DEFAULT_ATK;
	def = PLAYER_DEFAULT_DEF;

	skillcount = 0;
	
	
}

void player::Init()
{
	map = (GameMap*)ObjectMgr::GetInstance().GetObjFromMap("map");
	map->objMap[this->row][this->col] = this;
	this->upfunc = &player::MovePhase;
}

void player::SetVariable(string text)
{

}

void player::Interact(MapObject* origin)
{

}


void player::Update()
{
	(this->*upfunc)();
}

void player::MovePhase()
{
	map->objMap[this->row][this->col] = nullptr;
	char input = getch();
	InputBtn btn = InputTrans::getKey(input);
	switch (btn)
	{
	case InputBtn::UP:
		if (map->isInBoundary(this->row - 1, this->col))
		{
			if (map->objMap[this->row - 1][this->col] == nullptr)
			{
				this->row--;
			}
			else
			{
				map->objMap[this->row - 1][this->col]->Interact(this);
			}			
		}
		break;
	case InputBtn::DOWN:
		if (map->isInBoundary(this->row + 1, this->col))
		{
			if (map->objMap[this->row + 1][this->col] == nullptr)
			{
				this->row++;
			}
			else
			{
				map->objMap[this->row + 1][this->col]->Interact(this);
			}
			
		}
		break;
	case InputBtn::LEFT:
		if (map->isInBoundary(this->row, this->col - 1))
		{
			if (map->objMap[this->row][this->col-1] == nullptr)
			{
				this->col--;
			}
			else
			{
				map->objMap[this->row][this->col-1]->Interact(this);
			}
		}
		break;
	case InputBtn::RIGHT:
		if (map->isInBoundary(this->row , this->col+1))
		{
			if (map->objMap[this->row][this->col+1] == nullptr)
			{
				this->col++;
			}
			else
			{
				map->objMap[this->row][this->col+1]->Interact(this);
			}
		}
		break;
	case InputBtn::CANCEL:
		break;
	case InputBtn::CONFIRM:
		break;
	default:
		break;
	}
	map->objMap[this->row][this->col] = this;
}


const std::string player::name = "player";