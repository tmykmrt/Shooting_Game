#pragma once
#include"stdafx.h"
/**
* @file MovementBase.h
* @brief 動作基底クラス
* @date 2018 11/03
*/
class MovementBase
{
public:
	MovementBase();
	MovementBase(float speed);
	~MovementBase();
	//! 移動ベクトル更新
	virtual void Move(D3DXVECTOR2 &vec) = 0;
private:
	//! ベクトル
	D3DXVECTOR2 vec;
	//!速度
	float speed;
	//! 現在の速度
	float nowSpeed;
};

