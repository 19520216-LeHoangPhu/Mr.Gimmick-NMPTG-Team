﻿#include "ScenePlay.h"

ScenePlay::~ScenePlay() {}

ScenePlay::ScenePlay(HWND window)
{
	this->window = window;
	bool flag = this->directX.InitDirectX(this->window, SCREEN_WIDTH, SCREEN_HEIGHT, FULLSCREEN);

	this->yumetaro = new Yumetaro(YUMETARO_START_X, YUMETARO_START_Y, YUMETARO_VELOCITY_X,
		YUMETARO_VELOCITY_Y, 1, YUMETARO_WIDTH, YUMETARO_HEIGHT, SPRITE_YUMETARO_PATH, 1);

	this->yumetaro->Load(YUMETARO_BACKGROUND_COLOR, this->directX.GetDirectXGraphic());
	this->background = Background(NUMBER_OF_ROWS_LEVEL_1, NUMBER_OF_COLUMNS_LEVEL_1,
		FILE_TILEMAP_PATH_LEVEL_1, NUMBER_OF_TILES_LEVEL_1, L"Level_1", BACKGROUND_COLOR_LEVEL_1);

	this->background.LoadBackground(this->directX.GetDirectXGraphic());
}
void ScenePlay::Run(DWORD time, DWORD& timeStart)
{
	Update(time);
	Render();
}
void ScenePlay::Update(DWORD time)
{
	int velocity = 2;

	// Di chuyển bằng bàn phím
	if (KEY_DOWN(VK_LEFT))
	{
		yumetaro->SetVelocity(-velocity, 0);
		yumetaro->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_RIGHT))
	{
		yumetaro->SetVelocity(velocity, 0);
		yumetaro->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_UP))
	{
		yumetaro->SetVelocity(0, -velocity);
		yumetaro->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}

	if (KEY_DOWN(VK_DOWN))
	{
		yumetaro->SetVelocity(0, velocity);
		yumetaro->Move(SCREEN_WIDTH, SCREEN_HEIGHT);
	}
}
void ScenePlay::Render()
{
	GraphicDevice graphicDevice = this->directX.GetDirectXGraphic().GetGraphicDevice();

	// Bắt đầu render
	if (graphicDevice.BeginRendering())
	{
		DirectXGraphic directXGraphic = this->directX.GetDirectXGraphic();
		this->background.DrawBackground(directXGraphic.GetGraphicDevice().GetBackbuffer(), directXGraphic, 
			Camera());
		yumetaro->Draw(2, 0, graphicDevice, Point());

		// Dừng render
		graphicDevice.EndRendering();
	}

	// Thể hiện backbuffer lên màn hình
	graphicDevice.ShowBackbuffer();
}
void ScenePlay::OnKeyUp(int keycode)
{
//	yumetaro->OnKeyUp(keycode);
}
void ScenePlay::OnKeyDown(int keycode)
{
//	yumetaro->OnKeyDown(keycode);
}