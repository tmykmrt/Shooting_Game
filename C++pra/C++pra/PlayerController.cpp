#include"stdafx.h"
#include "PlayerController.h"
#include "Input.h"
#include"Collision.h"
#include"Animation2D.h"


PlayerController::PlayerController(TCHAR *name, int x, int y)
{
	anim = new Animation2D(name, x, y, 128, 128);

	//	ひとまずテスト用でデータ生成
	
	tmpD[0].animaNum = 1;
	tmpD[0].pagesNum = 10;
	tmpD[0].frame = 5;

	tmpD[1].animaNum = 2;
	tmpD[1].pagesNum = 10;
	tmpD[1].frame = 5;
	anim->SetAnimaData(tmpD);
	anim->SetAima(0);

	//sprite.Load(name, x, y);
	//sprite.size = { 128,128 };
	speed = 3;
	nowSpeed = speed;
	reloadValue = 0;
	hp = 10;
	animnum = 0;
}

PlayerController::~PlayerController()
{
	delete anim;
	UnitBase::~UnitBase();
}

void PlayerController::SetBulletManager(Bullet::BulletManager *bullet)
{
	bulletManager = bullet;
}

void PlayerController::Update()
{
	UpdateVecter();
	Shot();
	if (Collision::Circle(position.x, position.y, targetPosition.x, targetPosition.y, 2))
	{
		anim->SetAima(0);
		nowSpeed = 0;
	}
	else nowSpeed = speed;
	UpdatePosition();
}

void PlayerController::Render()
{
	anim->Render(position);
	//animnum++;
	//sprite.pos = position;
	//int num = animnum / 10;
	//num = num == 0 ? 1 : num;
	//sprite.DrawCenter(1, num);
	//if (animnum > 10 * 10)
	//{
	//	animnum = 0;
	//}
	//UnitBase::Render();
}

void PlayerController::UpdateVecter()
{
	if (Input::GetInstance()->OnLeft() == false)return;
	targetPosition = Input::GetInstance()->GetMousePoint();
	float angle = atan2f(targetPosition.y - position.y, targetPosition.x - position.x);
	vec.x = cosf(angle);
	vec.y = sinf(angle);
	anim->SetAima(1);
}

void PlayerController::Shot()
{
	reloadValue--;
	if (Input::GetInstance()->OnRight() == false) return;
	if(reloadValue > 0)return;
	bulletManager->Create(10,Bullet::TargetType::Enemy,1,position,position);
	reloadValue = 60;
}

void PlayerController::HitAction(int atk)
{
	UnitBase::HitAction(atk);
}
