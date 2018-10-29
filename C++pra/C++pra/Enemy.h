#pragma once
/**
* @file Enemy.h
* @brief �G�l�~�[�N���X
* @date 2018 9/23
*/
#include "UnitBase.h"
class Enemy : public UnitBase
{
public:
	Enemy();
	Enemy(int moveType, D3DXVECTOR2 startPos);
	~Enemy();

	//	������
	void Init(int moveType, D3DXVECTOR2 startPos);
	void Update();
	void Render();
	void HitAction(int atk);
private:
	//! �����^�C�v
	int moveType;
	//! �ł��
	int shotType;

};

