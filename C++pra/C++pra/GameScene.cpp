#include "GameScene.h"
#include "Collision.h"
#include "PlayerController.h"
#include "BulletBase.h"
#include "GameUIManager.h"

GameScene::GameScene()
{
	EnemyManager::CreateInstance();
	Bullet::BulletManager::CreateInstance();
	player = new PlayerController("Res/player.png", 1280, 256);
	bgSprite.pos = { 0,0 };
	bgSprite.Load("Res/game.png", 1280, 720);
	GameUIManager::CreateInstance();
}

GameScene::~GameScene()
{
	delete player;
	EnemyManager::Destroy();
	Bullet::BulletManager::Destroy();
	bgSprite.Release();
	GameUIManager::Destroy();
}

void GameScene::Update()
{
	player->Update();
	EnemyManager::GetInstance()->Update();
	Bullet::BulletManager::GetInstance()->Update();
	Colision();
}

void GameScene::Render()
{
	bgSprite.Draw();
	GameUIManager::GetInstance()->Render();
	player->Render();
	EnemyManager::GetInstance()->Render();
	Bullet::BulletManager::GetInstance()->Render();
}

void GameScene::Colision()
{
	for (int i = 0; i < Bullet::BulletManager::bulletNum; i++)
	{
		BulletBase *b = Bullet::BulletManager::GetInstance()->Getbullet(i);
		if (b == NULL)continue;
		if (b->Exists() == false)continue;
		//	エネミーとの判定
		if (b->GetTargetType() == Bullet::TargetType::Enemy)
		{
			for (int i = 0; i < EnemyManager::enemyMax; i++)
			{
				EnemyBase *e = EnemyManager::GetInstance()->GetEnemy(i);
				if (e == NULL)continue;
				if (e->Exists() == false)continue;
				if (Collision::Circle(b->GetPosition(), e->GetPosition(), 32))
				{
					e->HitAction(1);
					b->Deleat();
				}
			}
		}
	}
}