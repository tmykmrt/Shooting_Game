#pragma once
#include "WeaponBase.h"
namespace Weapon
{
	class AimGun :
		public WeaponBase
	{
	public:
		AimGun(UnitBase& owner);
		~AimGun();
	};
}

