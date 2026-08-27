#pragma once

#include "Dxlib.h"

class KeyBord
{
public:
	void Init();
	void Update();
	void End();
	int GetKey() const { return key; };
private:
	int key;
};