#pragma once
#include"NumRange.h"

class LimitPoint
{
public:
	LimitPoint();
	~LimitPoint();
	void LimitReleasing();
	void Recovery(float recovPoint );
	void Update();
private:
	NumRange point;
	//	�������
	bool isReleasing;
	void Add(float point);
};

