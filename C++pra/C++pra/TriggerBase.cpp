#include "TriggerBase.h"
#include"BulletManager.h"
using namespace Bullet;

TriggerBase::TriggerBase(D3DXVECTOR2 &pos) : shotPos(pos)
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

