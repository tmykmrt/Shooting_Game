#pragma once
#include"stdafx.h"

class Sprite
{
public:
	Sprite();
	~Sprite();
	//	���W
	D3DXVECTOR2 pos;
	//	�T�C�Y
	D3DXVECTOR2 size;
	void Load(TCHAR *name,int x,int y);
	//	�`��
	void Draw();
	//	�`��
	void DrawCenter();
	//	���
	void Release();
private:
	//	�e�N�X�`��
	 LPDIRECT3DTEXTURE9 pTexture;

};
