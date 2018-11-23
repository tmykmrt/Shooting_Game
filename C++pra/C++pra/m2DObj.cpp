#pragma once
#include"stdafx.h"
#include"MyDX.h"
#include"m2DObj.h"

LPDIRECT3D9 MyDX::pD3d;
LPDIRECT3DDEVICE9 MyDX::pDevice; 
LPD3DXSPRITE m2DObj::pSprite;

m2DObj::m2DObj()
{ 
}

m2DObj::~m2DObj()
{

}

//	初期化
HRESULT m2DObj::Init()
{
	if (FAILED(D3DXCreateSprite(MyDX::Device(), &pSprite)))
	{
		MessageBox(0, "スプライトの作成に失敗しました", "", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

//	読み込み
int m2DObj::LoadTexture(TCHAR *name, LPDIRECT3DTEXTURE9 *pTexture, int x, int y)
{
	//「テクスチャオブジェクト」の作成
	if (FAILED(D3DXCreateTextureFromFileEx(MyDX::Device(), name, x, y, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT,
		0xff000000, NULL, NULL, pTexture)))
	{
		MessageBox(0, _T("テクスチャの作成に失敗しました"), _T(""), MB_OK);
		return E_FAIL;
	}
}

//	描画
void m2DObj::Draw(LPDIRECT3DTEXTURE9 *pTexture, D3DXVECTOR2 pos, RECT rect)
{
	D3DXVECTOR3 v3Center(0, 0, 0);
	D3DXVECTOR3 v3Position(pos);
	pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	pSprite->Draw(*pTexture, &rect, &v3Center, &v3Position, D3DCOLOR_ARGB(255, 255, 255, 255));
	pSprite->End();
}
//	描画
void m2DObj::DrawCenter(LPDIRECT3DTEXTURE9 *pTexture, D3DXVECTOR2 pos, RECT rect)
{
	D3DXVECTOR3 v3Center(rect.right / 2, rect.bottom / 2, 0);
	D3DXVECTOR3 v3Position(pos);
	pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	pSprite->Draw(*pTexture, &rect, &v3Center, &v3Position, D3DCOLOR_ARGB(255, 255, 255, 255));
	pSprite->End();
}

////	描画
//void m2DObj::Draw(LPDIRECT3DTEXTURE9 *pTexture, D3DXVECTOR2 pos, int x,int y,int )
//{
//	D3DXVECTOR3 v3Center(0, 0, 0);
//	D3DXVECTOR3 v3Position(pos);
//	pSprite->Begin(D3DXSPRITE_ALPHABLEND);
//	pSprite->Draw(*pTexture, &rect, &v3Center, &v3Position, D3DCOLOR_ARGB(255, 255, 255, 255));
//	pSprite->End();
//}

//	解放
void m2DObj::Release()
{
	pSprite->Release();
	Singleton::Destroy();
}
