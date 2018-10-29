#include "Enemy.h"

Enemy::Enemy()
{
	
}

Enemy::Enemy(int moveType, D3DXVECTOR2 startPos)
{
	speed = 4;
	sprite.Load("bullet_01.png", 32, 32);
	Init(moveType, startPos);
}

Enemy::~Enemy()
{
	UnitBase::~UnitBase();
}

//
void Enemy::Init(int moveType, D3DXVECTOR2 startPos)
{
	this->moveType = moveType;
	position = startPos;
	exists = true;
	hp = 1;
	if (moveType == 1)
	{
		vec = D3DXVECTOR2(-1, 0);
		nowSpeed = speed;
	}
}

void Enemy::Update()
{
	UpdatePosition();
	if (CheckScreenOut())
	{
		exists = false;
	}
}	//

void Enemy::Render()
{
	UnitBase::Render();
}

void Enemy::HitAction(int atk)
{
	UnitBase::HitAction(atk);
}

