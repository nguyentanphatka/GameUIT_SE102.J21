#pragma once

#define WINDOW_CLASS_NAME "Ninja Gaiden"		// Class Windows
#define MAIN_WINDOW_TITLE "Ninja Gaiden"		// Tên cửa sổ
#define SCREEN_WIDTH 312						// Chiều rộng cửa sổ
#define SCREEN_HEIGHT 176						// Chiều dài cửa sổ
#define MAX_FRAME_RATE 90						// FPS
#define BACK_COLOR D3DCOLOR_XRGB(0, 0, 0)		// Màu nền BackBuffer
#define DEFAULT_FPS 150							// Thời gian tồn tại của mỗi Frame (cho Animation)
#define GRAVITY_SPEED 0.014f					// Tốc độ trọng lực
#define KEYBOARD_BUFFER_SIZE 1024
#define NUMBER_MAP_LEVEL 1
#define TILE_SIZE 16

// ===== Các thông số cho PLAYER ====
#define player Player::GetInstance()
#define PLAYER_RUNNING_SPEED 0.1f
#define PLAYER_JUMPING_SPEED 0.28f
#define PLAYER_FALLING_SPEED 0.25f
#define PLAYER_CLIMBING_SPEED 0.1f
#define PLAYER_WIDTH 24
#define PLAYER_STANDING_HEIGHT 32
#define PLAYER_SITTING_HEIGHT 24
#define PLAYER_ATTACK_SPRITE_WIDTH 34
#define PLAYER_ATTACKING_FORWARD 15
#define PLAYER_SITTING_BACKWARD 7
#define PLAYER_THROW_SPRITE_WIDTH 27
#define PLAYER_THROWING_FORWARD 5

// ===== Các thông số cho ITEM SWORD ====
#define SWORD_WIDTH 16
#define SWORD_HEIGHT 12

// ===== Các thông số cho ITEM SHURIKEN ====
#define BLUESHURIKEN_WIDTH 18
#define BLUESHURIKEN_HEIGHT 18
#define BLUESHURIKEN_SPEED 0.15f
#define SWINGSWORD_WIDTH 18
#define SWINGSWORD_HEIGHT 18
#define BULLET_WIDTH 18
#define BULLET_HEIGHT 12
#define DAGGER_WIDTH 11
#define DAGGER_HEIGHT 23

#define FIREWHEEL_WIDTH 35
#define FIREWHEEL_HEIGHT 35
#define FIREWHEEL_SPEED 0.14f

// ===== CÁC THÔNG SỐ CHO ENEMIES ====
#define ENEMY_SWORDMAN_WIDTH 24
#define ENEMY_SWORDMAN_HEIGHT 32
#define ENEMY_GUNMAN_HEIGHT 30
#define ENEMY_GUNMAN_WIDTH 32
#define ENEMY_BAZOKAMAN_WIDTH 32
#define ENEMY_BAZOKAMAN_HEIGHT 32
#define ENEMY_CLOAKMAN_WIDTH 28
#define ENEMY_CLOAKMAN_HEIGHT 48
#define ENEMY_PANTHER_WIDTH 34
#define ENEMY_PANTHER_HEIGHT 14
#define ENEMY_EAGLE_WIDTH 26
#define ENEMY_EAGLE_HEIGHT 38

// ===== CÁC THÔNG SỐ CHO HOLDERS ====
#define HODLER_BUTTERFLY_WIDTH 20
#define HODLER_BUTTERFLY_HEIGHT 16

// ===== CAMERA =====
#define camera Camera::GetInstance()
