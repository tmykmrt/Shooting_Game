#pragma once
#include"stdafx.h"
#include"WeaponBase.h"

class WeaponFactory : public Singleton<WeaponFactory>
{
public:
	//	����̎��
	enum WeaponType
	{
		//	�^�������ȏe
		Gun,
		//	�z�[�~���O�@�\�̏e
		HomingGun,
		//	�_���e
		AimGun,
		//	�r�[��
		Beam,
	};

	friend class Singleton<WeaponFactory>;
	//	����̐���
	WeaponBase* Create(WeaponType createType, Unit::UnitBase *owner, D3DXVECTOR2 dirVec);
protected:
	WeaponFactory();
	~WeaponFactory();

};

