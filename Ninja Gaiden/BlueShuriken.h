#pragma once
#include "Weapon.h"

class BlueShuriken : public Weapon
{
public:
	BlueShuriken();
	~BlueShuriken();
	void Update(float dt, std::unordered_set<Object*> ColliableObjects);
};