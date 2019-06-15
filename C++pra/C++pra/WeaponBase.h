#pragma once
#include "Obsever.h"
#include "BulletManager.h"

class WeaponBase : public Obsever
{
public:
	WeaponBase(Unit::UnitBase &owner, D3DXVECTOR2 dirVec);
	~WeaponBase();
	void Update();
	//	�I�[�i�[�o�^
	void RegisterOwner(Unit::UnitBase &newOwner);
protected:
	//	����̏�����
	Unit::UnitBase &owner;
	//	���g�̕����x�N�g��
	D3DXVECTOR2 dirVec;
};


