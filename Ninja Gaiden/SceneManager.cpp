#include "SceneManager.h"

SceneManager* SceneManager::_instance = NULL;

SceneManager::SceneManager()
{
	_curScene = nullptr;
}

void SceneManager::ReplaceScene(Scene * scene)
{
	delete _curScene;
	_curScene = scene;
}

Scene * SceneManager::GetCurScene()
{
	return _curScene;
}

// Get Instance (Singleton Pattern)
SceneManager * SceneManager::GetInstance()
{
	if (_instance == NULL)
		_instance = new SceneManager();
	return _instance;
}