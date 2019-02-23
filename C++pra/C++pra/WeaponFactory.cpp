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
WeaponBase *WeaponFactory::Create(WeaponType createType)
{
	WeaponBase *createWeapon;
	switch (createType)
	{
	case WeaponFactory::Gun:
		//createWeapon = new Weapon::Gun(NULL,0, Bullet::TargetType::Enemy);
		break;
	case WeaponFactory::HomingGun:
		//createWeapon = new Weapon::HomingGun(NULL, 0, Bullet::TargetType::Enemy);
		break;
	case WeaponFactory::AimGun:
		//createWeapon = new Weapon::AimGun(NULL, 0, Bullet::TargetType::Enemy);
		break;
	case WeaponFactory::Beam:
		break;
	default:
		//createWeapon = new Weapon::Gun(NULL, 0, Bullet::TargetType::Enemy);
		break;
	}

	return createWeapon;
}
