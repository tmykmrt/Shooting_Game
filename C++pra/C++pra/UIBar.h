#pragma once
#include"Sprite.h"
class UIBar
{
public:
	UIBar();
	UIBar(TCHAR *name, int sizeX, float sizeY,float posX, float posY);
	~UIBar();
	void Render();
	void SetRatio(float newRatio);
private:
	float ratio;
	Sprite *sprite;
};

