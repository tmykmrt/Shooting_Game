#pragma once
#include"stdafx.h"
class SpriteData;
/**
* @brief ‰æ‘œŠÇ—
* @details ‰æ‘œŠÇ—
*/
class SpriteManager :public Singleton<SpriteManager>
{

public:
	friend class Singleton<SpriteManager>;
	bool Load(TCHAR *fileName);
protected:
	SpriteManager();
	~SpriteManager();
private:
	//!	‰æ‘œƒf[ƒ^
	list<SpriteData> spriteDataList;
};

