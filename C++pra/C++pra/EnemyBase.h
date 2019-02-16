#pragma once
/**
* @file Enemy.h
* @brief エネミークラス
* @date 2018 9/23
*/
#include "UnitBase.h"
#include "EnemyShotTrigger.h"
#include "MovementBase.h"
class EnemyBase : public UnitBase
{
public:
	EnemyBase();
	EnemyBase(int moveType, D3DXVECTOR2 startPos);
	~EnemyBase();
	//	初期化
	void Init(int moveType, D3DXVECTOR2 startPos);
	void Update();
	void Render();
	void Damage(int atk);
private:
	//! 動くタイプ
	int moveType;
	//! 打つ種類
	int shotType;
	//! 移動
	MovementBase* mover;
	EnemyShotTrigger *shot;
};

