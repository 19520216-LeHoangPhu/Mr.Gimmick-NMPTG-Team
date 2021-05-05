#include "Treasures.h"

Treasures::Treasures()
{

}

Treasures::Treasures(float x, float y, int currentFrame, float width, float height,
	int numberOfAnimatedTiles, LPCWSTR fileSpriteName) : UsefulObj(x, y, numberOfAnimatedTiles)
{
	this->animatedTiles[0] = new AnimatedTile(x, y, width, height, fileSpriteName, 1, 0, currentFrame);
}

Treasures& Treasures::operator = (const Treasures& itemsAndHUD)
{
	AnimatedObj::operator = (itemsAndHUD);

	return *this;
}

bool Treasures::Load(D3DXCOLOR transparentColor, DirectXGraphic directXGrphic)
{
	return this->animatedTiles[0]->Load(transparentColor, directXGrphic);
}