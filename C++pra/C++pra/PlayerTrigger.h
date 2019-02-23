#pragma once
#include"stdafx.h"
#include "ShotPower.h"
#include "Timer.h"
#include "TriggerBase.h"

/**
* @file PlayerShotTrigger.h
* @brief �v���C���[�̎ˌ��Ǘ��g���K�[
* @date 2019 2/1
*/
class PlayerTrigger : public TriggerBase
{
public:
	PlayerTrigger(D3DXVECTOR2 &pos);
	~PlayerTrigger();
	//	�\�Ȃ�g���K�[������
	void TriggerIfPossible();
private:
	//	������������
	void PullTrigger();
	//	�����Ƃ��̕K�v�ȗ�
	float useStrangPow;
	//	���߂ɕK�v�ȃt���[��
	float chageFrame;
	//	�ˌ����o
	int reloadFrame;
	//	���Ԍv��
	Timer timer;
};

