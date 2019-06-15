#pragma once
/**
* @file Enemy.h
* @brief エネミークラス
* @date 2018 9/23
*/
#include "UnitBase.h"
#include "EnemyTrigger.h"
#include "MovementBase.h"

namespace Unit
{
	namespace Enemy
	{
		class EnemyBase : public UnitBase
		{
		public:
			EnemyBase();
			EnemyBase(int moveType, D3DXVECTOR2 startPos);
			~EnemyBase();
			//	初期化
			void Update();
			void Render();
			void Damage(int atk);
			void CreateShape();
		private:
			void Init(int moveType, D3DXVECTOR2 startPos);
			//! 動くタイプ
			int moveType;
			//! 打つ種類
			int shotType;
			//! 移動
			MovementBase* mover;
			EnemyTrigger *trigger;
		};
	}
}

