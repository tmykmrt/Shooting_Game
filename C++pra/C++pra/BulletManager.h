﻿#pragma once
#include"stdafx.h"
#include "UnitBase.h"
enum UnitType;
/**
* @brief 弾の管理
* @details 弾の更新、描画、生成を行う
*/
namespace Unit
{
	namespace Bullet
	{
		class BulletBase;
		class BulletManager : public Singleton<BulletManager>
		{
		public:
			const static int bulletNum = 5;
			friend class Singleton<BulletManager>;
			//	作成
			void Create(float speed, UnitType targetType,
				int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);

			void Render();
			void Update();
		protected:
			BulletManager();
			~BulletManager();
		private:
			list<Unit::Bullet::BulletBase*> bulletLists;
		};
	}
}