#pragma once
#include "KeyBord.hpp"

void KeyBord ::Init()
{
	key = 0;
}

void KeyBord::Update()
{
	char bit = 0x00;

	if (CheckHitKey(KEY_INPUT_W) == 1)
	{
		bit |= 0x01;
	}
	if (CheckHitKey(KEY_INPUT_A) == 1)
	{
		bit |= 0x02;
	}
	if (CheckHitKey(KEY_INPUT_S) == 1)
	{
		bit |= 0x04;
	}
	if (CheckHitKey(KEY_INPUT_D) == 1)
	{
		bit |= 0x08;
	}
}

void KeyBord::End()
{
}