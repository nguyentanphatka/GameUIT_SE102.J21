﻿#include "SpriteLoader.h"

SpriteLoader* SpriteLoader::_instance = NULL;

void SpriteLoader::LoadResources()
{
	// ======================== PLAYER SPRITE ===========================s
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(STANDING, 0, 5, 22, 38));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(RUNNING, 338, 5, 360, 38));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(RUNNING, 368, 5, 390, 38));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(RUNNING, 400, 5, 422, 38));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(SITTING, 2, 53, 21, 76));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(JUMPING, 139, 50, 163, 78));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(JUMPING, 165, 50, 189, 78));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(JUMPING, 190, 50, 214, 78));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(JUMPING, 216, 50, 240, 78));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(ATTACKING_STAND, 40, 5, 62, 38));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(ATTACKING_STAND, 66, 5, 93, 38));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(ATTACKING_STAND, 110, 5, 133, 38));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(ATTACKING_SIT, 35, 53, 57, 76));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(ATTACKING_SIT, 58, 53, 82, 76));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(ATTACKING_SIT, 100, 53, 122, 76));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(CLINGING, 264, 5, 288, 38));
	SpriteLoader::GetInstance()->AddSprite(new PlayerSprite(CLIMBING, 286, 5, 310, 38));

	// ======================== Weapon SPRITE ==========================
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(EXPLODED, 357, 10, 374, 30));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(EXPLODED, 365, 40, 397, 78));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(EXPLODED, 318, 0, 350, 40));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(SWORD, 150, 28, 172, 43));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(SWORD, 170, 35, 187, 41));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(BLUESHURIKEN, 175, 95, 185, 105));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(BLUESHURIKEN, 188, 95, 198, 105));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(FIREWHEEL, 5, 80, 40, 115));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(FIREWHEEL, 45, 80, 80, 115));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(FIREWHEEL, 90, 80, 125, 115));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(FIREWHEEL, 130, 80, 165, 115));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(SWINGSWORD, 188, 29, 198, 47));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(SWINGSWORD, 206, 37, 224, 47));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(SWINGSWORD, 228, 29, 241, 47));
	SpriteLoader::GetInstance()->AddSprite(new WeaponSprite(SWINGSWORD, 244, 35, 262, 47));

	// ======================== ENEMY SPRITE ================================

	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(SWORDMAN, 211, 47, 240, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(SWORDMAN, 240, 47, 269, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(SWORDMAN, 278, 47, 307, 90));

	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(BAZOKAMAN, 383, 61, 414, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(BAZOKAMAN, 415, 61, 446, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(BAZOKAMAN, 446, 59, 453, 78));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(BAZOKAMAN, 460, 61, 471, 71));

	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(GUNMAN, 51, 55, 77, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(GUNMAN, 77, 55, 103, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(GUNMAN, 129, 55, 159, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(GUNMAN, 159, 55, 189, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(GUNMAN, 189, 62, 206, 73));

	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(CLOAKMAN, 409, 0, 435, 49));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(CLOAKMAN, 445, 0, 471, 49));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(CLOAKMAN, 487, 0, 515, 49));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(CLOAKMAN, 517, 0, 531, 23));

	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(PANTHER, 309, 74, 342, 90));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(PANTHER, 342, 74, 377, 90));

	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(EAGLE, 471, 54, 497, 92));
	SpriteLoader::GetInstance()->AddSprite(new EnemySprite(EAGLE, 500, 54, 526, 92));

	// =========================== HOLDER SPRITE ========================================	
	/*SpriteLoader::GetInstance()->AddSprite(new HolderSprite(BUTTERFLY, 83, 55, 96, 70));
	SpriteLoader::GetInstance()->AddSprite(new HolderSprite(BUTTERFLY, 96, 53, 114, 70));
	*/
	// =========================== ITEM SPRITE ===========================================
	/*SpriteLoader::GetInstance()->AddSprite(new ItemSprite(BLUESPIRIT, 0, 7, 20, 24));
	SpriteLoader::GetInstance()->AddSprite(new ItemSprite(REDSPIRIT, 20, 7, 40, 24));
	SpriteLoader::GetInstance()->AddSprite(new ItemSprite(GLASSHOUR, 400, 50, 416, 70));
	SpriteLoader::GetInstance()->AddSprite(new ItemSprite(BLUESHURIKEN, 50, 6, 68, 26));
	SpriteLoader::GetInstance()->AddSprite(new ItemSprite(REDBAG, 192, 6, 210, 26));
	SpriteLoader::GetInstance()->AddSprite(new ItemSprite(FIREWHEEL, 110, 6, 128, 26));
	SpriteLoader::GetInstance()->AddSprite(new ItemSprite(BLUEBAG, 172, 6, 190, 26));
	SpriteLoader::GetInstance()->AddSprite(new ItemSprite(REDPOTION, 227, 6, 245, 26));*/
}

// Thêm một Sprite vào danh sách các Sprite, quy định theo Tag của Sprite
void SpriteLoader::AddSprite(Sprite* sprite)
{
	_sprites[sprite->tag].push_back(sprite);
}

Sprite* SpriteLoader::GetSprite(Tag tag, int index)
{
	return _sprites[tag][index];
}

// Lấy các Sprite (dùng cho tạo Animation) theo Tag từ vị trí first->last
std::vector<Sprite*> SpriteLoader::GetSprites(Tag tag, int firstIndex, int lastIndex)
{
	auto first = _sprites[tag].begin() + firstIndex;
	auto last = _sprites[tag].begin() + lastIndex;
	return std::vector<Sprite*>(first, last + 1);
}

SpriteLoader* SpriteLoader::GetInstance()
{
	if (_instance == NULL)
		_instance = new SpriteLoader();
	return _instance;
}