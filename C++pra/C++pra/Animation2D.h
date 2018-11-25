#pragma once
#include"stdafx.h"
#include"Timer.h"
class Sprite;
class Timer;

struct Animation2DData
{
	//	�A�j���ԍ�
	int animaNum;
	//	����
	int pagesNum;
	//	�\���t���[��
	int frame;
};

class Animation2D
{
public:
	Animation2D();
	Animation2D(TCHAR *name, int imageSizeX, int imageSizeY, int sizeX, int sizeY);
	~Animation2D();
	void Load(TCHAR *name, int imageSizeX, int imageSizeY, int sizeX, int sizeY);
	void SetAima(int num);
	void Render(D3DXVECTOR2 pos);
	void SetAnimaData(Animation2DData *data);
	//	�A�j���̍X�V
	void UpdateAnima();

private:
	//	��{�̈ꖇ
	Sprite *sprite;
	//	�^�C�}�[
	Timer timer;
	//	�A�j���̃f�[�^
	Animation2DData *data;
	//	���݂̃A�j��
	int nowAnimaNum;
	//	���݂̃A�j���̃y�[�W
	int nowAnimaPage;
	
};

