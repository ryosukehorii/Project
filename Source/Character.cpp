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
	
	anim_ctr.Init();
}

void Character::Update()
{
	anim_ctr.Update();
	action_state_ctr.Update(this);
}

void  Character::End()
{
	anim_ctr.End();
}

void Character::Draw()
{
	anim_ctr.Draw(pos, move_ctr.GetAngle());
}
