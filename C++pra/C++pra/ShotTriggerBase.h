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
class ShotTriggerBase : public Subject
{
public:
	ShotTriggerBase(D3DXVECTOR2 &pos);
	~ShotTriggerBase();
protected:
	//	�ˌ��ɕK�v�ȃp���[���Ǘ�
	ShotPower shotPow;
	float usePow;
	//	�K�v�ȗ�
	bool Shot();
	//	�K�v�ȗ�
	bool Shot(D3DXVECTOR2& targetPos);
	//	���ˍ��W
	Bullet::TargetType targetType;

	//	�e�X�gcode---------------------
	float speed;
private:
	const D3DXVECTOR2 &shotPos;
};

