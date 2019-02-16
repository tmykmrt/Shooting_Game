#pragma once
#include"stdafx.h"
#include "ShotPower.h"
#include "Timer.h"
#include "ShotTriggerBase.h"

/**
* @file PlayerShotTrigger.h
* @brief �v���C���[�̎ˌ��Ǘ��g���K�[
* @date 2019 2/1
*/
class PlayerShotTrigger : public ShotTriggerBase
{
public:
	PlayerShotTrigger(D3DXVECTOR2 &pos);
	~PlayerShotTrigger();
	//	�U���X�V
	void AttackUpdate();
private:
	//	�K�v�ȗ�
	void Shot();
	//	�����Ƃ��̕K�v�ȗ�
	float useStrangPow;
	//	���߂ɕK�v�ȃt���[��
	float chageFrame;
	//	�ˌ����o
	int reloadFrame;
	//	���Ԍv��
	Timer timer;
};

