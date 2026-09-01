#pragma once
#include "PlayerState.hpp"

#define MOTION_IDLE (0)

class IdleState : public PlayerState
{
public:
	void Enter(Character* owner)override;
	void Update(Character* owner)override;
	void Exit(Character* owner)override;
};

