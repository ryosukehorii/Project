#include "Character.hpp"
#include "KeyBord.hpp"
#include "AnimationController.hpp"

#define OFFSETSPEED (1.0f)

void Character::Init()
{
	anim_motion = 0;
	current_motion = -1;
	move_ctr.Init();
	rot_ctr.Init();
}

void Character::Update()
{
	anim_motion = key_ptr->GetKey();
	if (anim_motion != current_motion)
	{
		current_motion = anim_motion;
		anim_ptr->ChangeAnim(current_motion);
	}
	move_ctr.Update(current_motion,OFFSETSPEED);
	rot_ctr.Update(move_ctr.GetPos());
}

void  Character::End()
{
	anim_ptr->End();
}

void Character::Draw()
{
	anim_ptr->Draw(move_ctr.GetPos(), rot_ctr.GetAngle());
}