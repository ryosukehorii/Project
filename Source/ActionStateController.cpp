// ActionStateController.cpp
#include "ActionStateController.hpp"
#include "IdleState.hpp"
#include "RunState.hpp"
#include "AttackState.hpp"

void ActionStateController::Init()
{
	// ここで各 State を生成！
	idle_state = std::make_unique<IdleState>();
	run_state = std::make_unique<RunState>();
	attack_state = std::make_unique<AttackState>();

	current_state = idle_state.get();
}

void ActionStateController::ChangeState(PlayerState* next_state, Character* owner)
{
	if (!next_state) return;
	if (current_state) current_state->Exit(owner);

	current_state = next_state;
	current_state->Enter(owner);
}

void ActionStateController::Update(Character* owner)
{
	if (current_state)
	{
		// 現在のステートを実行するだけ！
		current_state->Update(owner);
	}
}