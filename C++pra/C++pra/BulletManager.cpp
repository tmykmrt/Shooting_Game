#include "BulletManager.h"
#include "UnitBase.h"
#include "BulletBase.h"

Bullet::BulletManager::BulletManager()
{
	bulletLists = new list<BulletBase>;
	for (int i = 0; i < bulletNum; i++)
	{
		bulletList[i] = NULL;
	}
}

Bullet::BulletManager::~BulletManager()
{
	bulletLists->clear();
	delete bulletLists;
	//delete[] bulletList;
}

//	更新
void Bullet::BulletManager::Update()
{
	list<BulletBase>::iterator itr;
	for (itr = bulletLists->begin(); itr != bulletLists->end();)
	{
		if (itr->Exists() == false)
		{
			itr =  bulletLists->erase(itr);
			continue;
		}
		else
		{
			itr->Update();
		}
		itr++;
	}
	
	//for (int i = 0; i < bulletNum;i++)
	//{
	//	if (bulletList[i] == NULL)continue;
	//	if (bulletList[i]->Exists() == false)
	//	{
	//		delete bulletList[i];
	//		bulletList[i] = NULL;
	//	}
	//	else
	//	{
	//		bulletList[i]->Update();
	//	}
	//}
}


BulletBase* Bullet::BulletManager::Getbullet(int index)
{
	//if (num < 0 || num >= bulletNum) return NULL;
	//return bulletList[num];
	if (bulletLists->size() <= index) return NULL;
	list<BulletBase>::iterator itr = bulletLists->begin();
	std::advance(itr, index);
	
	return NULL;
}


//	描画
void Bullet::BulletManager::Render()
{
	list<BulletBase>::iterator itr;
	for (itr = bulletLists->begin(); itr != bulletLists->end(); itr++)
	{
		itr->Render();
	}
	//for (int i = 0; i < bulletNum; i++)
	//{
	//	if (bulletList[i] == NULL)continue;
	//	bulletList[i]->Render();
	//}
}

//	追加
void Bullet::BulletManager::Create(float speed, Bullet::TargetType targetType, int moveType,
	D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
{
	BulletBase *bullet = new BulletBase(speed, targetType, moveType, startPos, targtPos);
	bulletLists->push_back(*bullet);
	//for (int i = 0; i < bulletNum; i++)
	//{
	//	if (bulletList[i] == NULL)
	//	{
	//		bulletList[i] = new BulletBase(speed, targetType, moveType, startPos, targtPos);
	//		break;
	//	}
	//}
}

//	削除
void Bullet::BulletManager::Remove(BulletBase *bullet)
{
	//bulletList->remove(*bullet);
	////delete[] bullet;
	//for (int i = 0; i < bulletNum; i++)
	//{
	//	if (bullets[i] == bullet)
	//	{
	//		delete bullets;
	//		bullets[i] = NULL;
	//		break;
	//	}
	//}
}
