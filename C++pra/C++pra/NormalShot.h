#pragma once
#include "WeaponBase.h"
//	�ʏ�ˌ��U��
class NormalShot :
	public WeaponBase
{
public:
	NormalShot(UnitBase& owner) ;
	~NormalShot();
	void Update();

};

