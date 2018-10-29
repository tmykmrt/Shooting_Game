#include "BulletManager.h"
BulletManager::BulletManager()
{
	//bulletList = new list<Bullet>;
	for (int i = 0; i < bulletNum; i++)
	{
		bullets[i] = NULL;
	}
}


BulletManager::~BulletManager()
{
	//bulletList.clear();
	//delete bulletList;
	delete[] bullets;
}

//	XV
void BulletManager::Update()
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
		if (bullets[i] == NULL)continue;
		if (bullets[i]->Exists() == false)
		{
			delete bullets[i];
			bullets[i] = NULL;
		}
		else
		{
			bullets[i]->Update();
		}
	}
}


Bullet* BulletManager::Getbullet(int num)
{
	if (num < 0 || num >= bulletNum)return NULL;
	return bullets[num];
}


//	•`‰æ
void BulletManager::Render()
{
	//list<Bullet>::iterator itr;
	//for (itr = bulletList.begin(); itr != bulletList.end(); itr++)
	//{
	//	itr->Render();
	//}
	for (int i = 0; i < bulletNum; i++)
	{
		if (bullets[i] == NULL)continue;
		bullets[i]->Render();
	}
}

//	’Ç‰Á
void BulletManager::Create(float speed, TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
{
	//Bullet *bullet = new Bullet(speed, targetType, moveType, startPos, targtPos);
	//bullet->SetBulletManager(this);
	//bulletList.push_back(*bullet);
	for (int i = 0; i < bulletNum; i++)
	{
		if (bullets[i] == NULL)
		{
			bullets[i] = new Bullet(speed, targetType, moveType, startPos, targtPos);
			break;
		}
	}
}

//	íœ
void BulletManager::Remove(Bullet *bullet)
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
