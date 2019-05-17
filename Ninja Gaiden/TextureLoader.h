#pragma once
#include "GameGlobal.h"
#include <unordered_map>
#include "Texture.h"

class TextureLoader
{
private:
	static TextureLoader* _instance;
	std::unordered_map<Tag, LPDIRECT3DTEXTURE9> _textures;

public:
	void LoadResources();
	void AddTexture(Tag tag, const char* filePath);
	static TextureLoader* GetInstance();
	LPDIRECT3DTEXTURE9 GetTexture(Tag tag);
};