#pragma once
#include"Sprite.h"
#include "stdafx.h"
/**
* @brief �摜�Ǘ��p�f�[�^
* @details  �摜�Ǘ��p�f�[�^
*/
class SpriteData
{
public:
	SpriteData();
	SpriteData(int id, TCHAR *fileName, float sizeX, float sizeY);
	~SpriteData();
private:
	//!	�Ǘ�ID
	int id;
	//	Sprite
	Sprite *sprite;
};

