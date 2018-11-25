#include "Timer.h"
Timer::Timer()
{
	nowFrame = 0;
}

Timer::~Timer()
{
}

void Timer::SetCountTime(float time)
{
	this->countTime = time;
}

void Timer::SetCountFrame(int frame)
{
	this->countFrame = frame;
}

//	フレーム経過したか
bool Timer::CheckFrameOut()
{
	countFrame--;
	return countFrame <= 0;
}

//	フレーム計測
int Timer::UpdateFrame()
{
	nowFrame += 1;
	return nowFrame;
}

//	計測フレームのリセット
void Timer::ResetFrame()
{
	nowFrame = 0;
}
