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
	TriggerBase(D3DXVECTOR2 &pos);
	//	�\�Ȃ����
	virtual void TriggerIfPossible() = 0;
protected:
	//	�ˌ��ɕK�v�ȃp���[���Ǘ�
	ShotPower shotPow;
	float usePow;
	//	�K�v�ȗ�
	//bool Shot(D3DXVECTOR2& targetPos);
	~TriggerBase();
	//	������������
	bool PullTrigger();
private:
	const D3DXVECTOR2 &shotPos;
};

