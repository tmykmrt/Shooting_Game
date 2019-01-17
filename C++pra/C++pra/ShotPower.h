#pragma once
//	射撃に必要な力の管理
class ShotPower
{
public:
	ShotPower();
	ShotPower(float max,float recoveFrame);
	~ShotPower();
	void Init(float max, float recoveFrame);
	//	使用する力が足りているか
	bool IsEnough(float usePower);
	//	チャージ
	void Chage();
private:
	//	現在のパワー
	float nowPower;
	//	現在のパワー
	float maxPower;
	//	チャージフレーム
	float recoveFrame;
};

