// ActionStateController.hpp
#include <memory>
#include "PlayerState.hpp"

class Character; // 前方宣言

class ActionStateController
{

public:
	void Init();
	void Update(Character* owner);
	void ChangeState(PlayerState* next_state, Character* owner);

	// 各ステートの取得用
	PlayerState* GetIdleState() { return idle_state.get(); }
	PlayerState* GetRunState() { return run_state.get(); }
	PlayerState* GetAttackState() { return attack_state.get(); }

private:
	// 各ステートのインスタンスを所有
	std::unique_ptr<PlayerState> idle_state;
	std::unique_ptr<PlayerState> run_state;
	std::unique_ptr<PlayerState> attack_state;

	// 現在のステート
	PlayerState* current_state = nullptr;
};