#include "AimGun.h"

using namespace Weapon;
using namespace Unit;
AimGun::AimGun(UnitBase &owner, D3DXVECTOR2 dirVec) : WeaponBase(owner, dirVec)
{

}


AimGun::~AimGun()
{

}

void AimGun::Update()
{
	AttackUseInfo info = owner.FetchAttackUseInfo();
	Bullet::BulletManager::GetInstance()
		->Create(5, Unit::UnitType::None, 2, info.attckPosition, info.targetPosition);
}
