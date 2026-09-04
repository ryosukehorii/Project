#pragma once

#include "Dxlib.h"
class MoveController;

class KeyBord
{
public:
	void Init();
	void Update();
	void End();
	unsigned char GetKey() const { return key; };
	unsigned char GetTriggerKey()const;

private:
	unsigned char key{ 0x00 };
	unsigned char prev_key{ 0xff };

	bool trigger_key{ false };
	void KeyCheck(unsigned char key);
};