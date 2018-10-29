#pragma once
#include"Bullet.h"
#include"stdafx.h"
class Bullet;
/**
* @brief 弾の管理
* @details 弾の更新、描画、生成を行う
*/
class BulletManager
{
public:
	enum TargetType
	{
		None,
		Player,
		Enemy,
	};

	const static int bulletNum = 5;
	BulletManager();
	~BulletManager();
	//	作成
	void Create(float speed, TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
	void Render();
	void Update();
	void Remove(Bullet *bullet);
	Bullet* Getbullet(int num);
private:
	//	弾のは配列
	Bullet *bullets[bulletNum];

	//list<Bullet> bulletList;
};