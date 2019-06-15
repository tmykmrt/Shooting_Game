#pragma once
#include "WeaponBase.h"
namespace Weapon
{
	class AimGun :
		public WeaponBase
	{
	public:
		AimGun(Unit::UnitBase &owner, D3DXVECTOR2 dirVec);
		~AimGun();
		void Update();
	};
}

