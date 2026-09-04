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

	// 攻撃ボタン
	if (owner->GetKeyPtr()->GetTriggerKey() & 0x80)
	{
		owner->GetActionCtr().ChangeState(
			owner->GetActionCtr().GetAttackState(),
			owner
		);
		return;
	}

	// 回避ボタン
	if (owner->GetKeyPtr()->GetTriggerKey() & 0x40)
	{
		owner->GetActionCtr().ChangeState(
			owner->GetActionCtr().GetRollState(),
			owner
		);
		return;
	}

	//Idle
	if (owner->GetKeyPtr()->GetKey() == 0x00)
	{
		owner->GetActionCtr().ChangeState(
			owner->GetActionCtr().GetIdleState(),
			owner
		);
	}
}

void RunState::Exit(Character* owner)
{

}
