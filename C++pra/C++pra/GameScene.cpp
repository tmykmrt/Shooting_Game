#include "GameScene.h"
#include "UnitManager.h"
#include "GameUIManager.h"
#include "WeaponFactory.h"
#include "CollisionManager.h"
using namespace Collision;
using namespace Unit;
GameScene::GameScene()
{
	GameUIManager::CreateInstance();
	UnitManager::CreateInstance();
	WeaponFactory::CreateInstance();
	Collision::CollisionManager::CreateInstance();
	bgSprite.pos = { 0,0 };
	bgSprite.Load("Res/game.png", 1280, 720);
}

GameScene::~GameScene()
{
	bgSprite.Release();
	GameUIManager::Destroy();
	UnitManager::Destroy();
	WeaponFactory::Destroy();
	CollisionManager::Destroy();
}

void GameScene::Update()
{
	UnitManager::GetInstance()->Update();

	CollisionManager::GetInstance()->CollisionCheck();
	//	UIXV
	GameUIManager::GetInstance()->Update();
}

void GameScene::Render()
{
	bgSprite.Draw();
	GameUIManager::GetInstance()->Render();
	UnitManager::GetInstance()->Render();
}