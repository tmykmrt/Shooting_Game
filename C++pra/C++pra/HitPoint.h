#pragma once
class HitPoint
{
public:
	HitPoint();
	HitPoint(float maxHp);
	~HitPoint();
	void Set(float maxHp);
	float GetNowHp();
	//	HP�����Z����
	void AddHp(float add);
	//	HP�����Z����
	void SubHp(float Sub);
	//	�ő�HP�����Z����
	void AddMaxHp(float add);
	void SubMaxHp(float sub);
	//	HP�𖞃^���ɂ���
	void Full();
	//	HP����ɂ���
	void Empty();
	//	HP�𖞃^����
	bool IsFull();
	//	HP���O��
	bool IsEmpty();
	//	����
	float Rate();
private:
	//	���݂�HP
	float nowHp;
	//	�ő�HP
	float maxHp;
};

