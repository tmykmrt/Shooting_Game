#include "ShotPower.h"

ShotPower::ShotPower()
{
	Init(100,100);
}

ShotPower::ShotPower(float max, float recoveFrame)
{
	Init(max, recoveFrame);
}


ShotPower::~ShotPower()
{
}


void ShotPower::Init(float max, float recoveFrame)
{
	this->recoveFrame = recoveFrame;
	this->maxPower = nowPower = max;
}

void ShotPower::Chage()
{
	nowPower += maxPower / recoveFrame;
}


bool ShotPower::IsEnough(float usePower)
{
	return nowPower >= usePower;
}
