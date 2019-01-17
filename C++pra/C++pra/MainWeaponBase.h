#pragma once
#include"stdafx.h"
class SubWeaponBase;

class MainWeaponBase
{
public:
	MainWeaponBase();
	~MainWeaponBase();

	//virtual ~MainWeaponBase();

	virtual void AddSubWeapon(SubWeaponBase* subWeapon)
	{
		subWeaponList.push_back(subWeapon);
		



	}

protected:
	list<SubWeaponBase*> subWeaponList;
};

