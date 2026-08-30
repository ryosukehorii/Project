#pragma once

#include "Dxlib.h"
class MoveController;

class KeyBord
{
public:
	void Init();
	void Update();
	void End();
	char GetKey() const { return key; };
private:
	char key;
	void KeyCheck(char key);
};