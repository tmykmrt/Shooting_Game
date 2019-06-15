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

