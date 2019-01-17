#pragma once
class HitPoint
{
public:
	HitPoint();
	HitPoint(float maxHp);
	~HitPoint();
	void Set(float maxHp);
	float GetNowHp();
	//	HP‚ğ‰ÁZ‚·‚é
	void AddHp(float add);
	//	HP‚ğ‰ÁZ‚·‚é
	void SubHp(float Sub);
	//	Å‘åHP‚ğ‰ÁZ‚·‚é
	void AddMaxHp(float add);
	void SubMaxHp(float sub);
	//	HP‚ğ–ƒ^ƒ“‚É‚·‚é
	void Full();
	//	HP‚ğ‹ó‚É‚·‚é
	void Empty();
	//	HP‚ğ–ƒ^ƒ“‚©
	bool IsFull();
	//	HP‚ª‚O‚©
	bool IsEmpty();
	//	Š„‡
	float Rate();
private:
	//	Œ»İ‚ÌHP
	float nowHp;
	//	Å‘åHP
	float maxHp;
};

