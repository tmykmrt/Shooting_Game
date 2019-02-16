#pragma once
#include"stdafx.h"
#include"ShotPower.h"
#include"BulletManager.h"
#include"Obsever.h"
class ShotPower;

/**
* @file PlayerShotTrigger.h
* @brief 射撃の引き金
* @date 2019 1/1
*/
class ShotTriggerBase : public Subject
{
public:
	ShotTriggerBase(D3DXVECTOR2 &pos);
	~ShotTriggerBase();
protected:
	//	射撃に必要なパワーを管理
	ShotPower shotPow;
	float usePow;
	//	必要な力
	bool Shot();
	//	必要な力
	bool Shot(D3DXVECTOR2& targetPos);
	//	発射座標
	Bullet::TargetType targetType;

	//	テストcode---------------------
	float speed;
private:
	const D3DXVECTOR2 &shotPos;
};

