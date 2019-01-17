
/**
* @file UnitBase.h
* @brief ユニット基底クラス
* @date 2018 8/25
*/

#pragma once
#include "Sprite.h"
#include"stdafx.h"
#include"HitPoint.h"
class HitPoint;

class UnitBase
{
public:
	UnitBase();
	virtual ~UnitBase();
	//	更新
	virtual void Update() = 0;
	//	描画
	virtual void Render() = 0;
	//	
	virtual void HitAction(int atk);

	D3DXVECTOR2 GetPosition();
	//	比較
	const bool UnitBase::operator == (const UnitBase& b)
	{
		return this == &b;
	}
	//	生存しているか
	bool Exists();
	//! 画面外確認
	bool CheckScreenOut();
	//! 座標更新
	void UpdatePosition();
protected:
	//!座標
	D3DXVECTOR2 position;
	//	移動ベクトル
	D3DXVECTOR2 vec;
	//!画像
	Sprite sprite;
	//!速度
	float speed;
	//! 現在の速度
	float nowSpeed;
	//! 体力
	HitPoint hp;
	//! 存在しているか
	bool exists;
};

