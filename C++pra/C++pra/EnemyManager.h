#pragma once
#include"EnemyBase.h"
#include"stdafx.h"
class Enemy;

class EnemyManager
{
public:
	EnemyManager();
	~EnemyManager();
	void Update();
	void Render();
	void Create(int moveType, D3DXVECTOR2 startPos);
	void RandCreae();
	void Deleat();
	EnemyBase* GetEnemy(int num);
	//	敵数
	static const int enemyMax = 5;
private:

	//	敵配列
	EnemyBase *enemys[enemyMax];
};

