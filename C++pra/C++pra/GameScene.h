#pragma once
#include "SceneBase.h"
#include "Sprite.h"

class GameScene :public SceneBase
{
public:
	GameScene();
	~GameScene();
	//	XV
	void Update();
	//	•`‰æ
	void Render();
private:
	//	
	Sprite bgSprite;
};