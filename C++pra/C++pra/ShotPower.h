#pragma once
#include"NumRange.h"

/**
* @file PlayerShotTrigger.h
* @brief �ˌ��ɕK�v�ȗ͂̊Ǘ�
* @date 2019 1/1
*/
class ShotPower
{
public:
	ShotPower();
	ShotPower(float max,float recoveFrame);
	~ShotPower();
	void Init(float max, float recoveFrame);
	//	�����
	void Consume(float usePow);
	//	�g�p����͂�����Ă��邩
	bool IsEnough(float usePower);
	//	�`���[�W
	void Chage();
	//	����
	//	���ꎞ�I��
	float Rate();
	NumRange* NowPow();
private:
	NumRange pow;
	//	�`���[�W�l
	float recovePow;
};

