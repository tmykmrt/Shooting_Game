#pragma once
class NumRange
{
public:
	NumRange();
	NumRange(float max);
	~NumRange();
	void Set(float now, float max, float min);
	float GetNow();
	//	���Z����
	void Add(float add);
	void SetNow(float now);
	//	�ő���Z����
	void AddMax(float add);
	void SetMax(float nowMax);
	//	�ŏ����Z����
	void AddMin(float add);
	void SetMin(float nowMin);
	//	���݂̒l������ȏォ
	bool IsOver(float value);
	//	���݂̒l������ȉ���
	bool IsUnder(float value);
	//	���^���ɂ���
	void Full();
	//	��ɂ���
	void Empty();
	//	���^����
	bool IsFull();
	//	�ŏ���
	bool IsEmpty();
	//	����
	float Rate();
private:
	//	����
	float now;
	//	�ő�
	float max;
	//	�ŏ�
	float min;
};

