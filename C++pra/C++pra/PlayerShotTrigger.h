#pragma once
#include"stdafx.h"
#include "ShotPower.h"
#include "Timer.h"
#include "ShotTriggerBase.h"

/**
* @file PlayerShotTrigger.h
* @brief プレイヤーの射撃管理トリガー
* @date 2019 2/1
*/
class PlayerShotTrigger : public ShotTriggerBase
{
public:
	PlayerShotTrigger(D3DXVECTOR2 &pos);
	~PlayerShotTrigger();
	//	攻撃更新
	void AttackUpdate();
private:
	//	必要な力
	void Shot();
	//	強いときの必要な力
	float useStrangPow;
	//	溜めに必要なフレーム
	float chageFrame;
	//	射撃感覚
	int reloadFrame;
	//	時間計測
	Timer timer;
};

