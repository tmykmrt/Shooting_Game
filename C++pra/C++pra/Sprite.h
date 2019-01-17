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
	void Load(TCHAR *name, int imageSizeX, int imageSizeY,int sizeX,int sizeY);
	//	描画
	void Draw();
	void DrawRatio(float ratioX,float ratioY);
	//	描画
	void DrawCenter();
	void DrawCenter(int top, int right);
	//	解放
	void Release();
private:
	//	テクスチャ
	 LPDIRECT3DTEXTURE9 pTexture;

};
