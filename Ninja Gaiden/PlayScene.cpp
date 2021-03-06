﻿#include "PlayScene.h"

PlayScene::PlayScene()
{
	map = MapFactory::GetInstance()->GetMap(0);
	grid = new Grid(map->rect);
	grid->LoadObjects();

	player->spawnX = player->posX = 50;
	player->spawnY = player->posY = 100;
	player->ChangeState(new PlayerStandingState());

	camera->x = 0;
	camera->y = SCREEN_HEIGHT;
}

PlayScene::~PlayScene()
{
}

// Update các thông số các đối tượng trong Scene
void PlayScene::Update(float dt)
{
	this->UpdateScene();
	this->UpdateObjects(dt);
	this->UpdatePlayer(dt);

}

void PlayScene::UpdateScene()
{
	camera->x = player->posX - (camera->width >> 1);
	map->Update();
	grid->Update();
}

void PlayScene::UpdateVisibleObjects()
{
	auto it = visibleObjects.begin();
	while (it != visibleObjects.end())
	{
		if ((*it)->tag != WEAPON)
		{
			it = visibleObjects.erase(it);
		}
		else ++it;
	}

	for (auto o : grid->GetVisibleObjects())
	{
		visibleObjects.insert(o);
	}
}

void PlayScene::UpdateObjects(float dt)
{
	this->UpdateVisibleObjects();

	auto it = visibleObjects.begin();
	while (it != visibleObjects.end())
	{
		auto o = *it;
		switch (o->tag)
		{
		case ENEMY:
		{
			EnemyFactory::ConvertToEnemy(o)->Update(dt);
			grid->UpdateObject(o, o->posX + o->dx, o->posY + o->dy);
			break;
		}
		case WEAPON:
		{
			auto w = WeaponLoader::ConvertToWeapon(o);

			if (w->isDead || !w->IsCollide(camera->GetRect())
				|| (w->type == SWORD && player->stateName != ATTACKING_STAND
					&& player->stateName != ATTACKING_SIT))
			{
				player->allow[THROWING] = true;
				it = visibleObjects.erase(it);
				delete w;
				continue;
			}

			w->Update(dt, grid->GetColliableObjects(w));
			break;
		}
		}
		++it;
	}
}

void PlayScene::UpdatePlayer(float dt)
{
	auto p = player;

	p->Update(dt, grid->GetColliableObjects(p));
	p->CheckGroundCollision(grid->GetVisibleGrounds());
	p->CheckWallCollision(grid->GetVisibleWalls());

	p->posX += p->dx;
	p->posY += p->dy;

	if (p->GetRect().y < 0)
	{
		grid->RestartGame();
		p->posX = p->spawnX;
		p->posY = p->spawnY;
	}

	if (p->isAttacking && p->curAnimation->CurFrameIndex == 1)
	{
		Weapon* weapon = WeaponLoader::CreateWeapon(SWORD);
		weapon->isReverse = p->isReverse;
		weapon->posX = p->posX + (p->isReverse ? -22 : 22);
		weapon->posY = p->posY + 8;
		visibleObjects.insert(weapon);
		p->isAttacking = false;
	}

	else if (p->isThrowing)
	{
		Weapon* weapon = WeaponLoader::CreateWeapon(p->weaponType);
		weapon->posX = p->posX + (p->isReverse ? -5 : 5);
		weapon->posY = p->posY + 5;
		weapon->isReverse = p->isReverse;
		if (p->isReverse) weapon->vx = -weapon->vx;
		visibleObjects.insert(weapon);
		p->isThrowing = false;
	}
}

// Tải Scene lên màn hình bằng cách vẽ object có trong trong Scene
void PlayScene::Render()
{
	map->Render();

	for (auto o : visibleObjects)
	{
		o->Render();
	}

	player->Render();
}

// Xử lí Scene khi nhấn phím
void PlayScene::OnKeyDown(int key)
{
	keyCode[key] = true;
	player->OnKeyDown(key);
}

// Xử lí Scene khi thả phím
void PlayScene::OnKeyUp(int key)
{
	keyCode[key] = false;
	player->OnKeyUp(key);
}