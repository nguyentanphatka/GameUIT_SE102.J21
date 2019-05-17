#include "Scene.h"

Scene::Scene()
{
	TextureLoader::GetInstance()->LoadResources();
	SpriteLoader::GetInstance()->LoadResources();
	MapFactory::GetInstance()->LoadResources();
}