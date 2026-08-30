#pragma once

#include <memory>
#include "Dxlib.h"

#include "MoveController.hpp"
#include "RotationController.hpp"

#define OFFSET_Y (250.0f)

using namespace std;
class KeyBord;
class AnimationController;
class CameraController;

class Character
{
public:
	void Init();
	void Update();
	void End();
	void SetBind(AnimationController& anim, const KeyBord& key,const CameraController& camera)
	{
		anim_ptr = &anim;
		key_ptr = &key;
		camera_ptr = &camera;
	}
	void Draw();
	VECTOR GetMyPos() { return pos; };
	float GetOffSetY() { return offset_y; };

private:
	void CheckMotion();
	int anim_motion{0};
	int current_motion{-1};
	VECTOR pos{0,0,0};
	MoveController move_ctr;
	RotationController rot_ctr;
	AnimationController* anim_ptr{NULL};
	const KeyBord* key_ptr{ NULL };
	const CameraController* camera_ptr{NULL};
	float offset_y{ OFFSET_Y };
};

