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

//	������
HRESULT m2DObj::Init()
{
	if (FAILED(D3DXCreateSprite(MyDX::Device(), &pSprite)))
	{
		MessageBox(0, "�X�v���C�g�̍쐬�Ɏ��s���܂���", "", MB_OK);
		return E_FAIL;
	}
	return S_OK;
}

//	�ǂݍ���
int m2DObj::LoadTexture(TCHAR *name, LPDIRECT3DTEXTURE9 *pTexture, int x, int y)
{
	//�u�e�N�X�`���I�u�W�F�N�g�v�̍쐬
	if (FAILED(D3DXCreateTextureFromFileEx(MyDX::Device(), name, x, y, 0, 0, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_DEFAULT,
		0xff000000, NULL, NULL, pTexture)))
	{
		MessageBox(0, _T("�e�N�X�`���̍쐬�Ɏ��s���܂���"), _T(""), MB_OK);
		return E_FAIL;
	}
}

//	�`��
void m2DObj::Draw(LPDIRECT3DTEXTURE9 *pTexture, D3DXVECTOR2 pos, RECT rect)
{
	D3DXVECTOR3 v3Center(0, 0, 0);
	D3DXVECTOR3 v3Position(pos);
	pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	pSprite->Draw(*pTexture, &rect, &v3Center, &v3Position, D3DCOLOR_ARGB(255, 255, 255, 255));
	pSprite->End();
}
//	�`��
//���_�t�H�[�}�b�g��`
struct TEX_VERTEX
{
	float x, y, z;
	float u, v;
};
void m2DObj::DrawCenter(LPDIRECT3DTEXTURE9 *pTexture, D3DXVECTOR2 pos, RECT drowRect, D3DXVECTOR2 size)
{

	D3DXVECTOR3 v3Center(size.x / 2, size.y / 2, 0);
	D3DXVECTOR3 v3Position(pos);
	//D3DXMATRIX      matWorld, matWork;
	//D3DXMatrixIdentity(&matWorld);
	//D3DXMatrixIdentity(&matWork);
	//float rad = 3.141592f / 180.0f; // ���W�A���̏�����
	//D3DXMatrixRotationZ(&matWorld, 90*rad);
	//
	//D3DXMatrixTranslation(&matWork, pos.x, pos.y, 0.0f);
	//v3Position.x = matWork._41;
	//v3Position.y = matWork._42;
	////matWorld = matWorld * matWork;
	//pSprite->SetTransform(&matWorld);
	pSprite->Begin(D3DXSPRITE_ALPHABLEND);
	pSprite->Draw(*pTexture, &drowRect, &v3Center, &v3Position, D3DCOLOR_ARGB(255, 255, 255, 255));

	pSprite->End();
	//	���ɖ߂�
	//D3DXMatrixRotationZ(&matWorld, 0);
	//D3DXMatrixTranslation(&matWork, 0, 0, 0.0f);
	//matWorld = matWorld * matWork;
	//pSprite->SetTransform(&matWorld);
}

////	�`��
//void m2DObj::Draw(LPDIRECT3DTEXTURE9 *pTexture, D3DXVECTOR2 pos, int x,int y,int )
//{
//	D3DXVECTOR3 v3Center(0, 0, 0);
//	D3DXVECTOR3 v3Position(pos);
//	pSprite->Begin(D3DXSPRITE_ALPHABLEND);
//	pSprite->Draw(*pTexture, &rect, &v3Center, &v3Position, D3DCOLOR_ARGB(255, 255, 255, 255));
//	pSprite->End();
//}

//	���
void m2DObj::Release()
{
	pSprite->Release();
	Singleton::Destroy();
}
