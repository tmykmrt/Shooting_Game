#include"stdafx.h"
#include "PlayerBase.h"
#include "Input.h"
#include"Collision.h"

PlayerBase::PlayerBase(TCHAR *name, int x, int y)
{
	sprite.Load(name, x, y);
	speed = 3;
	nowSpeed = speed;
	reloadValue = 0;
	hp = 10;
}

PlayerBase::~PlayerBase()
{
	UnitBase::~UnitBase();
}

void PlayerBase::SetBulletManager(Bullet::BulletManager *bullet)
{
	bulletManager = bullet;
}

void PlayerBase::Update()
{
	UpdateVecter();
	Shot();
	if (Collision::Circle(position.x, position.y, targetPosition.x, targetPosition.y, 2))nowSpeed = 0;
	else nowSpeed = speed;
	UpdatePosition();
}

void PlayerBase::Render()
{
	UnitBase::Render();
}

void PlayerBase::UpdateVecter()
{
	if (Input::GetInstance()->OnLeft() == false)return;
	targetPosition = Input::GetInstance()->GetMousePoint();
	float angle = atan2f(targetPosition.y - position.y, targetPosition.x - position.x);
	vec.x = cosf(angle);
	vec.y = sinf(angle);
}

void PlayerBase::Shot()
{
	reloadValue--;
	if (Input::GetInstance()->OnRight() == false) return;
	if(reloadValue > 0)return;
	bulletManager->Create(10,Bullet::TargetType::Enemy,1,position,position);
	reloadValue = 60;
}

void PlayerBase::HitAction(int atk)
{
	UnitBase::HitAction(atk);
}
