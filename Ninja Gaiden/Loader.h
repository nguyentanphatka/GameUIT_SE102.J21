#pragma once
#include "EnemyFactory.h"
#include <string>
#include <fstream>
#include <vector>

class Loader
{
public:
	Loader() {};
	~Loader() {};
	std::vector<Enemy*> LoadEnemies();
	std::vector<Rect*> LoadWallsBound();
	std::vector<Rect*> LoadGroundsBound();
};