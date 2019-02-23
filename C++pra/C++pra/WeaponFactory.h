#pragma once
#include"stdafx.h"
#include"WeaponBase.h"

class WeaponFactory : public Singleton<WeaponFactory>
{
public:
	//	武器の種類
	enum WeaponType
	{
		//	真っすぐな銃
		Gun,
		//	ホーミング機能の銃
		HomingGun,
		//	狙う銃
		AimGun,
		//	ビーム
		Beam,
	};

	friend class Singleton<WeaponFactory>;
	//	武器の生成
	WeaponBase* Create(WeaponType createType);
protected:
	WeaponFactory();
	~WeaponFactory();

};

