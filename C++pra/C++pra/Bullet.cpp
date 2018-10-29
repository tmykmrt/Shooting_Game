#include "Bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(float speed, BulletManager::TargetType targetType, int moveType, D3DXVECTOR2 startPos,D3DXVECTOR2 targtPos)
{
	sprite.Load("bullet_01.png", 32, 32);
	Init(speed, targetType, moveType, startPos,targtPos);
}

Bullet::~Bullet()
{
	UnitBase::~UnitBase();
}


void Bullet::SetBulletManager(BulletManager *bullet)
{ 
	bulletManager = bullet;
}

BulletManager::TargetType Bullet::GetTargetType()
{
	return targetType;
}

void Bullet::Init(float speed, BulletManager::TargetType targetType, int moveType, D3DXVECTOR2 startPos, D3DXVECTOR2 targtPos)
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

void Bullet::Update()
{
	UpdatePosition();
	if (CheckScreenOut())
	{
		Deleat();
	}
}

void Bullet::Render()
{
	UnitBase::Render();
}

void Bullet::HitAction(int atk)
{
	UnitBase::HitAction(atk);
}

void Bullet::Deleat()
{
	exists = false;
}

