/**
* @file TitleScene.h
* @brief タイトル
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
	//	更新
	void Update();
	//	描画
	void Render();
private:
	//	
	Sprite bgSprite;
};

