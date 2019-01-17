#include "HitPoint.h"
#include"Math.h"
HitPoint::HitPoint()
{
}

HitPoint::HitPoint(float maxHp)
{
	Set(maxHp);
}

HitPoint::~HitPoint()
{

}

void HitPoint::Set(float maxHp)
{
	this->nowHp = maxHp;
	this->maxHp = maxHp;
}

void HitPoint::AddHp(float add)
{
	nowHp += add;
	nowHp = Math::Clamp<float>(nowHp, 0.0f, maxHp);
}
void HitPoint::SubHp(float sub)
{
	nowHp -= sub;
	nowHp = Math::Clamp<float>(nowHp, 0.0f, maxHp);
}

void HitPoint::AddMaxHp(float add)
{
	maxHp += add;
}

void HitPoint::SubMaxHp(float sub)
{
	maxHp -= sub;
	maxHp = Math::Clamp<float>(maxHp, 0, maxHp);
}

float HitPoint::GetNowHp()
{
	return maxHp;
}

void HitPoint::Full()
{
	nowHp = maxHp;
}

void HitPoint::Empty()
{
	nowHp = 0;
}

bool HitPoint::IsFull()
{
	return nowHp == maxHp;
}

bool HitPoint::IsEmpty()
{
	return nowHp == 0;
}

float HitPoint::Rate()
{
	return nowHp / maxHp;
}