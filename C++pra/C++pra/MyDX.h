#pragma once
#include"stdafx.h"
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }

//	DirectX管理
static class MyDX : public Singleton<MyDX>
{
public:
	friend class Singleton<MyDX>;
	//	初期化
	HRESULT Init(HWND);
	//	描画
	void Render();
	//	解放
	void Release();
	static LPDIRECT3D9 Pd3d() { return pD3d; }
	static LPDIRECT3DDEVICE9 Device() { return pDevice; }
protected:
	MyDX();
	~MyDX();
private:
	//	Direct3DとDirect3Dデバイス
	static LPDIRECT3D9 pD3d;
	static LPDIRECT3DDEVICE9 pDevice;
};

