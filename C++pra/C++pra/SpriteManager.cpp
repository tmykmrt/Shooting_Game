#include "SpriteManager.h"
#include"SpriteData.h"

SpriteManager::SpriteManager()
{

}

SpriteManager::~SpriteManager()
{

}

bool SpriteManager::Load(TCHAR *fileName)
{
	//iterator it = spriteDatas.begin();

	D3DXIMAGE_INFO *info = NULL;
	//	î•ñŽæ“¾
	if (D3DXGetImageInfoFromFile(fileName, info) == D3D_OK)
	{
		SpriteData *data = new SpriteData(0,fileName, info->Width,info->Height);
		//spriteDatas.insert(std::make_pair(loadSpriteName.cou, data));
	}

	return NULL;
}
