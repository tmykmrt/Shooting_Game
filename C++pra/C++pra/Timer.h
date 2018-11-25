#pragma once
class Timer
{
public:
	Timer();
	~Timer();
	//	�J�E���g�^�C���̐ݒ�
	void SetCountTime(float time);
	//	�J�E���g�t���[���̐ݒ�
	void SetCountFrame(int frame);
	//bool CheckTimeOut();
	//	�J�E���g�t���[�����o�߂�����
	bool CheckFrameOut();
	//	�v���t���[���̍X�V
	int UpdateFrame();
	//	�v���t���[�����Z�b�g
	void ResetFrame();
private:
	//	�J�E���g�^�C��
	float countTime;
	//	�J�E���g�t���[��
	int countFrame;
	//	�v���t���[��
	int nowFrame;
};

