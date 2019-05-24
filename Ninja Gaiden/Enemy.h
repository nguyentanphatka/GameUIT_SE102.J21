#pragma once
#include "Object.h"
#include "EnemySprite.h"
#include "Cell.h"
#include <algorithm>

class Enemy : public Object
{
protected:
	Animation* curAnimation;
	std::unordered_map<State, Animation*> animations;

public:
	Enemy() 
	{ 
		tag = ENEMY; 
		isActive = false;
	}
	
	~Enemy() {};
	Type type;
	bool isActive;
	bool isDead;
	State StateName;
	void Render()
	{
		curAnimation->isReverse = this->isReverse;
		curAnimation->Render(posX, posY);
	}

	void Render(float translateX = 0, float translateY = 0)
	{
		auto posX = this->posX + translateX;
		auto posY = this->posY + translateY;

		camera->ConvertPositionToViewPort(posX, posY);
		curAnimation->isReverse = this->isReverse;
		curAnimation->Render(posX, posY);
	}

	virtual void Update(float dt)
	{
		curAnimation->Update(dt);
		dx = vx * dt;
		dy = vy * dt;
	}

	bool IsRespawnOnScreen()
	{
		return Rect(spawnX - (width >> 1), spawnY - (height >> 1), width, height).IsContain(camera->GetRect());
	}


	void ChangeState(State StateName)
	{
		switch (StateName)
		{
		case DEAD:
		{
			break;
		}
		default:
		{
			this->isActive = true;
			this->isDead = false;
			break;
		}
		}
		this->StateName = StateName;
		this->curAnimation = animations[StateName];
	}
};