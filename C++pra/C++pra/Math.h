#pragma once
class Math
{
public:
	Math();
	~Math();
	//	�傫���ق���Ԃ�
	template<typename T>
	static T Max(T a,T b)
	{
		if (a >= b)return a;
		else return b;
	}
	//	�������ق���Ԃ�
	template<typename T>
	static T Min(T a, T b)
	{
		if (a <= b)return a;
		else return b;
	}
	//	�͈͓��ɐ�������
	template<typename T>
	static T Clamp(T value,T min, T max)
	{
		if (value > max) value = max;
		else if (value < min) value = min;
		return value;
	}

	////	�͈͓��ɐ�������
	//template<typename T>
	//static T Clamp(T value, T min, T max)
	//{
	//	if (value > max) value = max;
	//	else if (value < min) value = min;
	//	return value;
	//}

private:

};
