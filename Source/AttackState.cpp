#include "AttackState.hpp"
#include "RunState.hpp"
#include "Character.hpp"
#include "KeyBord.hpp"
#include "CameraController.hpp"
#include "MoveController.hpp"


void AttackState::Enter(Character* owner)
{
	owner->GetAnimCtr().ChangeAnim(MOTION_ATTACK);
}

void AttackState::Update(Character* owner)
{
	// 回避ボタン
	if (owner->GetKeyPtr()->GetTriggerKey() & 0x40)
	{
		owner->GetActionCtr().ChangeState(
			owner->GetActionCtr().GetRollState(),
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

void AttackState::Exit(Character* owner)
{
}

void AttackState::CheckComboInput(Character* owner)
{
	float progress = owner->GetAnimCtr().GetPlayRate(); // 再生率（0.0〜1.0）

	// 受付時間内（ 50%〜90%再生時）の入力
	if (progress >= 0.5f && progress <= 0.9f)
	{
		if (owner->GetKeyPtr()->GetTriggerKey() & 0x80)
		{
			can_next_combo = true;
		}
	}
}