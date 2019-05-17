#include "PlayerDeadState.h"

PlayerDeadState::PlayerDeadState()
{
	player->vx = 0;
	player->vy = 0;
	player->allow[ATTACKING] = false;
	player->allow[CLINGING] = false;

}

State PlayerDeadState::GetName()
{
	return DEAD;
}
