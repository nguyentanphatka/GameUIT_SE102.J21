#pragma once
#include "GameGlobal.h"
#include <unordered_map>

class Texture
{
public:
	LPDIRECT3DTEXTURE9 _texture;
	Texture(const char* filePath);
	~Texture();
	LPDIRECT3DTEXTURE9 GetTexture();
};