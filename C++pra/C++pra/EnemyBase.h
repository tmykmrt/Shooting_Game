#pragma once
/**
* @file Enemy.h
* @brief �G�l�~�[�N���X
* @date 2018 9/23
*/
#include "UnitBase.h"
#include "EnemyShotTrigger.h"
#include "MovementBase.h"
class EnemyBase : public UnitBase
{
public:
	EnemyBase();
	EnemyBase(int moveType, D3DXVECTOR2 startPos);
	~EnemyBase();
	//	������
	void Init(int moveType, D3DXVECTOR2 startPos);
	void Update();
	void Render();
	void Damage(int atk);
private:
	//! �����^�C�v
	int moveType;
	//! �ł��
	int shotType;
	//! �ړ�
	MovementBase* mover;
	EnemyShotTrigger *shot;
};

