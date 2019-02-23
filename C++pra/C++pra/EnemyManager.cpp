#include "EnemyManager.h"
#include "EnemyBase.h"

EnemyManager::EnemyManager()
{
	for (int i = 0; i < enemyMax; i++)
	{
		enemys[i] = NULL;
	}
}

EnemyManager::~EnemyManager()
{
	delete[] enemys;
}

EnemyBase* EnemyManager::GetEnemy(int num)
{
	if (num < 0 || num >= enemyMax)return NULL;
	return enemys[num];
}

//	更新
void EnemyManager::Update()
{
	RandCreae();
	for (int i = 0; i < enemyMax; i++)
	{
		if (enemys[i] == NULL)continue;
		if (enemys[i]->Exists() == false)
		{
			delete enemys[i];
			enemys[i] = NULL;
		}
		else
		{
			enemys[i]->Update();
		}
	}
}

//	描画
void EnemyManager::Render()
{
	for (int i = 0; i < enemyMax; i++)
	{
		if (enemys[i] == NULL)continue;
		enemys[i]->Render();
	}
}

void EnemyManager::Create(int moveType, D3DXVECTOR2 startPos)
{
	for (int i = 0; i < enemyMax; i++)
	{
		if (enemys[i] == NULL)
		{
			enemys[i] = new EnemyBase(moveType, startPos);
			break;
		}
	}
}

void EnemyManager::RandCreae()
{

	if ((rand() % 100) == 0)
	{
		D3DXVECTOR2 pos;
		pos.x = SCREEN_WIDTH;
		float rat = (float)(rand() % 10);
		pos.y = (float)(SCREEN_HEIGHT / rat);
		Create(1, pos);
	}
}
