#pragma once
#include "GameGlobal.h"

HINSTANCE hInstance = NULL;						
HWND hWnd = NULL;								
LPD3DXSPRITE spriteHandler = nullptr;			
LPDIRECT3DDEVICE9 d3ddev = nullptr;				
LPDIRECT3DSURFACE9 backBuffer = nullptr;		
bool isGameRunning = true;						
std::unordered_map<int, bool> keyCode;