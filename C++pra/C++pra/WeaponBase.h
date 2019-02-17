#pragma once
#include "Obsever.h"
#include "BulletManager.h"
class WeaponBase : public Obsever
{
public:
	WeaponBase(D3DXVECTOR2 &pos);
	~WeaponBase();
	void Update();
protected:
	const D3DXVECTOR2 &shotPos;
	float speed;

	//	目標のタイプ
	Bullet::TargetType targetType;
};


