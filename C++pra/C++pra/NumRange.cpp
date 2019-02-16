#include "NumRange.h"
#include"Math.h"
NumRange::NumRange()
{
	max = 1;
	min = 0;
	now = 0;
}

NumRange::NumRange(float max)
{
	Set(max,max,0);
}

NumRange::~NumRange()
{

}

void NumRange::Set(float now,float max,float min)
{
	this->now = max;
	this->max = max;
}

void NumRange::Add(float add)
{
	now += add;
	now = Math::Clamp<float>(now, 0.0f, max);
}
void NumRange::SetNow(float now)
{
	now = now;
	now = Math::Clamp<float>(now, 0.0f, max);
}

void NumRange::AddMax(float add)
{
	max += add;
}

void NumRange::SetMax(float newMax)
{
	max = newMax;
	max = Math::Clamp<float>(max, min, max);
}

void NumRange::AddMin(float add)
{
	min += add;
}

void NumRange::SetMin(float newMin)
{
	min = newMin;
	min = Math::Clamp<float>(max, min, max);
}

float NumRange::GetNow()
{
	return now;
}

bool NumRange::IsOver(float value)
{
	return now > value;
}

bool NumRange::IsUnder(float value)
{
	return now < value;
}


void NumRange::Full()
{
	now = max;
}

void NumRange::Empty()
{
	now = 0;
}

bool NumRange::IsFull()
{
	return now >= max;
}

bool NumRange::IsEmpty()
{
	return now <= min;
}

float NumRange::Rate()
{
	return now / max;
}