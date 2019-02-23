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
class TriggerBase : public Subject
{
public:
	TriggerBase();
	//	可能なら引く
	virtual void TriggerIfPossible() = 0;
protected:
	//	射撃に必要なパワーを管理
	ShotPower shotPow;
	float usePow;
	//	必要な力
	//bool Shot(D3DXVECTOR2& targetPos);
	~TriggerBase();
	//	引き金を引く
	bool PullTrigger();
private:
};

