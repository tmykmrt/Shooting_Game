#pragma once
#include"stdafx.h"
#include"Timer.h"
class Sprite;
class Timer;

struct Animation2DData
{
	//	アニメ番号
	int animaNum;
	//	枚数
	int pagesNum;
	//	表示フレーム
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
	//	アニメの更新
	void UpdateAnima();

private:
	//	大本の一枚
	Sprite *sprite;
	//	タイマー
	Timer timer;
	//	アニメのデータ
	Animation2DData *data;
	//	現在のアニメ
	int nowAnimaNum;
	//	現在のアニメのページ
	int nowAnimaPage;
	
};

