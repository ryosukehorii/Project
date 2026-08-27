#pragma once
#include "KeyBord.hpp"

void KeyBord ::Init()
{
	key = 0;
}

void KeyBord::Update()
{
	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		key = 1;
		printf("W");
	}
	else if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		key = 2;
		printf("A");
	}
	else if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		key = 3;
		printf("S");
	}
	else if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		key = 4;
		printf("D");
	}
	else
	{
		key = 0;
	}
}

void KeyBord::End()
{
}