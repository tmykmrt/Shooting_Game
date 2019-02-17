#include "NormalShot.h"
#include "BulletManager.h"

NormalShot::NormalShot(D3DXVECTOR2 &pos,float speed,Bullet::TargetType targetType)
	: WeaponBase(pos)
{
	this->speed = speed;
	this->targetType = targetType;
}


NormalShot::~NormalShot()
{

}

void NormalShot::Update()
{
	Bullet::BulletManager::GetInstance()
		->Create(speed, targetType, 1, shotPos, shotPos);
}
