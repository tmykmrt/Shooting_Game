#include "Animation2D.h"
#include"Sprite.h"
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

//	�A�j���Z�b�g
void Animation2D::SetAima(int num)
{
	//	
	if (nowAnimaNum == num)return;
	nowAnimaNum = num;
	timer.ResetFrame();

}

//	�`��
void Animation2D::Render(D3DXVECTOR2 pos)
{
	//	
	sprite->pos = pos;
	UpdateAnima();
	sprite->DrawCenter(data[nowAnimaNum].animaNum,nowAnimaPage);
}

//	�A�j���X�V
void Animation2D::UpdateAnima()
{
	int frame = timer.UpdateFrame();
	nowAnimaPage = frame / data[nowAnimaNum].frame;
	nowAnimaPage = nowAnimaPage <= 0 ? 1 : nowAnimaPage;
	if (nowAnimaPage >= data[nowAnimaNum].pagesNum) timer.ResetFrame();
}




