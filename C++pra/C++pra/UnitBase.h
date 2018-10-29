
/**
* @file UnitBase.h
* @brief ���j�b�g���N���X
* @date 2018 8/25
*/

#pragma once
#include "Sprite.h"
#include"stdafx.h"
class UnitBase
{
public:
	UnitBase();
	virtual ~UnitBase();
	//	�X�V
	virtual void Update() = 0;
	//	�`��
	virtual void Render() = 0;
	//	
	virtual void HitAction(int atk);

	D3DXVECTOR2 GetPosition();
	//	��r
	const bool UnitBase::operator == (const UnitBase& b)
	{
		return this == &b;
	}
	//	�������Ă��邩
	bool Exists();
	//! ��ʊO�m�F
	bool CheckScreenOut();
	//! ���W�X�V
	void UpdatePosition();
protected:
	//!���W
	D3DXVECTOR2 position;
	//	�x�N�g��
	D3DXVECTOR2 vec;
	//!�摜
	Sprite sprite;
	//!���x
	float speed;
	//! ���݂̑��x
	float nowSpeed;
	//! �̗�
	int hp;
	//! ���݂��Ă��邩
	bool exists;
};

