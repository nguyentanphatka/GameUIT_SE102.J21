﻿#include "Map.h"
#include "Define.h"

const auto ADD_COL = (SCREEN_WIDTH >> 4) + 1;
const auto MOVE_TILE = (TILE_SIZE >> 1);

Map::Map(int level)
{
	std::ifstream ifile;
	char fileName[30];
	int numSetTiles;

	sprintf_s(fileName, "Resources\\matrix1.txt", level + 1);
	mapLevel = MAP3_1;
	ifile.open(fileName);

	// cột và chiều dài, rộng của Map tương ứng
	ifile >> numSetTiles;
	ifile >> columns;
	ifile >> rows;
	width = columns << 4;
	height = rows << 4;

	rect.width = width;
	rect.height = height;
	rect.x = 0;
	rect.y = rect.height;

	// lấy danh sách tất cả các sprite của map
	for (int i = 0; i < numSetTiles; ++i)
	{
		SpriteLoader::GetInstance()->AddSprite(new Sprite(mapLevel, i << 4, 0, i + 1 << 4, 16));
	}

	// Tạo ma trận tương ứng của Map
	mapTiles = new int* [rows];
	for (int r = 0; r < rows; ++r)
	{
		mapTiles[r] = new int[columns];
		for (int c = 0; c < columns; ++c)
		{
			ifile >> mapTiles[r][c];
		}
	}
	ifile.close();
}

void Map::Update()
{
	camera->Update(this->rect);
	cBegin = max(0, camera->x / 16);
	cEnd = min(cBegin + ADD_COL, columns);
}

void Map::Render()
{
	for (auto r = 0; r != rows; ++r)
	{
		for (auto c = cBegin; c != cEnd; ++c)
		{
			auto sprite = SpriteLoader::GetInstance()->GetSprite(mapLevel, mapTiles[r][c]);
			sprite->Render((c << 4) + MOVE_TILE - (int)camera->x, (r << 4) + MOVE_TILE);
		}
	}
}