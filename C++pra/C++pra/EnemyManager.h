#pragma once
#include"Enemy.h"
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
	Enemy* GetEnemy(int num);
	//	“G”
	static const int enemyMax = 5;
private:

	//	“G”z—ñ
	Enemy *enemys[enemyMax];
};

