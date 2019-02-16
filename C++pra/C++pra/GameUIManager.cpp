#include "GameUIManager.h"
#include"PlayerBar.h"
#include"Sprite.h"

GameUIManager::GameUIManager()
{
	//	˜g
	powFlame = new Sprite();
	powFlame->Load("Res/BattleUI/hougeki.png", 540, 100);
	powFlame->pos = { 0 , 590 };

	pointFlame = new Sprite();
	pointFlame->Load("Res/BattleUI/HP_rimit.png", 640, 100);
	pointFlame->pos = { 0 , 0 };

	//	ƒQ[ƒW
	playerHp = new PlayerBar("Res/BattleUI/HP_bar.png", 413, 20, 213, 21);
	playerMp = new PlayerBar("Res/BattleUI/rimit_ber.png", 343, 26, 188, 45);
	playerPow = new PlayerBar("Res/BattleUI/houbeki_bar.png", 540, 100, 0, 590);
}

GameUIManager::~GameUIManager()
{
	delete playerHp;
	delete playerMp;
	delete playerPow;
	pointFlame->Release();
	powFlame->Release();
}

void GameUIManager::Update()
{
	playerHp->Update();
	playerMp->Update();
	playerPow->Update();
}

void GameUIManager::Render()
{
	pointFlame->Draw();
	powFlame->Draw();
	playerHp->Render();
	playerMp->Render();
	playerPow->Render();
}

//	
void GameUIManager::UpdateHpBar(float raito)
{
	playerHp->UpdateRatio(raito);
}

void GameUIManager::UpdateMpBar(float raito)
{
	playerMp->UpdateRatio(raito);
}
void GameUIManager::UpdatePowBar(float raito)
{
	playerPow->UpdateRatio(raito);
}
