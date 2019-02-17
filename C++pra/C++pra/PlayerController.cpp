#include"stdafx.h"
#include "PlayerController.h"
#include "Input.h"
#include"Collision.h"
#include"Animation2D.h"
#include"GameUIManager.h"

PlayerController::PlayerController(TCHAR *name, int x, int y)
{
	anim = new Animation2D(name, x, y, 128, 128);
	limitPoint = new LimitPoint();
	//	ひとまずテスト用でデータ生成
	tmpD[0].animaNum = 1;
	tmpD[0].pagesNum = 10;
	tmpD[0].frame = 5;

	tmpD[1].animaNum = 2;
	tmpD[1].pagesNum = 10;
	tmpD[1].frame = 5;

	anim->SetAnimaData(tmpD);
	anim->SetAima(0);
	trigger = new PlayerTrigger(position);
	speed = 3;
	nowSpeed = speed;
	hp.Set(10,10,0);
	GameUIManager::GetInstance()->UpdateHpBar(hp.Rate());
	animnum = 0;
}

PlayerController::~PlayerController()
{
	delete anim;
	delete limitPoint;
	UnitBase::~UnitBase();
}

//	更新
void PlayerController::Update()
{
	UpdateVecter();
	//	可能なら射撃する
	trigger->TriggerIfPossible();

	//	一先ずの処理----------------
	limitPoint->Update();
	limitPoint->LimitReleasing();
	//	---------------------------

	if (Collision::Circle(position.x, position.y, targetPosition.x, targetPosition.y, 2))
	{
		anim->SetAima(0);
		nowSpeed = 0;
	}
	else
	{
		nowSpeed = speed;
	}

	UpdatePosition();
}

//	描画
void PlayerController::Render()
{
	anim->Render(position);
}

//	移動方向の更新
void PlayerController::UpdateVecter()
{
	if (Input::GetInstance()->OnLeft() == false)return;
	targetPosition = Input::GetInstance()->GetMousePoint();
	float angle = atan2f(targetPosition.y - position.y, targetPosition.x - position.x);
	vec.x = cosf(angle);
	vec.y = sinf(angle);
	anim->SetAima(1);
}


void PlayerController::Damage(int atk)
{
	UnitBase::Damage(atk);
	GameUIManager::GetInstance()->UpdateHpBar(hp.Rate());
}

void PlayerController::ChageLimit()
{
	limitPoint->Recovery(10);
}