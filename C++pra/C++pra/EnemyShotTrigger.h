#pragma once
#include "ShotTriggerBase.h"

/**
* @file PlayerShotTrigger.h
* @brief �G�l�~�[�̎ˌ��Ǘ��g���K�[
* @date 2019 2/1
*/
class EnemyShotTrigger :
	public ShotTriggerBase
{
public:
	EnemyShotTrigger(D3DXVECTOR2 &pos);
	~EnemyShotTrigger();
	void Shot();
	void Shot(D3DXVECTOR2 targetPos);
};

