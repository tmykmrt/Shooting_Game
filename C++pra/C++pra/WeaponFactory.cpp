#include "WeaponFactory.h"
#include"Gun.h"
#include"HomingGun.h"
#include"AimGun.h"
WeaponFactory::WeaponFactory()
{
}


WeaponFactory::~WeaponFactory()
{
}

//	ïêäÌÇê∂ê¨Ç∑ÇÈ
WeaponBase *WeaponFactory::Create(WeaponType createType, Unit::UnitBase *owner,D3DXVECTOR2 dirVec)
{
	switch (createType)
	{
	case WeaponFactory::Gun:
		return new Weapon::Gun(*owner, dirVec);
		break;
	case WeaponFactory::HomingGun:
		return new Weapon::HomingGun(*owner, dirVec);
		break;
	case WeaponFactory::AimGun:
		return new Weapon::AimGun(*owner, dirVec);
		break;
	case WeaponFactory::Beam:
		break;
	default:
		//createWeapon = new Weapon::Gun(NULL, 0, Bullet::TargetType::Enemy);
		break;
	}

	return NULL;
}
