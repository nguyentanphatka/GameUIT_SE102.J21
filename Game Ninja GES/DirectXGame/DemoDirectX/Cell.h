#pragma once
#include "Object.h"
#include <unordered_set>
#include "GameComponents/GameGlobal.h"
class Cell
{
private:
	int xID, yID;

public:
	Rect rect;
	static int width, height;
	std::unordered_set<Object*> objects;
	std::vector<Rect> walls;
	std::vector<Rect> grounds;

	Cell(int xID, int yID);
	bool IsContain(Rect r);
	void RemoveObject(Object* obj);
};