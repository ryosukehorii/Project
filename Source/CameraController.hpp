#pragma once

#include "Dxlib.h"

class CameraController
{
public:
	void Init();
	void Update();
	void End();
	void SetCamera(VECTOR target_pos, float offset_y);
	float GetAngle_y() const { return angle_y; };
private:
	float angle_y;
	VECTOR camera_pos{0,0,0};

};

