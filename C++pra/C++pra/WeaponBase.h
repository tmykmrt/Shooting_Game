#pragma once
#include "Obsever.h"
#include "BulletManager.h"

class WeaponBase : public Obsever
{
public:
	WeaponBase(Unit::UnitBase &owner, D3DXVECTOR2 dirVec);
	~WeaponBase();
	void Update();
	//	オーナー登録
	void RegisterOwner(Unit::UnitBase &newOwner);
protected:
	//	武器の所持者
	Unit::UnitBase &owner;
	//	自身の方向ベクトル
	D3DXVECTOR2 dirVec;
};


