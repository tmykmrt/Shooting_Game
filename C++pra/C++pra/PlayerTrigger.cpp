#include "PlayerTrigger.h"
#include "Input.h"
#include "ShotPower.h"
#include "BulletManager.h"
#include "Timer.h"
#include "Animation2D.h"
#include "GameUIManager.h"
#include "WeaponFactory.h"
PlayerTrigger::PlayerTrigger(UnitBase *owner)
{
	shotPow.Init(100, 600);
	timer.SetCountFrame(60);

	//	‚Ð‚Æ‚Ü‚¸‰¼‚Åì¬
	WeaponBase *weapon 
		= WeaponFactory::GetInstance()->Create(WeaponFactory::Gun, owner);


	Subject::AddObserver(weapon);
}

PlayerTrigger::~PlayerTrigger()
{

}

void PlayerTrigger::TriggerIfPossible()
{
	shotPow.Chage();
	PullTrigger();
	GameUIManager::GetInstance()->UpdatePowBar(shotPow.Rate());
}

void PlayerTrigger::PullTrigger()
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
	if (TriggerBase::PullTrigger())
	{
		reloadFrame = 20;
	}
}
