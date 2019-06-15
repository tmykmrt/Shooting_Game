#pragma once
#include"stdafx.h"
class SpriteData;
/**
* @brief �摜�Ǘ�
* @details �摜�Ǘ�
*/
class SpriteManager : public Singleton<SpriteManager>
{
public:
	friend class Singleton<SpriteManager>;
	bool Load(TCHAR *fileName);
protected:
	SpriteManager();
	~SpriteManager();
private:
	//!	�摜�f�[�^
	vector<TCHAR*> loadSpriteName;
	map<int,SpriteData*> spriteDatas;
};

