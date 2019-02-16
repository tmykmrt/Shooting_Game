#include "ShotTriggerBase.h"
#include"BulletManager.h"
using namespace Bullet;

ShotTriggerBase::ShotTriggerBase(D3DXVECTOR2 &pos) : shotPos(pos)
{

}

ShotTriggerBase::~ShotTriggerBase()
{

}

bool ShotTriggerBase::Shot()
{
	if (shotPow.IsEnough(usePow) == false) return false;

	shotPow.Consume(usePow);

	BulletManager::GetInstance()
		->Create(speed, targetType, 1, shotPos, shotPos);

	return true;
}

bool ShotTriggerBase::Shot(D3DXVECTOR2& targetPos)
{
	if (shotPow.IsEnough(usePow) == false) return false;

	shotPow.Consume(usePow);

	BulletManager::GetInstance()
		->Create(5, targetType, 2, shotPos, targetPos);

	return true;
}
