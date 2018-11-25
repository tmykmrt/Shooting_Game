#pragma once
#include "UnitBase.h"
#include "stdafx.h"
#include "Input.h"
#include "BulletManager.h"
#include "Animation2D.h"
class Animation2D;

class PlayerController : public UnitBase
{
public:
	PlayerController(TCHAR *name, int x, int y);
	~PlayerController();
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
	Bullet::BulletManager *bulletManager;
	//	
	int reloadValue;
	int animnum;
	Animation2D *anim;
	Animation2DData tmpD[2];
};

