#include "PlayerTrigger.h"
#include "Input.h"
#include "ShotPower.h"
#include "BulletManager.h"
#include "Timer.h"
#include "Animation2D.h"
#include "GameUIManager.h"
#include "NormalShot.h"

PlayerTrigger::PlayerTrigger(D3DXVECTOR2 &pos)
	: TriggerBase(pos)
{
	shotPow.Init(100, 600);
	timer.SetCountFrame(60);
	NormalShot *s = new NormalShot(pos, 3,Bullet::Enemy);
	NormalShot *s2 = new NormalShot(pos, 10, Bullet::Enemy);

	Subject::AddObserver(s);
	Subject::AddObserver(s2);
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
