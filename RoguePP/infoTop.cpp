#include "infoTop.h"
#include <iostream>
#include "PrintMgr.h"
using namespace std;

infoTop::infoTop() : msg("")
{
	isStatic = true;
	isShowing = true;
}

void infoTop::Print()
{
	cout << msg << '\n';
	
}

void infoTop::Init()
{
}

const string infoTop::name = "infotop";