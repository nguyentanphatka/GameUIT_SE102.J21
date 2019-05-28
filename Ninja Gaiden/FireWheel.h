#pragma once
#include "Weapon.h"

class FireWheel : public Weapon
{
public:
	FireWheel()
	{
		animation = new Animation(WEAPON, 7, 10, DEFAULT_FPS >> 4);
		width = FIREWHEEL_WIDTH;
		height = FIREWHEEL_HEIGHT;
		vx = FIREWHEEL_SPEED;
		vy = 0;
		type = FIREWHEEL;
	}

	void UpdateDistance(float dt)
	{
		this->dx = vx * dt;
		this->dy = 0.75 * dx * dx;
	}
};