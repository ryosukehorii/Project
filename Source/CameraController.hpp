#pragma once

#include "Dxlib.h"

class CameraController
{
public:
	void Init();
	void Update();
	void End();
	void SetCamera();
private:
	float angle_y;


};

