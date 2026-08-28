#include "Character.hpp"
#include "KeyBord.hpp"
#include "AnimationController.hpp"
#include "CameraController.hpp"

#define OFFSETSPEED (1.0f)

void Character::Init()
{
	anim_motion = 0;
	current_motion = -1;
	move_ctr.Init();
	//rot_ctr.Init();
}

void Character::Update()
{
	anim_motion = key_ptr->GetKey();
	if (anim_motion != current_motion)
	{
		current_motion = anim_motion;
		if (current_motion != Idle)
		{
			anim_ptr->ChangeAnim(1);
		}
		else
		{
			anim_ptr->ChangeAnim(0);
		}
	}
	move_ctr.Update(current_motion, camera_ptr->GetAngle_y());
	pos = move_ctr.GetPos();
}

void  Character::End()
{
	anim_ptr->End();
}

void Character::Draw()
{
	anim_ptr->Draw(pos, move_ctr.GetAngle());
}