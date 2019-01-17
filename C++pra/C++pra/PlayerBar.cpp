#include "PlayerBar.h"
#include"UIBar.h"
#include"Sprite.h"

PlayerBar::PlayerBar()
{
}

PlayerBar::PlayerBar(TCHAR *name, int sizeX, float sizeY, float posX, float posY)
{
	uiBar = new UIBar(name, sizeX, sizeY,posX,posY);
	uiBar->SetRatio(0.5f);
}


PlayerBar::~PlayerBar()
{
	delete uiBar;
}

void PlayerBar::Set(float ratio)
{
	uiBar->SetRatio(1);
}

void PlayerBar::Set(float ratio)
{
	targetRatio = ratio;
}

void PlayerBar::Update()
{
	if (targetRatio >= nowRatio)
	{
		nowRatio = targetRatio;
		return;
	}
	nowRatio -= 0.05f;
	uiBar->SetRatio(nowRatio);
}

void PlayerBar::Render()
{
	uiBar->Render();
}
