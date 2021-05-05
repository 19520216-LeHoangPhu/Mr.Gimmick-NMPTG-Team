﻿#pragma once

#include <d3dx9math.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "Yumetaro.h"
#include "DirectX.h"
#include "Background.h"
#include "LevelOne.h"
#include "ScrollBar.h"
#include "Waterfall.h"
#include "Enemies.h"

#pragma region Definition
#define APP_TITLE L"Mr.Gimmick"

#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)
#define KEY_UP(vk_code) ((GetAsyncKeyState(vk_code) * 0x8000) ? 1 : 0)

#define FULLSCREEN 0
#define SCREEN_WIDTH 1902//16 * TILE_SIZE * SCALE
#define SCREEN_HEIGHT 732//12 * TILE_SIZE * SCALE
//#define SCREEN_WIDTH 1920
//#define SCREEN_HEIGHT 739

#define FPS 30
#pragma endregion

class Game
{
private:
	Yumetaro yumetaro;
	Enemies* enemies;
	UselessObj** uselessObjs;
	int numberOfUselessObjs, numberOfEnemies;
	DirectX directX;
	HWND window;
	Background background;
public:
	Game();
	Game(const Game& game);
	~Game();
	void InitUselessObjs(int key, int* numberOfUselessObjs);
	void InitEnemies();
	bool InitGame(HWND window);
	bool LoadGame();
	void RunGame(HWND window);
	void UpdateGame();
	void Render();
	void EndGame(HWND window);
	DirectX GetDirectX();
};