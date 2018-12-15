#include "Animation2D.h"
#include"Sprite.h"

//	
Animation2D::Animation2D()
{
}

Animation2D::Animation2D(TCHAR *name, int imageSizeX, int imageSizeY, int sizeX, int sizeY)
{
	sprite = new Sprite();
	Load(name, imageSizeX, imageSizeY, sizeX, sizeY);
}

Animation2D::~Animation2D()
{
	sprite->Release();
	delete sprite;
}

void Animation2D::Load(TCHAR *name, int imageSizeX, int imageSizeY, int sizeX, int sizeY)
{
	sprite->Load(name, imageSizeX, imageSizeY, sizeX, sizeY);
}

void Animation2D::SetAnimaData(Animation2DData *data)
{
	this->data = data;
}

//	アニメセット
void Animation2D::SetAima(int num)
{
	//	
	if (nowAnimaNum == num)return;
	nowAnimaNum = num;
	timer.ResetFrame();
	nowPlayCount = 0;

}

//	描画
void Animation2D::Render(D3DXVECTOR2 pos)
{
	//	
	sprite->pos = pos;
	UpdateAnima();
	sprite->DrawCenter(data[nowAnimaNum].animaNum,nowAnimaPage);
}

//	アニメ更新
void Animation2D::UpdateAnima()
{
	int frame = timer.UpdateFrame();
	nowAnimaPage = frame / data[nowAnimaNum].frame;
	nowAnimaPage = nowAnimaPage <= 0 ? 1 : nowAnimaPage;
	//	
	if (nowAnimaPage >= data[nowAnimaNum].pagesNum)
	{
		//	ループじゃなければ繰り返す
		if(data[nowAnimaNum].loop == false)timer.ResetFrame();
		isEnd = true;
		nowPlayCount++;
	}
}

//	終了か
bool Animation2D::IsEnd()
{
	return isEnd;
}

//	次のアニメーションへ
void Animation2D::Next()
{
	//	無ければスキップ
	if (data[nowAnimaNum].animaNum < 0)return;
	//	次へ
	SetAima(data[nowAnimaNum].animaNum);
}

//	現在の再生回数
int Animation2D::NowPlayCount()
{
	return nowPlayCount;
}



