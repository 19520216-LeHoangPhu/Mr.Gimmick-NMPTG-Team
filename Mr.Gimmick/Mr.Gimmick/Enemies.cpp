﻿#include "Enemies.h"

Enemies::Enemies()
{

}

Enemies::Enemies(float x, float y, int gameObjID, float vX, float vY, int numberOfAnimatedTiles, 
	float width, float height, LPCWSTR fileSpriteName) : UnplayableObj(x, y, numberOfAnimatedTiles, vX, 
	vY, gameObjID)
{
	this->animatedTiles[0] = new AnimatedTile(x, y, width, height, fileSpriteName, 1, 0, 1);
	SetDimension();
}

Enemies& Enemies::operator = (const Enemies& enemies)
{
	AnimatedAndMovableObj::operator = (enemies);

	return *this;
}

bool Enemies::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}