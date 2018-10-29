#pragma once
#include "SceneBase.h"
#include "Sprite.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "Player.h"
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

	Player *player;

	BulletManager *bulletManager;

	EnemyManager *enemytManager;
};

