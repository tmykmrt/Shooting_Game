#include "PlayerTrigger.h"
#include "Input.h"
#include "ShotPower.h"
#include "BulletManager.h"
#include "Timer.h"
#include "Animation2D.h"
#include "GameUIManager.h"
#include "WeaponFactory.h"
using namespace Unit;
PlayerTrigger::PlayerTrigger(UnitBase *owner)
{
	shotPow.Init(100, 600);
	timer.SetCountFrame(60);

	//	‚Ð‚Æ‚Ü‚¸‰¼‚Åì¬
	WeaponBase *weapon 
		= WeaponFactory::GetInstance()->Create(WeaponFactory::Gun, owner,D3DXVECTOR2(1,0));
	WeaponBase *weapon2
		= WeaponFactory::GetInstance()->Create(WeaponFactory::AimGun, owner, D3DXVECTOR2(1, 1));

	Subject::AddObserver(weapon);
	Subject::AddObserver(weapon2);
}

PlayerTrigger::~PlayerTrigger()
{

}

//	‰Â”\‚È‚çˆø‚«‹à‚ðˆø‚­
void PlayerTrigger::TriggerIfPossible()
{
	shotPow.Chage();
	PullTrigger();
	GameUIManager::GetInstance()->UpdatePowBar(shotPow.Rate());
}

//	ˆø‚«‹à‚ðˆø‚­
void PlayerTrigger::PullTrigger()
{
	reloadFrame--;
	if (reloadFrame > 0) return;
	if (Input::GetInstance()->OnJustRight())
	{
		TriggerBase::ChangeUsePow(10);
		timer.SetCountFrame(60);
	}

	if (Input::GetInstance()->OnRight())
	{
		if (timer.CheckFrameOut())
		{
			TriggerBase::ChangeUsePow(80);
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
