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
private:
	unsigned char key;
	void KeyCheck(unsigned char key);
};