#include "UnitManager.h"
#include "Collision.h"
#include "PlayerController.h"
#include "BulletBase.h"

UnitManager::UnitManager()
{
	EnemyManager::CreateInstance();
	Bullet::BulletManager::CreateInstance();
	player = new PlayerController("Res/player.png", 1280, 256);
	playerinfo = new PlayerInformation(*player);
}

UnitManager::~UnitManager()
{
	delete player;
	delete playerinfo;
	EnemyManager::Destroy();
	Bullet::BulletManager::Destroy();
}

void UnitManager::Update()
{
	player->Update();
	EnemyManager::GetInstance()->Update();
	Bullet::BulletManager::GetInstance()->Update();
	Colision();
}

void UnitManager::Render()
{
	player->Render();
	EnemyManager::GetInstance()->Render();
	Bullet::BulletManager::GetInstance()->Render();
}

void UnitManager::Colision()
{
	//	“G‚Æ‚Ì”»’è
	for (int i = 0; i < EnemyManager::enemyMax; i++)
	{
		EnemyBase *e = EnemyManager::GetInstance()->GetEnemy(i);
		if (e == NULL)continue;
		if (e->Exists() == false)continue;

		if (Collision::Circle(player->GetPosition(), e->GetPosition(), 32))
		{
			player->Damage(1);
			e->Damage(1);
		}
	}

	//	’e‚Æ‚Ì”»’è
	for (int i = 0; i < Bullet::BulletManager::bulletNum; i++)
	{
		BulletBase *b = Bullet::BulletManager::GetInstance()->Getbullet(i);
		if (b == NULL)continue;
		if (b->Exists() == false)continue;
		//	ƒGƒlƒ~[‚Æ‚Ì”»’è
		if (b->GetTargetType() == Bullet::TargetType::Enemy)
		{
			for (int k = 0; k < EnemyManager::enemyMax; k++)
			{
				EnemyBase *e = EnemyManager::GetInstance()->GetEnemy(k);
				if (e == NULL)continue;
				if (e->Exists() == false)continue;
				if (Collision::Circle(b->GetPosition(), e->GetPosition(), 32))
				{
					e->Damage(1);
					b->Deleat();
					player->ChageLimit();
				}
			}
		}
	}
}

PlayerInformation &UnitManager::PlayerInfo()
{
	return *playerinfo;
}
