#pragma once
#include"stdafx.h"
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }

//	DirectX�Ǘ�
static class MyDX
{
public:
	MyDX();
	~MyDX();
	//	������
	HRESULT Init(HWND);
	//	�`��
	void Render();
	//	���
	void Release();
	static LPDIRECT3D9 Pd3d() { return pD3d; }
	static LPDIRECT3DDEVICE9 Device() { return pDevice; }
private:
	//	Direct3D��Direct3D�f�o�C�X
	static LPDIRECT3D9 pD3d;
	static LPDIRECT3DDEVICE9 pDevice;
};
