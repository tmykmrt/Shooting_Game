#pragma once
#include"stdafx.h"

class m2DObj
{
public:
	m2DObj();
	~m2DObj();
	static HRESULT Init();
	//	�ǂݍ���
	static int LoadTexture(TCHAR *name, LPDIRECT3DTEXTURE9 *pTexture, int x, int y);
	//	�`��
	void Draw(LPDIRECT3DTEXTURE9 *pTexture, int x,int y,int , RECT rect);
	static void Draw(LPDIRECT3DTEXTURE9 *pTexture, D3DXVECTOR2 pos, RECT rect);
	static void DrawCenter(LPDIRECT3DTEXTURE9 *pTexture, D3DXVECTOR2 pos, RECT rect);
	void Release();
private:
	//	LPD3DXSPRITE
	static LPD3DXSPRITE pSprite;
};


