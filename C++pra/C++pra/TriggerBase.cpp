#include "TriggerBase.h"
#include"BulletManager.h"
using namespace Unit::Bullet;

TriggerBase::TriggerBase()
{
	
}

TriggerBase::~TriggerBase()
{

}

bool TriggerBase::PullTrigger()
{
	if (shotPow.IsEnough(usePow) == false) return false;

	shotPow.Consume(usePow);

	Subject::Update();

	return true;
}

void TriggerBase::ChangeUsePow(float newPow)
{
	usePow = newPow;
}