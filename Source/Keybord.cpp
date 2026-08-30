#pragma once
#include "KeyBord.hpp"
#include "MoveController.hpp"

void KeyBord::Init()
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
	KeyCheck(bit);
}

void KeyBord::End()
{
}

void KeyBord::KeyCheck(char bit)
{
	
	if ((bit & 0x01) && (bit & 0x02)) 
	{
		// W + A Å® ç∂è„
		key = FrontLeft;
		
	}
	else if ((bit & 0x01) && (bit & 0x08)) 
	{
		// W + D Å® âEè„
		key = FrontRight;
	}
	else if ((bit & 0x04) && (bit & 0x02)) 
	{
		// S + A Å® ç∂â∫
		key = BackLeft;
	}
	else if ((bit & 0x04) && (bit & 0x08)) 
	{
		// S + D Å® âEâ∫
		key = BackRight;
	}
	else if (bit & 0x01) 
	{
		key = Front;
	}
	else if (bit & 0x02) 
	{
		key = Left;
	}
	else if (bit & 0x04) 
	{
		key = Back;
	}
	else if (bit & 0x08) 
	{
		key = Right;
	}
	else 
	{
		key = Idle;
	}


	DrawFormatString(0, 100, GetColor(255, 0, 0), "model %d", key);
}