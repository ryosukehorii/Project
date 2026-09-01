#include "RunState.hpp"
#include "Character.hpp"
#include "KeyBord.hpp"
#include "CameraController.hpp"
#include "MoveController.hpp"

void RunState::Enter(Character* owner)
{
	owner->GetAnimCtr().ChangeAnim(MOTION_RUN);
}

void RunState::Update(Character* owner)
{
	owner->GetMoveCtr().Update
	(
		owner->GetKeyPtr()->GetKey(),
		owner->GetCamePtr()->GetAngle_y()
	);
}

void RunState::Exit(Character* owner)
{

}
