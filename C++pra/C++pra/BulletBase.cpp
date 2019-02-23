#include "BulletBase.h"
class BulletManager;

BulletBase::BulletBase()
{
	
}

BulletBase::BulletBase(float speed, UnitType targetType, int moveType, D3DXVECTOR2 startPos,D3DXVECTOR2 targtPos)
{
	sprite.Load("Res/bullet_01.png", 32, 32);
	Init(speed, targetType, moveType, startPos,targtPos);
}

BulletBase::~BulletBase()
{
	UnitBase::~UnitBase();
}

UnitType BulletBase::GetTargetType()
{
	return targetType;
}

void BulletBase::Init(float speed, UnitType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
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
	if (moveType == 2)
	{
		float atan = atan2f(targtPos.y - startPos.y, targtPos.x - startPos.x);
		vec.x = cosf(atan);
		vec.y = sinf(atan);
	}
	if (moveType == 3)
	{
		vec.x = 1;
		vec.y = 1;
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

void BulletBase::Damage(int atk)
{
	UnitBase::Damage(atk);
}


void BulletBase::Deleat()
{
	exists = false;
}

