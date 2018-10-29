#include"stdafx.h"
#include"MyDX.h"

MyDX::MyDX()
{
	pD3d = NULL;
	pDevice = NULL;
}

//	�f�X�g���N�^
MyDX::~MyDX()
{
	//	���
	//m_p_d3d->Release();
	//m_p_device->Release();
}


//	���
void MyDX::Release()
{
	pD3d->Release();
	pDevice->Release();
}


//	DirectX�̏�����
HRESULT MyDX::Init(HWND hwnd)
{
	// �쐬
	if (NULL == (pD3d = Direct3DCreate9(D3D_SDK_VERSION)))
	{
		MessageBox(0, "Direct3D�̍쐬�Ɏ��s���܂���", "", MB_OK);
		return E_FAIL;
	}
	// �uDIRECT3D�f�o�C�X�v�I�u�W�F�N�g�̍쐬
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	//	��ʂ̃t�H�[�}�b�g���̊i�[
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	//	�o�b�N�o�b�t�@�̐����i�[
	d3dpp.BackBufferCount = 1;
	//	�t�����g�o�b�t�@�ƃo�b�N�o�b�t�@�̐؂�ւ���`
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	//	�X�N���[�����[�h���`�@true : �E�B���h�E�@����ȊO : �t���X�N���[��
	d3dpp.Windowed = TRUE;
	//	�[�x�X�e���V���o�b�t�@�̗L��
	d3dpp.EnableAutoDepthStencil = TRUE;
	//	�X�e���V���o�b�t�@�̃t�H�[�}�b�g�w��
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

	if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp, &pDevice)))
	{
		if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd,
			D3DCREATE_SOFTWARE_VERTEXPROCESSING,
			&d3dpp, &pDevice)))
		{
			MessageBox(0, "HAL���[�h��DIRECT3D�f�o�C�X���쐬�ł��܂���\nREF���[�h�ōĎ��s���܂�", NULL, MB_OK);
			if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hwnd,
				D3DCREATE_HARDWARE_VERTEXPROCESSING,
				&d3dpp, &pDevice)))
			{
				if (FAILED(pD3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_REF, hwnd,
					D3DCREATE_SOFTWARE_VERTEXPROCESSING,
					&d3dpp, &pDevice)))
				{
					MessageBox(0, "DIRECT3D�f�o�C�X�̍쐬�Ɏ��s���܂���", NULL, MB_OK);
					return E_FAIL;
				}
			}
		}
	}
	return S_OK;
}

void MyDX::Render()
{
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	if (SUCCEEDED(pDevice->BeginScene()))
	{
		//---------------------------------
		//	�`��
		//---------------------------------
		
		
		pDevice->EndScene();
	}
	//	�t���b�v
	pDevice->Present(NULL, NULL, NULL, NULL);
}