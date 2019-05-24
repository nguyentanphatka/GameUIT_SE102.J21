#pragma once
#include "Weapon.h"

class SwingSword : public Weapon
{
public:
	SwingSword();
	void Update(float dt);
	void Render(float x, float y, int frameIndex, float translateX, float translateY);
};