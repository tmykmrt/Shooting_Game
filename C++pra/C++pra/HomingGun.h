#pragma once
#include "WeaponBase.h"

namespace Weapon
{
	//	�ڕW���z�[�~���O���镐��
	class HomingGun :
		public WeaponBase
	{
	public:
		HomingGun(D3DXVECTOR2 &pos, float speed, Bullet::TargetType targetType);
		~HomingGun();
	};
}

