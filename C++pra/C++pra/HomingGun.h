#pragma once
#include "WeaponBase.h"

namespace Weapon
{
	//	�ڕW���z�[�~���O���镐��
	class HomingGun :
		public WeaponBase
	{
	public:
		HomingGun(UnitBase &owner);
		~HomingGun();
	};
}

