#pragma once

#include "PlayerState.hpp"

class RunState : public PlayerState
{
public:
	void Enter(Character* owner)override;
	void Update(Character* owner)override;
	void Exit(Character* owner)override;
};

