#include "BlueShuriken.h"


BlueShuriken::BlueShuriken()
{
	animation = new Animation(WEAPON, 5, 6);
	isOnScreen = false;
	width = BLUESHURIKEN_WIDTH;
	height = BLUESHURIKEN_HEIGHT;
	vx = BLUESHURIKEN_SPEED;
	vy = 0;
	type = BLUESHURIKEN;
}

BlueShuriken::~BlueShuriken()
{
}

void BlueShuriken::Update(float dt, std::unordered_set<Object*> ColliableObjects)
{
	Object::Update(dt);
	animation->Update(dt);

	for (auto obj : ColliableObjects)
	{
		if (this->GetRect().IsContain(obj->GetRect()))
		{
			if (obj->tag == ENEMY)
			{
				auto e = (Enemy*)obj;
				e->ChangeState(DEAD);
				this->isDead = true;
				break;
			}

			else if (obj->tag == HOLDER)
			{
				/*auto h = (Holder*)obj;
				h->isDead = true;
				this->isDead = true;*/
				break;
			}
		}
	}
}
