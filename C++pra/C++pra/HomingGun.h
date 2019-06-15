#pragma once
#include "WeaponBase.h"

namespace Weapon
{
	//	目標をホーミングする武器
	class HomingGun :
		public WeaponBase
	{
	public:
		HomingGun(Unit::UnitBase &owner, D3DXVECTOR2 dirVec);
		~HomingGun();
	};
}

