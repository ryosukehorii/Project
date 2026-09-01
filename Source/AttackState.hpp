#pragma once

#include "PlayerState.hpp"

class AttackState : public PlayerState
{
	void Enter(Character* owner)override;
	void Update(Character* owner)override;
	void Exit(Character* owner)override;
};

