#pragma once
#include "Weapon.h"
class BlueBullet : public Weapon
{
	Sprite* sprite;

public:
	BlueBullet();
	~BlueBullet();

	void Update(float dt, int leftScreen, int rightScreen);
	void Render(float translateX = 0, float translateY = 0);
};
