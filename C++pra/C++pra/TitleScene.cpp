/**
* @file TitleScene.cpp
* @brief �^�C�g��
* @date 2018 7/14
*/

#include "TitleScene.h"
#include"Input.h"

TitleScene::TitleScene()
{
	bgSprite.pos.x = 0;
	bgSprite.pos.y = 0;
	bgSprite.Load("Title.png",1280,720);
}


TitleScene::~TitleScene()
{
	//	���
	bgSprite.Release();

}
void TitleScene::Update()
{
	
}
void TitleScene::Render()
{
	bgSprite.Draw();
}
