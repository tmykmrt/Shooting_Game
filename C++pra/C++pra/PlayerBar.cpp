#include "PlayerBar.h"
#include"UIBar.h"
#include"Sprite.h"

PlayerBar::PlayerBar()
{

}

PlayerBar::PlayerBar(TCHAR *name, int sizeX, float sizeY, float posX, float posY)
{
	uiBar = new UIBar(name, sizeX, sizeY,posX,posY);
	nowRatio = targetRatio = 1;
	uiBar->SetRatio(1);
}

PlayerBar::~PlayerBar()
{
	delete uiBar;
}

//void PlayerBar::Set(float ratio)
//{
//	uiBar->SetRatio(1);
//}

void PlayerBar::UpdateRatio(float ratio)
{
	upper = nowRatio < ratio;
	targetRatio = ratio;
}

void PlayerBar::Update()
{
	if (nowRatio == targetRatio) return;

	if ( nowRatio > targetRatio
		&& upper)
	{
		nowRatio = targetRatio;
		return;
	}
	else if (targetRatio > nowRatio
		&& upper == false)
	{
		nowRatio = targetRatio;
		return;
	}

	nowRatio += upper ? 0.005f : -0.005f;

	uiBar->SetRatio(nowRatio);
}

void PlayerBar::Render()
{
	uiBar->Render();
}
