#pragma once
#include"Sprite.h"
class UIBar;
class PlayerBar
{
public:
	PlayerBar();
	PlayerBar(TCHAR *name, int sizeX, float sizeY,float posX, float posY);
	~PlayerBar();
	void Render();
	void Update();
	void Set(float max);
private:
	UIBar *uiBar;
	float nowRatio;
	float targetRatio;
};

