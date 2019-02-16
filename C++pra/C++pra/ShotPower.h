#pragma once
#include"NumRange.h"

/**
* @file PlayerShotTrigger.h
* @brief 射撃に必要な力の管理
* @date 2019 1/1
*/
class ShotPower
{
public:
	ShotPower();
	ShotPower(float max,float recoveFrame);
	~ShotPower();
	void Init(float max, float recoveFrame);
	//	消費する
	void Consume(float usePow);
	//	使用する力が足りているか
	bool IsEnough(float usePower);
	//	チャージ
	void Chage();
	//	割合
	//	※一時的な
	float Rate();
	NumRange* NowPow();
private:
	NumRange pow;
	//	チャージ値
	float recovePow;
};

