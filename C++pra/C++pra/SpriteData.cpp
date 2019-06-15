#include "SpriteData.h"


SpriteData::SpriteData()
{

}

SpriteData::SpriteData(int id, TCHAR *fileName,float sizeX,float sizeY)
{
	sprite = new Sprite();
	this->id = id;
	sprite->Load(fileName, sizeX, sizeY);
}

SpriteData::~SpriteData()
{
	sprite->Release();
	delete sprite;
}
