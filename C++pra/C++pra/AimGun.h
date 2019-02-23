#pragma once
#include "WeaponBase.h"
namespace Weapon
{
	class AimGun :
		public WeaponBase
	{
	public:
		AimGun(D3DXVECTOR2 &pos, float speed, Bullet::TargetType targetType);
		~AimGun();
	};
}

