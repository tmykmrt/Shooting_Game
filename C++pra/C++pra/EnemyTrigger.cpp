#include "EnemyTrigger.h"

EnemyTrigger::EnemyTrigger(UnitBase* ower)
{
	shotPow.Init(60, 300);
	usePow = 50;
}

EnemyTrigger::~EnemyTrigger()
{

}
//	������������
void EnemyTrigger::PullTrigger()
{
	if (shotPow.NowPow()->
		IsFull() == false) return;
	TriggerBase::PullTrigger();
}

//	�\�Ȃ������������
void EnemyTrigger::TriggerIfPossible()
{
	shotPow.Chage();
	PullTrigger();
}

