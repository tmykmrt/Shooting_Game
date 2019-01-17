#include "UIBar.h"

UIBar::UIBar()
{

}

UIBar::UIBar(TCHAR *name, int sizeX,float sizeY, float posX, float posY)
{
	sprite = new Sprite();
	sprite->Load(name, sizeX, sizeY);
	sprite->pos = { posX , posY };
}

UIBar::~UIBar()
{
	sprite->Release();
}

void UIBar::SetRatio(float newRatio)
{
	ratio = newRatio;
}

void UIBar::Render()
{
	sprite->DrawRatio(ratio,1);
}
