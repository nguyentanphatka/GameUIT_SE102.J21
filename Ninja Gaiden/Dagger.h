#pragma once
#pragma once
#include "Weapon.h"


class Dagger : public Weapon
{
private:
	Sprite* sprite;

public:
	Dagger();
	~Dagger();
	void Update(float dt, int maxHight, int leftScreen, int rightScreen);
	void Render(float translateX = 0, float translateY = 0);
};