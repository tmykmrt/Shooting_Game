#pragma once
class HitPoint
{
public:
	HitPoint();
	HitPoint(float maxHp);
	~HitPoint();
	void Set(float maxHp);
	float GetNowHp();
	//	HPを加算する
	void AddHp(float add);
	//	HPを加算する
	void SubHp(float Sub);
	//	最大HPを加算する
	void AddMaxHp(float add);
	void SubMaxHp(float sub);
	//	HPを満タンにする
	void Full();
	//	HPを空にする
	void Empty();
	//	HPを満タンか
	bool IsFull();
	//	HPが０か
	bool IsEmpty();
	//	割合
	float Rate();
private:
	//	現在のHP
	float nowHp;
	//	最大HP
	float maxHp;
};

