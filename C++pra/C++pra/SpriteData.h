#pragma once
#include"Sprite.h"
#include "stdafx.h"
class SpriteData
{
public:
	SpriteData();
	SpriteData(int id,string fileName);
	~SpriteData();
private:
	//!	ŠÇ—ID
	int id;
	//	Sprite
	Sprite *sprite;
};

