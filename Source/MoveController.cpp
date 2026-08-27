#include "MoveController.hpp"

#define DEFORTSPEED (2.0f)

void MoveController::Init()
{

}

void MoveController::Update(int key,float speed)
{
	switch (key)
	{
		//w
	case Front:
		pos.z += DEFORTSPEED * speed;
		break;
		//a
	case Left:
		pos.x -= DEFORTSPEED * speed;
		break;
		//s
	case Back:
		pos.z -= DEFORTSPEED * speed;
		break;
		//d
	case Right:
		pos.x += DEFORTSPEED * speed;
		break;
	default:
		break;
	}
	// 白の色コードを保存
	unsigned int Cr = GetColor(255, 255, 255);
	DrawFormatString(0, 0, Cr, "posx %f posz %f ", pos.x, pos.z);
}

void MoveController::End()
{

}