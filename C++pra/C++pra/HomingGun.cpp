#include "HomingGun.h"

using namespace Weapon;

HomingGun::HomingGun(D3DXVECTOR2 &pos, float speed, Bullet::TargetType targetType)
	: WeaponBase(pos)
{
}

HomingGun::~HomingGun()
{
}
