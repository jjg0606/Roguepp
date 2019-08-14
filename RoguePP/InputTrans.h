#pragma once

enum class InputBtn
{
	NOTHING,
	UP,
	DOWN,
	LEFT,
	RIGHT,
	CONFIRM,
	CANCEL
};

class InputTrans
{
public:
	static InputBtn getKey(char input);
};