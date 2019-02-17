#include "EnemyTrigger.h"

EnemyTrigger::EnemyTrigger(D3DXVECTOR2 &pos) : TriggerBase(pos)
{
	shotPow.Init(60, 300);
	usePow = 50;
}

EnemyTrigger::~EnemyTrigger()
{

}

void EnemyTrigger::PullTrigger()
{
	if (shotPow.NowPow()->
		IsFull() == false) return;

	TriggerBase::PullTrigger();
}

void EnemyTrigger::TriggerIfPossible()
{
	shotPow.Chage();
	PullTrigger();
}

