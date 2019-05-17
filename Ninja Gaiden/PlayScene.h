#pragma once
#include "Scene.h"
#include "Player.h"
#include <map>
#include "Grid.h"
#include "Loader.h"

class PlayScene : public Scene
{
private:
	//cấu tạo nên scene cố định có map-grig - danh sách các object
	Map* map;
	Grid* grid;
	std::unordered_set<Object*> visibleObjects;

public:
	PlayScene();
	~PlayScene();
	void InitCellsInGrid();

	void Update(float dt);
	void UpdateScene();						
	void UpdateObjects(float dt);
	void UpdatePlayer(float dt);

	void Render();									
	void OnKeyDown(int key);						// Xử lí Scene khi nhấn phím
	void OnKeyUp(int key);							// Xử lí Scene khi thả phím
};