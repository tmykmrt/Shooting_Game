#pragma once
/**
* @file Enemy.h
* @brief �G�l�~�[�N���X
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
			//	������
			void Update();
			void Render();
			void Damage(int atk);
			void CreateShape();
		private:
			void Init(int moveType, D3DXVECTOR2 startPos);
			//! �����^�C�v
			int moveType;
			//! �ł��
			int shotType;
			//! �ړ�
			MovementBase* mover;
			EnemyTrigger *trigger;
		};
	}
}

