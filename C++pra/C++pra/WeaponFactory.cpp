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
WeaponBase *WeaponFactory::Create(WeaponType createType,UnitBase *owner)
{
	switch (createType)
	{
	case WeaponFactory::Gun:
		return new Weapon::Gun(*owner);
		break;
	case WeaponFactory::HomingGun:
		return new Weapon::HomingGun(*owner);
		break;
	case WeaponFactory::AimGun:
		return new Weapon::AimGun(*owner);
		break;
	case WeaponFactory::Beam:
		break;
	default:
		//createWeapon = new Weapon::Gun(NULL, 0, Bullet::TargetType::Enemy);
		break;
	}

	return NULL;
}
