#pragma once
#include "WeaponBase.h"

namespace Weapon
{
	//	目標をホーミングする武器
	class HomingGun :
		public WeaponBase
	{
	public:
		HomingGun(D3DXVECTOR2 &pos, float speed, Bullet::TargetType targetType);
		~HomingGun();
	};
}

