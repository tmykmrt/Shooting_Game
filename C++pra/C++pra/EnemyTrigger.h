#pragma once
#include "TriggerBase.h"

/**
* @file PlayerShotTrigger.h
* @brief エネミーの射撃管理トリガー
* @date 2019 2/1
*/
class EnemyTrigger :
	public TriggerBase
{
public:
	EnemyTrigger(D3DXVECTOR2 &pos);
	~EnemyTrigger();
	void TriggerIfPossible();
private:
	void PullTrigger();
};

