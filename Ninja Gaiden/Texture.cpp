
#include "Texture.h"



Texture::Texture(const char* filePath)
{
	D3DXIMAGE_INFO imageInfo;
	D3DXGetImageInfoFromFile(filePath, &imageInfo);
	D3DXCreateTextureFromFileEx(d3ddev, filePath, imageInfo.Width, imageInfo.Height, 1, D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_DEFAULT, D3DX_DEFAULT, NULL, &imageInfo, NULL, &_texture);
}

Texture::~Texture()
{
_texture->Release();
}

LPDIRECT3DTEXTURE9 Texture::GetTexture()
{
	return _texture;
}
