#pragma once
#include "UnitBase.h"
#include "stdafx.h"
#include "Input.h"
#include "BulletManager.h"
class Player : public UnitBase
{
public:
	Player(TCHAR *name, int x, int y);
	~Player();
	//	�X�V
	void Update();
	//	�`��
	void Render();

	void UpdateVecter();

	void Shot();
	void SetBulletManager(BulletManager *bullet);
	void HitAction(int atk);
private:
	//	
	D3DXVECTOR2 targetPosition;
	Input input;
	BulletManager *bulletManager;
	//	
	int reloadValue;
};

