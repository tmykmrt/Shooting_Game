#include "Gun.h"
using namespace Weapon;

Gun::Gun(UnitBase& owner) : WeaponBase(owner)
{

}

Gun::~Gun()
{

}

void Gun::Update()
{
	AttackUseInfo info = owner.FetchAttackUseInfo();
	Bullet::BulletManager::GetInstance()
		->Create(10, UnitType::None, 1, info.attckPosition, info.attckPosition);
}
