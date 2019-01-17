#pragma once
class Math
{
public:
	Math();
	~Math();
	//	‘å‚«‚¢‚Ù‚¤‚ğ•Ô‚·
	template<typename T>
	static T Max(T a,T b)
	{
		if (a >= b)return a;
		else return b;
	}
	//	¬‚³‚¢‚Ù‚¤‚ğ•Ô‚·
	template<typename T>
	static T Min(T a, T b)
	{
		if (a <= b)return a;
		else return b;
	}
	//	”ÍˆÍ“à‚É§ŒÀ‚·‚é
	template<typename T>
	static T Clamp(T value,T min, T max)
	{
		if (value > max) value = max;
		else if (value < min) value = min;
		return value;
	}

private:

};
