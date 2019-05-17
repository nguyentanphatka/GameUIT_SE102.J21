#pragma once
#include "Player.h"
#include "PlayerState.h"

class PlayerDeadState : public PlayerState
{
	bool _reverse;
public:
	PlayerDeadState();
	void Update(float dt) {};
	void HandleKeyboard() {};
	State GetName();
};