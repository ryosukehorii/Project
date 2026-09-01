#pragma once

#include <memory>
#include "Dxlib.h"

#include "MoveController.hpp"
#include "RotationController.hpp"
#include "AnimationController.hpp"
#include "ActionStateController.hpp"

#define OFFSET_Y (250.0f)

using namespace std;
class KeyBord;
class CameraController;

class Character
{
public:
	void Init();
	void Update();
	void End();
	void SetBind(const KeyBord& key,const CameraController& camera)
	{
		key_ptr = &key;
		camera_ptr = &camera;
	}
	void Draw();

	VECTOR GetMyPos() const { return pos; };
	float GetOffSetY() const { return offset_y; };
	AnimationController GetAnimCtr() { return anim_ctr; };
	MoveController GetMoveCtr() { return move_ctr; };

	const KeyBord* GetKeyPtr() { return key_ptr; };
	const CameraController* GetCamePtr() { return camera_ptr; };

private:
	void CheckMotion();
	int anim_motion{0};
	int current_motion{0};
	int prev_motion{ -1 };

	VECTOR pos{0,0,0};
	MoveController move_ctr;
	RotationController rot_ctr;
	ActionStateController action_state_ctr;
	AnimationController anim_ctr;

	const KeyBord* key_ptr{ NULL };
	const CameraController* camera_ptr{NULL};
	float offset_y{ OFFSET_Y };

};

