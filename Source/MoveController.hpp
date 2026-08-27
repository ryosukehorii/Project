#pragma once
#include "Dxlib.h"
typedef enum
{
	Idle,
    Front,
    Left,
    Back,
    Right
	
}Dir;

class MoveController
{
public:
	void Init();
	void Update(int key, float speed);
	void End();
	VECTOR GetPos() { return pos; };
private:
	VECTOR pos{0,0,0};
};

