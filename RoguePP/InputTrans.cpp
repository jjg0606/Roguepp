#include "InputTrans.h"

InputBtn InputTrans::getKey(char input)
{
	if (input == 'a' || input == 'A' || input == 75)
	{
		return InputBtn::LEFT;
	}
	if (input == 's' || input == 'S' || input == 80)
	{
		return InputBtn::DOWN;
	}
	if (input == 'd' || input == 'D' || input == 100)
	{
		return InputBtn::RIGHT;
	}
	if (input == 'w' || input == 'W' || input == 72)
	{
		return InputBtn::UP;
	}
	if (input == 27)
	{
		return InputBtn::CANCEL;
	}
	if (input == 32 || input == 13)
	{
		return InputBtn::CONFIRM;
	}
	return InputBtn::NOTHING;
}