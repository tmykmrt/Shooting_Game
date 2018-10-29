#include"stdafx.h"
#include "Player.h"
#include "Input.h"
#include"Collision.h"

Player::Player(TCHAR *name, int x, int y)
{
	sprite.Load(name, x, y);
	speed = 3;
	nowSpeed = speed;
	reloadValue = 0;
	hp = 10;
}

Player::~Player()
{
	UnitBase::~UnitBase();
}

void Player::SetBulletManager(BulletManager *bullet) 
{
	bulletManager = bullet;
}

void Player::Update()
{
	input.UpdateMouse();
	UpdateVecter();
	Shot();
	if (Collision::Circle(position.x, position.y, targetPosition.x, targetPosition.y, 2))nowSpeed = 0;
	else nowSpeed = speed;
	UpdatePosition();
}

void Player::Render()
{
	UnitBase::Render();
}

void Player::UpdateVecter()
{
	if (input.OnLeft() == false)return;
	targetPosition = input.GetMousePoint();
	float angle = atan2f(targetPosition.y - position.y, targetPosition.x - position.x);
	vec.x = cosf(angle);
	vec.y = sinf(angle);
}

void Player::Shot()
{
	reloadValue--;
	if (input.OnRight() == false) return;
	if(reloadValue > 0)return;
	bulletManager->Create(10,BulletManager::TargetType::Enemy,1,position,position);
	reloadValue = 60;
}

void Player::HitAction(int atk)
{
	UnitBase::HitAction(atk);
}
