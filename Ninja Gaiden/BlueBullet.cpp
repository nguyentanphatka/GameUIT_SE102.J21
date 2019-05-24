#include "BlueBullet.h"

BlueBullet::BlueBullet()
{
	sprite = SpriteLoader::GetInstance()->GetSprite(ENEMY, 11);
	type = BULLET;
	this->height = BULLET_HEIGHT;
	this->width = BULLET_WIDTH;
	this->isOnScreen = false;
}

BlueBullet::~BlueBullet()
{
}

void BlueBullet::Update(float dt, int leftScreen, int rightScreen)
{
	if (isOnScreen)
	{
		posX += vx * dt;
		if (posX > rightScreen || posX < leftScreen)
			isOnScreen = false;
	}
}

void BlueBullet::Render(float translateX, float translateY)
{
	if (isOnScreen)
	{
		auto posX = this->posX + translateX;
		auto posY = this->posY + translateY;
		camera->ConvertPositionToViewPort(posX, posY);
		sprite->isReverse = this->isReverse;
		sprite->Render(posX, posY, translateX, translateY);
	}
}

