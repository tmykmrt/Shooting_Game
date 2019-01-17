#include "ShotBase.h"
#include"BulletManager.h"
using namespace Bullet;
ShotBase::ShotBase()
{
}


ShotBase::~ShotBase()
{
}

void ShotBase::Shot(D3DXVECTOR2 shotPosition)
{
	BulletManager::GetInstance()
		->Create(10, Bullet::TargetType::Enemy, 1, shotPosition, shotPosition);
}
