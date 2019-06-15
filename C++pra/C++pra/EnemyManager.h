#pragma once
#include"EnemyBase.h"
#include"stdafx.h"
class Enemy;

namespace Unit
{
	namespace Enemy
	{
		class EnemyManager : public Singleton<EnemyManager>
		{
		public:
			friend class Singleton<EnemyManager>;
			void Update();
			void Render();
			void Create(int moveType, D3DXVECTOR2 startPos);
			void RandCreae();
			EnemyBase* GetEnemy(int num);
			//	敵数
			static const int enemyMax = 5;
		protected:
			EnemyManager();
			~EnemyManager();
		private:

			//	敵配列
			EnemyBase *enemys[enemyMax];
		};
	}
}
