#pragma once
class Math
{
public:
	Math();
	~Math();
	//	大きいほうを返す
	template<typename T>
	static T Max(T a,T b)
	{
		if (a >= b)return a;
		else return b;
	}
	//	小さいほうを返す
	template<typename T>
	static T Min(T a, T b)
	{
		if (a <= b)return a;
		else return b;
	}
	//	範囲内に制限する
	template<typename T>
	static T Clamp(T value,T min, T max)
	{
		if (value > max) value = max;
		else if (value < min) value = min;
		return value;
	}

	////	範囲内に制限する
	//template<typename T>
	//static T Clamp(T value, T min, T max)
	//{
	//	if (value > max) value = max;
	//	else if (value < min) value = min;
	//	return value;
	//}

private:

};
