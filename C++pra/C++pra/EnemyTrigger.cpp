#include "EnemyTrigger.h"

EnemyTrigger::EnemyTrigger(D3DXVECTOR2 &pos) : TriggerBase(pos)
{
	shotPow.Init(60, 300);
	usePow = 50;
}

EnemyTrigger::~EnemyTrigger()
{

}
//	ˆø‚«‹à‚ðˆø‚­
void EnemyTrigger::PullTrigger()
{
	if (shotPow.NowPow()->
		IsFull() == false) return;
	TriggerBase::PullTrigger();
}

//	‰Â”\‚È‚çˆø‚«‹à‚ðˆø‚­
void EnemyTrigger::TriggerIfPossible()
{
	shotPow.Chage();
	PullTrigger();
}

