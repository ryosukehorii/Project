#pragma once

#include <memory>
#include "Dxlib.h"

#include "MoveController.hpp"
#include "RotationController.hpp"

using namespace std;
class KeyBord;
class AnimationController;

class Character
{
public:
	void Init();
	void Update();
	void End();
	void SetBind(AnimationController& anim, const KeyBord& key)
	{
		anim_ptr = &anim;
		key_ptr = &key;
	}
	void Draw();
private:
	int anim_motion{0};
	int current_motion{-1};
	VECTOR pos{0,0,0};
	MoveController move_ctr;
	RotationController rot_ctr;
	AnimationController* anim_ptr{NULL};
	const KeyBord* key_ptr{ NULL };
};

