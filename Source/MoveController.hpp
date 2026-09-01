#pragma once
#include "Dxlib.h"
typedef enum
{
    FRONT = 0x01,                         // 0000 0001
    LEFT = 0x02,                         // 0000 0010
    BACK = 0x04,                         // 0000 0100
    RIGHT = 0x08,                         // 0000 1000

    F_LEFT = FRONT | LEFT,   // 0x03       // 0000 0011 (ëO Å{ ç∂)
    F_RIGHT = FRONT | RIGHT,  // 0x09       // 0000 1001 (ëO Å{ âE)
    B_LEFT = BACK | LEFT,   // 0x06       // 0000 0110 (å„ Å{ ç∂)
    B_RIGHT = BACK | RIGHT   // 0x0C       // 0000 1100 (å„ Å{ âE)
} Dir;

class MoveController
{
public:
	void Init();
	void Update(unsigned char key, float camera_angle_y);
	void End();
	VECTOR GetPos() { return pos; };
	float GetAngle() { return angle; };
private:
	VECTOR pos{0,0,0};
	float angle{0};
};

