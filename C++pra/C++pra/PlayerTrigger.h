#pragma once
#include"stdafx.h"
#include "ShotPower.h"
#include "Timer.h"
#include "TriggerBase.h"

/**
* @file PlayerShotTrigger.h
* @brief プレイヤーの射撃管理トリガー
* @date 2019 2/1
*/
class PlayerTrigger : public TriggerBase
{
public:
	PlayerTrigger(D3DXVECTOR2 &pos);
	~PlayerTrigger();
	//	可能ならトリガーを引く
	void TriggerIfPossible();
private:
	//	引き金を引く
	void PullTrigger();
	//	強いときの必要な力
	float useStrangPow;
	//	溜めに必要なフレーム
	float chageFrame;
	//	射撃感覚
	int reloadFrame;
	//	時間計測
	Timer timer;
};

