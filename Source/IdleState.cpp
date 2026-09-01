#include "IdleState.hpp"
#include "Character.hpp"

void IdleState::Enter(Character* owner)
{
	owner->GetAnimCtr().ChangeAnim(MOTION_IDLE);
}

void IdleState::Update(Character* owner)
{
}

void IdleState::Exit(Character* owner)
{
}