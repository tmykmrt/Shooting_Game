#include "GameScene.h"
#include "UnitManager.h"
#include "GameUIManager.h"

GameScene::GameScene()
{
	GameUIManager::CreateInstance();
	UnitManager::CreateInstance();
	bgSprite.pos = { 0,0 };
	bgSprite.Load("Res/game.png", 1280, 720);
}

GameScene::~GameScene()
{
	bgSprite.Release();
	GameUIManager::Destroy();
	UnitManager::Destroy();
}

void GameScene::Update()
{
	UnitManager::GetInstance()->Update();
	//	UIXV
	GameUIManager::GetInstance()->Update();
}

void GameScene::Render()
{
	bgSprite.Draw();
	GameUIManager::GetInstance()->Render();
	UnitManager::GetInstance()->Render();
}