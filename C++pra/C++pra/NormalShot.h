#pragma once
#include "WeaponBase.h"
//	�ʏ�ˌ��U��
class NormalShot :
	public WeaponBase
{
public:
	NormalShot(D3DXVECTOR2 &pos,float speed, Bullet::TargetType targetType);
	~NormalShot();
	void Update();

};

