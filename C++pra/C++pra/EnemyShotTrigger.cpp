#include "EnemyShotTrigger.h"

EnemyShotTrigger::EnemyShotTrigger(D3DXVECTOR2 &pos) : ShotTriggerBase(pos)
{
	shotPow.Init(60, 300);
	speed = -10;
	usePow = 50;
	targetType = Bullet::Player;
}

EnemyShotTrigger::~EnemyShotTrigger()
{

}

void EnemyShotTrigger::Shot()
{
	if (shotPow.NowPow()->
		IsFull() == false) return;

	ShotTriggerBase::Shot();
}

void EnemyShotTrigger::Shot(D3DXVECTOR2 targetPos)
{
	if (shotPow.NowPow()->
		IsFull() == false) return;

	ShotTriggerBase::Shot(targetPos);
}
