#include "BulletManager.h"
#include "UnitBase.h"
#include "BulletBase.h"
Bullet::BulletManager::BulletManager()
{
	//bulletList = new list<Bullet>;
	for (int i = 0; i < bulletNum; i++)
	{
		bulletList[i] = NULL;
	}
}


Bullet::BulletManager::~BulletManager()
{
	//bulletList.clear();
	//delete bulletList;
	delete[] bulletList;
}

//	更新
void Bullet::BulletManager::Update()
{
	//list<Bullet>::iterator itr;
	//for (itr = bulletList.begin(); itr != bulletList.end(); itr++)
	//{
	//	if (itr->Exists() == false)
	//	{
	//		itr =  bulletList.erase(itr);
	//		itr--;
	//	}
	//	else
	//	{
	//		itr->Update();
	//	}
	//}
	
	for (int i = 0; i < bulletNum;i++)
	{
		if (bulletList[i] == NULL)continue;
		if (bulletList[i]->Exists() == false)
		{
			delete bulletList[i];
			bulletList[i] = NULL;
		}
		else
		{
			bulletList[i]->Update();
		}
	}
}


BulletBase* Bullet::BulletManager::Getbullet(int num)
{
	if (num < 0 || num >= bulletNum)return NULL;
	return bulletList[num];
}


//	描画
void Bullet::BulletManager::Render()
{
	//list<Bullet>::iterator itr;
	//for (itr = bulletList.begin(); itr != bulletList.end(); itr++)
	//{
	//	itr->Render();
	//}
	for (int i = 0; i < bulletNum; i++)
	{
		if (bulletList[i] == NULL)continue;
		bulletList[i]->Render();
	}
}

//	追加
void Bullet::BulletManager::Create(float speed, Bullet::TargetType targetType, int moveType,
	D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
{
	//Bullet *bullet = new Bullet(speed, targetType, moveType, startPos, targtPos);
	//bullet->SetBulletManager(this);
	//bulletList.push_back(*bullet);
	for (int i = 0; i < bulletNum; i++)
	{
		if (bulletList[i] == NULL)
		{
			bulletList[i] = new BulletBase(speed, targetType, moveType, startPos, targtPos);
			break;
		}
	}
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
