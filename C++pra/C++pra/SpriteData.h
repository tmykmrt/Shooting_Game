#pragma once
#include"Sprite.h"
#include "stdafx.h"
/**
* @brief æÇpf[^
* @details  æÇpf[^
*/
class SpriteData
{
public:
	SpriteData();
	SpriteData(int id, TCHAR *fileName, float sizeX, float sizeY);
	~SpriteData();
private:
	//!	ÇID
	int id;
	//	Sprite
	Sprite *sprite;
};

