#pragma once
#include"Sprite.h"
#include "stdafx.h"
/**
* @brief 画像管理用データ
* @details  画像管理用データ
*/
class SpriteData
{
public:
	SpriteData();
	SpriteData(int id, TCHAR *fileName, float sizeX, float sizeY);
	~SpriteData();
private:
	//!	管理ID
	int id;
	//	Sprite
	Sprite *sprite;
};

