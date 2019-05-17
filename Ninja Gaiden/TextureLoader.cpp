#include "TextureLoader.h"

TextureLoader* TextureLoader::_instance = NULL;
//load all texture
void TextureLoader::LoadResources()
{
	TextureLoader::GetInstance()->AddTexture(PLAYER, "Resources\\player.png");
	TextureLoader::GetInstance()->AddTexture(ITEM, "Resources\\item.png");
	TextureLoader::GetInstance()->AddTexture(MAP3_1, "Resources\\tiles1.png");
	TextureLoader::GetInstance()->AddTexture(ENEMY, "Resources\\Enemy.png");
	TextureLoader::GetInstance()->AddTexture(HOLDER, "Resources\\Holder&Item.png");
}

void TextureLoader::AddTexture(Tag tag, const char * filePath)
{
	_textures[tag] = (new Texture(filePath))->GetTexture();
}

TextureLoader* TextureLoader::GetInstance()
{
	if (_instance == NULL)
		_instance = new TextureLoader();
	return _instance;
}

LPDIRECT3DTEXTURE9 TextureLoader::GetTexture(Tag tag)
{
	return _textures[tag];
}