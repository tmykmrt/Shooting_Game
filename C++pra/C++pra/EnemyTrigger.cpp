#include "EnemyTrigger.h"
using namespace Unit;

EnemyTrigger::EnemyTrigger(UnitBase* ower)
{
	shotPow.Init(60, 300);
	TriggerBase::ChangeUsePow(50);
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

