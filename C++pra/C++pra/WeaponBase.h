#pragma once
#include "Obsever.h"
#include "BulletManager.h"
class WeaponBase : public Obsever
{
public:
	WeaponBase(UnitBase &owner);
	~WeaponBase();
	void Update();
protected:
	 UnitBase &owner;
};


