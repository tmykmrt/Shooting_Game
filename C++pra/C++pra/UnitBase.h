﻿
/**
* @file UnitBase.h
* @brief ユニット基底クラス
* @date 2018 8/25
*/

#pragma once
#include "Sprite.h"
#include"stdafx.h"
#include"NumRange.h"
#include"TriggerBase.h"

namespace Collision {
	class Shape;
}
class NumRange;
class TriggerBase;

namespace Unit
{
	enum class UnitType
	{
		None,
		Player,
		Enemy,
		Bullet,
	};

	//	攻撃に必要な情報
	struct AttackUseInfo
	{
		//	方向
		byte dir;
		//	座標
		D3DXVECTOR2 attckPosition;
		//	目標の座標
		D3DXVECTOR2 targetPosition;
		//	オーナーのタイプ
		UnitType ownerType;
	};

	class UnitBase
	{
	public:
		UnitBase();
		virtual ~UnitBase();
		//	更新
		virtual void Update() = 0;
		//	描画
		virtual void Render() = 0;
		//	当たり判定生成
		virtual void CreateShape() = 0;
		// ダメージ
		virtual void Damage(int atk);
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
		//	目標を設定する
		void SetAttackTarget();
		//	攻撃に必要な情報を取得
		AttackUseInfo FetchAttackUseInfo();
	protected:
		//!座標
		D3DXVECTOR2 position;
		//	移動ベクトル
		D3DXVECTOR2 vec;
		//!画像
		Sprite sprite;
		//	方向
		byte dir;
		//!速度
		float speed;
		//! 現在の速度
		float nowSpeed;
		//! 体力
		NumRange hp;
		//! 存在しているか
		bool exists;
		//	自身のタイプ
		UnitType myType;
		Collision::Shape *shape;
	};
}
