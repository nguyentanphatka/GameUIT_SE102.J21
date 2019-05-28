#pragma once
#include "BlueShuriken.h"
#include "FireWheel.h"
#include "Sword.h"

class WeaponLoader
{
public:
	static Weapon* CreateWeapon(Type weaponType)
	{
		switch (weaponType)
		{
		case SWORD:
			return new Sword();

		case BLUESHURIKEN:
			return new BlueShuriken();

		case FIREWHEEL:
			return new FireWheel();

		default:
			return NULL;
		}
	}

	static Weapon* ConvertToWeapon(Object* obj)
	{
		Weapon* w = (Weapon*)obj;

		switch (w->type)
		{
		case SWORD:
			w = (Sword*)w;
			break;

		case BLUESHURIKEN:
			w = (BlueShuriken*)w;
			break;

		case FIREWHEEL:
			w = (FireWheel*)w;
			break;
		}

		return w;
	}
};