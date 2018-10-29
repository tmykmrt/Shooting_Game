#include "EnemyManager.h"
#include "Enemy.h"

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

Enemy* EnemyManager::GetEnemy(int num)
{
	if (num < 0 || num >= enemyMax)return NULL;
	return enemys[num];
}

//	XV
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

//	•`‰æ
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
			enemys[i] = new Enemy(moveType, startPos);
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
		pos.y = (float)rand() / SCREEN_HEIGHT;
		Create(1, pos);
	}
}
