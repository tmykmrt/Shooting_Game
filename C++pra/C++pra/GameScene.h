#pragma once
#include "SceneBase.h"
#include "Sprite.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "PlayerController.h"
class GameScene :public SceneBase
{
public:
	GameScene();
	~GameScene();
	//	XV
	void Update();
	//	•`‰æ
	void Render();
	//!	“–‚½‚è”»’è
	void Colision();
private:
	//	
	Sprite bgSprite;

	PlayerController *player;

	Bullet::BulletManager *bulletManager;

	EnemyManager *enemytManager;
};

