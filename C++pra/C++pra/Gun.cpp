#include "Gun.h"
using namespace Weapon;
using namespace Unit;
Gun::Gun(UnitBase &owner, D3DXVECTOR2 dirVec) : WeaponBase(owner, dirVec)
{

}

Gun::~Gun()
{

}

void Gun::Update()
{
	AttackUseInfo info = owner.FetchAttackUseInfo();
	Bullet::BulletManager::GetInstance()
		->Create(10, Unit::UnitType::None, 1, info.attckPosition, info.attckPosition);
}
