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
	EnemyTrigger(UnitBase* ower);
	~EnemyTrigger();
	void TriggerIfPossible();
private:
	void PullTrigger();
};

