#pragma once
class NumRange
{
public:
	NumRange();
	NumRange(float max);
	~NumRange();
	void Set(float now, float max, float min);
	float GetNow();
	//	加算する
	void Add(float add);
	void SetNow(float now);
	//	最大加算する
	void AddMax(float add);
	void SetMax(float nowMax);
	//	最小加算する
	void AddMin(float add);
	void SetMin(float nowMin);
	//	現在の値がそれ以上か
	bool IsOver(float value);
	//	現在の値がそれ以下か
	bool IsUnder(float value);
	//	満タンにする
	void Full();
	//	空にする
	void Empty();
	//	満タンか
	bool IsFull();
	//	最小化
	bool IsEmpty();
	//	割合
	float Rate();
private:
	//	現在
	float now;
	//	最大
	float max;
	//	最小
	float min;
};

