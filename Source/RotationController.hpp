#pragma once
#include "Dxlib.h"

class RotationController
{
public:
	void Init();
	void Update(VECTOR char_pos);
	void End();
	float GetAngle() { return angle_y; };
private:
	float angle_y{0.0f};
};

