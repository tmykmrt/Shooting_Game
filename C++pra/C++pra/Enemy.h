#pragma once
/**
* @file Enemy.h
* @brief エネミークラス
* @date 2018 9/23
*/
#include "UnitBase.h"
class Enemy : public UnitBase
{
public:
	Enemy();
	Enemy(int moveType, D3DXVECTOR2 startPos);
	~Enemy();

	//	初期化
	void Init(int moveType, D3DXVECTOR2 startPos);
	void Update();
	void Render();
	void HitAction(int atk);
private:
	//! 動くタイプ
	int moveType;
	//! 打つ種類
	int shotType;

};

