#pragma once
#include "SceneBase.h"
#include "Sprite.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "PlayerBase.h"
class GameScene :public SceneBase
{
public:
	GameScene();
	~GameScene();
	//	更新
	void Update();
	//	描画
	void Render();
	//!	当たり判定
	void Colision();
private:
	//	
	Sprite bgSprite;

	PlayerBase *player;

	Bullet::BulletManager *bulletManager;

	EnemyManager *enemytManager;
};

