#pragma once
#include"stdafx.h"
#include"ShotPower.h"
#include"BulletManager.h"
#include"Obsever.h"
class ShotPower;

/**
* @file PlayerShotTrigger.h
* @brief �ˌ��̈�����
* @date 2019 1/1
*/
class TriggerBase : public Subject
{
public:
	TriggerBase();
	//	�\�Ȃ����
	virtual void TriggerIfPossible() = 0;
	//	�g�p����͂�ς���
	void ChangeUsePow(float newPow);
protected:
	//	�ˌ��ɕK�v�ȃp���[���Ǘ�
	ShotPower shotPow;
	//	�K�v�ȗ�
	//bool Shot(D3DXVECTOR2& targetPos);
	~TriggerBase();
	//	������������
	bool PullTrigger();
private:
	float usePow;
};

