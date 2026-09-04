#pragma once
#include "KeyBord.hpp"
#include "MoveController.hpp"

void KeyBord::Init()
{
	key = 0x00;
	prev_key = 0xff;
	trigger_key = false;
}

void KeyBord::Update()
{
	unsigned char bit = 0x00;

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
	//çUåÇ
	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
	{
		bit |= 0x80;
	}
	//ÉKÅ[Éh
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
	{
		bit |= 0x40;
	}
	//âÒî
	if (CheckHitKey(KEY_INPUT_LCONTROL) == 1)
	{
		bit |= 0x20;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) == 1)
	{
		bit |= 0x10;
	}
	key = bit;
	prev_key = key;
}

void KeyBord::End()
{
}

unsigned char KeyBord::GetTriggerKey() const
{
	unsigned char trigger;

	trigger = key & ~prev_key;

	return trigger;
}