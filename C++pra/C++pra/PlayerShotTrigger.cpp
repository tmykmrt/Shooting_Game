#include "PlayerShotTrigger.h"
#include "Input.h"
#include "ShotPower.h"
#include "BulletManager.h"
#include "Timer.h"
#include "Animation2D.h"
#include "GameUIManager.h"

PlayerShotTrigger::PlayerShotTrigger(D3DXVECTOR2 &pos) 
	: ShotTriggerBase(pos)
{
	speed = 10;
	shotPow.Init(100, 600);
	timer.SetCountFrame(60);
	targetType = Bullet::Enemy;
	
}

PlayerShotTrigger::~PlayerShotTrigger()
{

}

void PlayerShotTrigger::AttackUpdate()
{
	shotPow.Chage();
	Shot();
	GameUIManager::GetInstance()->UpdatePowBar(shotPow.Rate());
}

void PlayerShotTrigger::Shot()
{
	reloadFrame--;
	if (reloadFrame > 0) return;
	if (Input::GetInstance()->OnJustRight())
	{
		usePow = 10;
		timer.SetCountFrame(60);
	}

	if (Input::GetInstance()->OnRight())
	{
		if (timer.CheckFrameOut())
		{
			usePow = 80;
		}
	}
	if (Input::GetInstance()->UpRight() == false)
	{
		return;
	}
	if (ShotTriggerBase::Shot())
	{
		reloadFrame = 20;
	}
}
