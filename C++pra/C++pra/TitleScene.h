/**
* @file TitleScene.h
* @brief �^�C�g��
* @date 2018 7/14
*/

#pragma once
#include "SceneBase.h"
#include "Sprite.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene();
	//	�X�V
	void Update();
	//	�`��
	void Render();
private:
	//	
	Sprite bgSprite;
};

