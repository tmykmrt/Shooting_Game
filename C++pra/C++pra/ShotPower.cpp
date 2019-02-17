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
	this->recovePow = max / recoveFrame;
	pow.Set(max, max, 0);
}

void ShotPower::Chage()
{
	pow.Add(recovePow);
}

void ShotPower::Consume(float usePow)
{
	pow.Add(-usePow);
}

bool ShotPower::IsEnough(float usePower)
{
	return pow.IsOver(usePower);
}

float ShotPower::Rate()
{
	return pow.Rate();
}

NumRange *ShotPower::NowPow()
{
	return &pow;
}
