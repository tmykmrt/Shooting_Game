#pragma once
#include "WeaponBase.h"
//	’ÊíËŒ‚UŒ‚
class NormalShot :
	public WeaponBase
{
public:
	NormalShot(UnitBase& owner) ;
	~NormalShot();
	void Update();

};

