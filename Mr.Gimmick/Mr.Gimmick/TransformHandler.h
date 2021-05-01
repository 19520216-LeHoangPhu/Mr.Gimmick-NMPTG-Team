#pragma once

#include <d3dx9.h>
#include "Handler.h"
#include "Pair.h"

#pragma region Definition
#define SCALE 2.5
#pragma endregion

class TransformHandler : public Handler
{
public:
	const D3DXMATRIX* GetScaleMatrix(Pair scale = Pair(SCALE, SCALE));
};