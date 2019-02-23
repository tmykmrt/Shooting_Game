#pragma once
#include "UnitBase.h"
#include"stdafx.h"
#include"BulletManager.h"

class BulletManager;
/**
* @brief 弾の動き
* @details 弾の動き
*/
class BulletBase : public UnitBase
{
public:
	BulletBase();
	BulletBase(float speed, UnitType targetType,
		int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
	~BulletBase();
	//	更新
	void Update();
	//	描画
	void Render();
	//	初期化
	void Init(float speed, UnitType targetType,
		int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
	void Damage(int atk);
	void Deleat();

	UnitType GetTargetType();
private:
	//!	目標タイプ
	UnitType targetType;
	//!	移動の種類
	int moveType;
};

