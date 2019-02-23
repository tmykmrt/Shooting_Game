#include "EnemyTrigger.h"

EnemyTrigger::EnemyTrigger(D3DXVECTOR2 &pos) : TriggerBase(pos)
{
	shotPow.Init(60, 300);
	usePow = 50;
}

EnemyTrigger::~EnemyTrigger()
{

}
//	引き金を引く
void EnemyTrigger::PullTrigger()
{
	if (shotPow.NowPow()->
		IsFull() == false) return;
	TriggerBase::PullTrigger();
}

//	可能なら引き金を引く
void EnemyTrigger::TriggerIfPossible()
{
	shotPow.Chage();
	PullTrigger();
}

