#pragma once
#include "UnitBase.h"
#include"stdafx.h"
#include"BulletManager.h"
class BulletManager;

/**
* @brief 弾の動き
* @details 弾の動き
*/
class Bullet : public UnitBase
{
public:

	Bullet();
	Bullet(float speed, BulletManager::TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
	~Bullet();
	//	更新
	void Update();
	//	描画
	void Render();
	//	初期化
	void Init(float speed, BulletManager::TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
	void SetBulletManager(BulletManager *bullet);
	void HitAction(int atk);
	void Deleat();
	BulletManager::TargetType GetTargetType();
private:
	//!	目標タイプ
	BulletManager::TargetType targetType;
	//!	移動の種類
	int moveType;
	//!	マネージャーのキャッシュ
	BulletManager *bulletManager;
};

