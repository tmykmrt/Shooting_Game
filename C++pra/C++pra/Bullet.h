#pragma once
#include "UnitBase.h"
#include"stdafx.h"
#include"BulletManager.h"
class BulletManager;

/**
* @brief �e�̓���
* @details �e�̓���
*/
class Bullet : public UnitBase
{
public:

	Bullet();
	Bullet(float speed, BulletManager::TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
	~Bullet();
	//	�X�V
	void Update();
	//	�`��
	void Render();
	//	������
	void Init(float speed, BulletManager::TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
	void SetBulletManager(BulletManager *bullet);
	void HitAction(int atk);
	void Deleat();
	BulletManager::TargetType GetTargetType();
private:
	//!	�ڕW�^�C�v
	BulletManager::TargetType targetType;
	//!	�ړ��̎��
	int moveType;
	//!	�}�l�[�W���[�̃L���b�V��
	BulletManager *bulletManager;
};

