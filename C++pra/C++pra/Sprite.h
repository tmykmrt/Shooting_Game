#pragma once
#include"stdafx.h"

class Sprite
{
public:
	Sprite();
	~Sprite();
	//	座標
	D3DXVECTOR2 pos;
	//	サイズ
	D3DXVECTOR2 size;
	void Load(TCHAR *name,int x,int y);
	//	描画
	void Draw();
	//	描画
	void DrawCenter();
	//	解放
	void Release();
private:
	//	テクスチャ
	 LPDIRECT3DTEXTURE9 pTexture;

};
