#include "BulletBase.h"
class BulletManager;

BulletBase::BulletBase()
{
	
}

BulletBase::BulletBase(float speed, Bullet::TargetType targetType, int moveType, D3DXVECTOR2 startPos,D3DXVECTOR2 targtPos)
{
	sprite.Load("bullet_01.png", 32, 32);
	Init(speed, targetType, moveType, startPos,targtPos);
}

BulletBase::~BulletBase()
{
	UnitBase::~UnitBase();
}


Bullet::TargetType BulletBase::GetTargetType()
{
	return targetType;
}

void BulletBase::Init(float speed, Bullet::TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
{
	position = startPos;
	this->speed = speed;
	nowSpeed = this->speed;
	this->targetType = targetType;
	exists = true;
	hp = 1;
	if (moveType == 1)
	{
		vec.x = 1;
		vec.y = 0;
	}
}

void BulletBase::Update()
{
	UpdatePosition();
	if (CheckScreenOut())
	{
		Deleat();
	}
}

void BulletBase::Render()
{
	UnitBase::Render();
}

void BulletBase::HitAction(int atk)
{
	UnitBase::HitAction(atk);
}

void BulletBase::Deleat()
{
	exists = false;
}

