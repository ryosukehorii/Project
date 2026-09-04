#pragma once

#define MOTION_IDLE (0)
#define MOTION_RUN (1)
#define MOTION_ATTACK (2)
#define MOTION_ROLL (3)

class Character;

class PlayerState
{
public:
	virtual void Enter(Character* owner) {};
	virtual void Update(Character* owner) = 0;
	virtual void Exit(Character* owner) {};
};

