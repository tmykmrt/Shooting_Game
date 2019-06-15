#include "BulletManager.h"
#include "UnitBase.h"
#include "BulletBase.h"
#include <list>
#include <stdio.h>
#include <conio.h>
#include <iterator>

namespace Unit
{
	namespace Bullet
	{
		BulletManager::BulletManager()
		{
		}

		BulletManager::~BulletManager()
		{
			bulletLists.clear();
		}

		//	更新
		void BulletManager::Update()
		{
			list<Unit::Bullet::BulletBase*>::iterator itr;
			for (itr = bulletLists.begin(); itr != bulletLists.end();)
			{
				if ((*itr)->Exists() == false)
				{
					itr = bulletLists.erase(itr);
					continue;
				}
				else
				{
					(*itr)->Update();
				}
				itr++;
			}
		}

		//	描画
		void BulletManager::Render()
		{
			for (auto itr = bulletLists.begin(); itr != bulletLists.end(); itr++)
			{
				(*itr)->Render();
			}
		}

		void BulletManager::Create(float speed, UnitType targetType, int moveType,
			D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
		{
			BulletBase *bullet = new BulletBase(speed, targetType, moveType, startPos, targtPos);
			bulletLists.push_back(bullet);
		}
	}
}
