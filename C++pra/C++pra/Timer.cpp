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

//	�t���[���o�߂�����
bool Timer::CheckFrameOut()
{
	countFrame--;
	return countFrame <= 0;
}

//	�t���[���v��
int Timer::UpdateFrame()
{
	nowFrame += 1;
	return nowFrame;
}

//	�v���t���[���̃��Z�b�g
void Timer::ResetFrame()
{
	nowFrame = 0;
}
