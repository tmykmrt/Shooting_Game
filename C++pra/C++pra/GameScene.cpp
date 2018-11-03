#include "GameScene.h"
#include "Collision.h"
#include "PlayerBase.h"
#include "BulletBase.h"
GameScene::GameScene()
{
	bulletManager = new Bullet::BulletManager();
	enemytManager = new EnemyManager();
	player = new PlayerBase("chara.png", 128, 128);
	player->SetBulletManager(bulletManager);
	bgSprite.pos = { 0,0 };
	bgSprite.Load("game.png", 1280, 720);
}


GameScene::~GameScene()
{
	delete player;
	delete bulletManager;
	delete enemytManager;
	bgSprite.Release();
}

void GameScene::Update()
{
	player->Update();
	bulletManager->Update();
	enemytManager->Update();
	Colision();
}

void GameScene::Render()
{
	bgSprite.Draw();
	player->Render();
	bulletManager->Render();
	enemytManager->Render();
}

void GameScene::Colision()
{
	for(int i = 0; i <Bullet::BulletManager::bulletNum; i++)
	{
		BulletBase *b = bulletManager->Getbullet(i);
		if (b == NULL)continue;
		if (b->Exists() == false)continue;
		//	エネミーとの判定
		if (b->GetTargetType() == Bullet::TargetType::Enemy)
		{
			for (int i = 0; i < EnemyManager::enemyMax; i++)
			{
				EnemyBase *e = enemytManager->GetEnemy(i);
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
