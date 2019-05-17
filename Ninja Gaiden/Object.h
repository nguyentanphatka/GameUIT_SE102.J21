#pragma once
#include "GameGlobal.h"
#include "SpriteLoader.h"
#include "Animation.h"
#include "Collision.h"
#include "Camera.h"

class Object
{
public:
	Object() {}
	~Object() {}

	Tag tag;									
	float spawnX, spawnY;
	float posX, posY;							//tâm của object
	float vx, vy;								
	float dx, dy;
	int width, height;			
	bool isReverse;								// Kiểm tra flipping

	Rect GetRect();
	BoundingBox GetBoundingBox();

	void Update(float dt);
	bool IsCollide(Rect r);
	virtual void Render(float translateX = 0, float translateY = 0) {}
};