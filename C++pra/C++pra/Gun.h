#pragma once
#include "WeaponBase.h"
namespace Weapon
{
	//	����
	class Gun :
		public WeaponBase
	{
	public:
		Gun(D3DXVECTOR2 &pos, float speed, Bullet::TargetType targetType);
		~Gun();
	};
}

