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
	//!	�Ǘ�ID
	int id;
	//	Sprite
	Sprite *sprite;
};

