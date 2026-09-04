#include "RoolState.hpp"
#include "AttackState.hpp"
#include "Character.hpp"
#include "KeyBord.hpp"
#include "CameraController.hpp"
#include "MoveController.hpp"


void RoolState::Enter(Character* owner)
{
	owner->GetAnimCtr().ChangeAnim(MOTION_ROLL);
}

void RoolState::Update(Character* owner)
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
	//移動
	if (owner->GetKeyPtr()->GetKey() & 0x01)
	{
		owner->GetActionCtr().ChangeState(
			owner->GetActionCtr().GetRunState(),
			owner
		);
	}
	//移動ボタン
	if (owner->GetKeyPtr()->GetKey() & 0x00)
	{
		owner->GetActionCtr().ChangeState(
			owner->GetActionCtr().GetIdleState(),
			owner
		);
	}
}

void RoolState::Exit(Character* owner)
{
}
