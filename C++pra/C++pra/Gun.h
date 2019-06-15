#pragma once
#include "WeaponBase.h"
namespace Weapon
{
	//	•Ší
	class Gun :
		public WeaponBase
	{
	public:
		Gun(Unit::UnitBase &owner, D3DXVECTOR2 dirVec);
		~Gun();
		void Update();
	};
}