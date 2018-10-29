#pragma once
#include"Bullet.h"
#include"stdafx.h"
class Bullet;
/**
* @brief ’e‚ÌŠÇ—
* @details ’e‚ÌXVA•`‰æA¶¬‚ğs‚¤
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
	//	ì¬
	void Create(float speed, TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
	void Render();
	void Update();
	void Remove(Bullet *bullet);
	Bullet* Getbullet(int num);
private:
	//	’e‚Ì‚Í”z—ñ
	Bullet *bullets[bulletNum];

	//list<Bullet> bulletList;
};