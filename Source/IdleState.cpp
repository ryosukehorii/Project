#include "IdleState.hpp"
#include "Character.hpp"
#include "KeyBord.hpp"
#include "ActionStateController.hpp"

void IdleState::Enter(Character* owner)
{
	owner->GetAnimCtr().ChangeAnim(MOTION_IDLE);
}

void IdleState::Update(Character* owner)
{
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
	//移動ボタン
	if (owner->GetKeyPtr()->GetKey() == 0x01)
	{
		owner->GetActionCtr().ChangeState(
			owner->GetActionCtr().GetRunState(),
			owner
		);
	}
}

void IdleState::Exit(Character* owner)
{
}