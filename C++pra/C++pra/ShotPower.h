#pragma once
//	�ˌ��ɕK�v�ȗ͂̊Ǘ�
class ShotPower
{
public:
	ShotPower();
	ShotPower(float max,float recoveFrame);
	~ShotPower();
	void Init(float max, float recoveFrame);
	//	�g�p����͂�����Ă��邩
	bool IsEnough(float usePower);
	//	�`���[�W
	void Chage();
private:
	//	���݂̃p���[
	float nowPower;
	//	���݂̃p���[
	float maxPower;
	//	�`���[�W�t���[��
	float recoveFrame;
};

