#pragma once
#include "WeaponBase.h"
namespace Weapon
{
	//	����
	class Gun :
		public WeaponBase
	{
	public:
		Gun(UnitBase& owner);
		~Gun();
		void Update();
	};
}