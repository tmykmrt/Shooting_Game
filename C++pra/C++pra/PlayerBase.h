#pragma once
#include "UnitBase.h"
#include "stdafx.h"
#include "Input.h"
#include "BulletManager.h"
class PlayerBase : public UnitBase
{
public:
	PlayerBase(TCHAR *name, int x, int y);
	~PlayerBase();
	//	更新
	void Update();
	//	描画
	void Render();

	void UpdateVecter();

	void Shot();
	void SetBulletManager(Bullet::BulletManager *bullet);
	void HitAction(int atk);
private:
	//	
	D3DXVECTOR2 targetPosition;
	Input input;
	Bullet::BulletManager *bulletManager;
	//	
	int reloadValue;
};

