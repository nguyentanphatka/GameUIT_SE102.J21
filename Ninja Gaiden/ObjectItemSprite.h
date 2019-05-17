﻿#pragma once
#include "Sprite.h"

class ObjectItemSprite : public Sprite
{
public:
	Type type;
	ObjectItemSprite(Type type, int left, int top, int right, int bottom)
	{
		tag = ITEM;
		_texture = TextureLoader::GetInstance()->GetTexture(ITEM);
		_rect.top = top;
		_rect.left = left;
		_rect.right = right;
		_rect.bottom = bottom;
		_center = D3DXVECTOR3((right - left) >> 1, (bottom - top) >> 1, 0);
	}
};