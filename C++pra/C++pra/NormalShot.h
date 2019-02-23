#pragma once
#include "WeaponBase.h"
//	’ÊíËŒ‚UŒ‚
class NormalShot :
	public WeaponBase
{
public:
	NormalShot(D3DXVECTOR2 &pos,float speed, Bullet::TargetType targetType);
	~NormalShot();
	void Update();

};

