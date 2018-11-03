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
	//	�X�V
	void Update();
	//	�`��
	void Render();
	//!	�����蔻��
	void Colision();
private:
	//	
	Sprite bgSprite;

	PlayerBase *player;

	Bullet::BulletManager *bulletManager;

	EnemyManager *enemytManager;
};

