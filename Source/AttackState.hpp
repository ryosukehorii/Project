#pragma once

#include "PlayerState.hpp"

class AttackState : public PlayerState
{
public:
	void Enter(Character* owner)override;
	void Update(Character* owner)override;
	void Exit(Character* owner)override;
private:
	void CheckComboInput(Character* owner);
	bool can_next_combo{false};
};

