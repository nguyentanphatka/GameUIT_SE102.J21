#pragma once
#include "TextureLoader.h"
#include "SpriteLoader.h"
#include "MapLoader.h"

class Scene
{
public:
	Scene();
	virtual void LoadResources() {};		
	virtual void Update(float dt) {};	
	virtual void Render() {};					
	virtual void OnKeyDown(int keyCode) {};		
	virtual void OnKeyUp(int keyCode) {};	
};