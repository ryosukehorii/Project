#pragma once
class Character;

class PlayerState
{
public:
	virtual void Enter(Character* owner);
	virtual void Update(Character* owner);
	virtual void Exit(Character* owner);
};

