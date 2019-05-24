#include "SwingWord.h"

SwingSword::SwingSword()
{
	animation = new Animation(WEAPON, 5, 8);
	isOnScreen = false;
	width = SWINGSWORD_WIDTH;
	height = SWINGSWORD_HEIGHT;
	type = SWINGSWORD;
}

void SwingSword::Update(float dt)
{
}

void SwingSword::Render(float x, float y, int frameIndex, float translateX, float translateY)
{
	if (!isOnScreen) return;

	Sprite* sprite = animation->GetSprite(frameIndex);
	sprite->isReverse = this->isReverse;

	switch (frameIndex)
	{
	case 0:
		sprite->Render(x, y, translateX + (isReverse ? -10 : 10), translateY - 6);
		break;

	case 1:
		sprite->Render(x, y, translateX + (isReverse ? -3 : 3), translateY + 10);
		break;

	case 2:
		sprite->Render(x, y, translateX + (isReverse ? 10 : -10), translateY - 4);
		break;

	case 3:
		sprite->Render(x, y, translateX + (isReverse ? 2 : -2), translateY - 10);
		break;
	}
}