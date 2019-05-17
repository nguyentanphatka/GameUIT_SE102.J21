#include "Animation.h"

void Animation::Render(float x, float y, float translateX, float translateY)
{
	_sprites[CurFrameIndex]->isReverse = this->isReverse;
	_sprites[CurFrameIndex]->Render(x, y, translateX, translateY);
}

void Animation::Update(float dt)
{
	if (_curFrameTime > _timePerFrame)
	{
		_curFrameTime = 0;
		
		if (++CurFrameIndex == _totalFrames)
		{
			isLastFrame = true;
			CurFrameIndex = 0;
		}
	}
	else
	{
		isLastFrame = false;
		_curFrameTime += dt;
	}
}

Animation::Animation(Tag tag, int index)
{
	_sprites.push_back(SpriteLoader::GetInstance()->GetSprite(tag, index));
	_totalFrames = 1;
	_timePerFrame = DEFAULT_TPS;
	CurFrameIndex = 0;
	isLastFrame = false;
}

Animation::Animation(Tag tag, int firstIndex, int lastIndex, int timePerFrame)
{
	_sprites = SpriteLoader::GetInstance()->GetSprites(tag, firstIndex, lastIndex);
	_totalFrames = _sprites.size();
	_timePerFrame = timePerFrame;
	CurFrameIndex = 0;
	isLastFrame = false;
}
Animation::Animation()
{

}
Sprite * Animation::GetSprite(int i)
{
	return _sprites[i];
}