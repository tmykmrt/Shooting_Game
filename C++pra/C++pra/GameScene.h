#pragma once
#include "SceneBase.h"
#include "Sprite.h"

class GameScene :public SceneBase
{
public:
	GameScene();
	~GameScene();
	//	�X�V
	void Update();
	//	�`��
	void Render();
private:
	//	
	Sprite bgSprite;
};