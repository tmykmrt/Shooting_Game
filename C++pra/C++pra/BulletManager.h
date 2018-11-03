#pragma once
#include"stdafx.h"
#include "UnitBase.h"
class BulletBase ;
/**
* @brief 弾の管理
* @details 弾の更新、描画、生成を行う
*/
namespace Bullet
{
	enum TargetType
	{
		None,
		Player,
		Enemy,
	};

	class BulletManager
	{
	public:
		const static int bulletNum = 5;
		BulletManager();
		~BulletManager();
		//	作成
		void Create(float speed, TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos);
		void Render();
		void Update();
		void Remove(BulletBase *bullet);
		BulletBase* Getbullet(int num);
	private:
		//	弾のは配列
		BulletBase *bulletList[bulletNum];

		//list<Bullet> bulletList;
	};
}