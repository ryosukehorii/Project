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
	void Update(int key, float camera_angle_y);
	void End();
	VECTOR GetPos() { return pos; };
	float GetAngle() { return angle; };
private:
	VECTOR pos{0,0,0};
	float angle{0};
};

